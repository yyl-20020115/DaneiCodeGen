using System.Text;

namespace DaneiCodeGen;

public class Program
{
    private const string CONST_STD_STRING_REF = "const std::string&";

    static void Main(string[] args)
    {
        using var work_reader = new StreamReader("Work.md");

        using var rtmapi_h_writer = new StreamWriter("DaneiAgoraRTMApi.h");
        using var rtmapi_callback_h_writer = new StreamWriter("DaneiAgoraRTMApiCallback.h");
        using var rtmapi_cpp_writer = new StreamWriter("DaneiAgoraRTMApi.cpp");


        string? line = null;
        var js = false;
        var dict = new Dictionary<string, (string, List<(string, List<string>)>)>();


        var enums = new Dictionary<string, List<(string, string)>>();

        enums["rtmTextMessageCategory"] = [];

        var current = "";
        while (null != (line = work_reader.ReadLine()))
        {
            line = line.Trim();
            if (line.StartsWith("##"))
                continue;
            else if (line.StartsWith("//"))
                continue;
            if (line.StartsWith("-"))
                continue;
            if (line.StartsWith("```javascript"))
            {
                js = true;
            }
            else if (line.StartsWith("```"))
            {
                js = false;
            }
            else if (js)
            {
                int p = line.IndexOf(':');
                if (p >= 0)
                {
                    var name = line[..p];

                    if (name.Length > 0 && name.StartsWith('"') && name.EndsWith('"'))
                    {
                        name = name.Trim('"');
                        line = line[(p + 1)..].Trim();
                        p = line.IndexOf("//");
                        if (p >= 0) line = line[..p].Trim();
                        if (line.EndsWith(',')) line = line[..^1].Trim();

                        var ename = name;
                        if (line.EndsWith('{'))
                        {
                            ename = line.Trim('{').Trim();
                            if (ename.EndsWith('.')) ename = ename[..^1].Trim();

                            var builder = new StringBuilder();
                            int cx = -1;
                            while ((cx = work_reader.Read()) != -1 && cx != '}') builder.Append((char)cx);
                            var enum_text = builder.ToString();
                            var evalues = ParseEnum(enum_text);
                            if (evalues != null) enums.Add(ename, evalues);
                        }

                        var vs = new List<string>();
                        p = line.IndexOf('|');
                        if (p >= 0)
                        {
                            var ps = line.Split('|');
                            foreach (var px in ps)
                            {
                                vs.Add(px.Trim());
                            }
                        }
                        else
                        {
                            line = line.TrimEnd('{').TrimEnd('.');
                            vs.Add(line);
                        }
                        //name,value
                        dict[current].Item2.Add((ename, vs));

                       
                    }
                }


            }
            else if (line.StartsWith("UserEvent"))
            {
                //UserEvent:SEND_CODE_STATUS: 'SEND_CODE_STATUS'
                int p = line.IndexOf(':');
                if (p > 0)
                {
                    int e = line.IndexOf(':', p + 1);
                    if (e > 0)
                    {
                        var cat_name = line.Substring(p + 1, e - p - 1);
                        int k = line.IndexOf('\'', e);
                        if (k > 0)
                        {
                            int f = line.IndexOf('\'', k + 1);

                            var enum_value = line.Substring(k + 1, f - k - 1);

                            enums["rtmTextMessageCategory"].Add((cat_name, enum_value));

                            if (!string.IsNullOrEmpty(cat_name) && !string.IsNullOrEmpty(enum_value))
                            {
                                dict[current = cat_name] = (enum_value, new());
                            }
                        }

                    }
                }
            }
        }

        foreach (var kvp in dict)
        {
            Console.WriteLine(kvp.Key + ":" + kvp.Value.Item1);
            foreach (var kvp2 in kvp.Value.Item2)
            {
                Console.WriteLine("\t" + kvp2.Item1 + " -> " + string.Join(",", kvp2.Item2));
            }
            Console.WriteLine();
        }


        rtmapi_h_writer.WriteLine("""
            enum class rtmTextMessageCategory :int
            {
            	NONE = -1,
            """);

        int i = -2;

        foreach (var kvp in dict)
        {
            rtmapi_h_writer.WriteLine($"\t{kvp.Key} = {GetValue(kvp.Value.Item1, i--)},");
        }
        rtmapi_h_writer.WriteLine("};\r\n");

        foreach (var e in enums)
        {
            rtmapi_h_writer.WriteLine($"enum class {e.Key} :int");
            rtmapi_h_writer.WriteLine("{");
            i = -1;
            foreach (var it in e.Value)
            {
                rtmapi_h_writer.WriteLine($"\t{it.Item1} = {GetEnumValue(it.Item2,i--)},");
            }
            rtmapi_h_writer.WriteLine("};");
        }


        rtmapi_callback_h_writer.WriteLine("class DaneiAgoraRTMApiCallback\r\n{\r\npublic:");

        rtmapi_h_writer.WriteLine("class DaneiAgoraRTMApi : agora::rtm::IRtmServiceEventHandler, agora::rtm::IChannelEventHandler\r\n{\r\npublic:");
        //	cppcoro::task<int> UploadLog(const std::string& peerId, int targetUid);
        foreach (var kvp in dict)
        {
            var fname = kvp.Key;
            rtmapi_h_writer.Write($"\tcppcoro::task<int> {GetName(fname)}(const std::string& peerId");
            rtmapi_callback_h_writer.Write($"\tvirtual void On{GetName(fname)}(const std::string& peerId");
            if (kvp.Value.Item2.Count > 0)
            {
                rtmapi_h_writer.Write(", ");
                rtmapi_callback_h_writer.Write(", ");
                var first = true;
                foreach (var kvp2 in kvp.Value.Item2)
                {
                    if (kvp2.Item1 == "code")
                        continue;
                    //Parameters
                    if (!first)
                    {
                        rtmapi_h_writer.Write(", ");
                        rtmapi_callback_h_writer.Write(", ");
                    }
                    rtmapi_h_writer.Write($"{GetType(kvp2.Item1, kvp2.Item2, enums)} {kvp2.Item1.TrimEnd('?').ToLower()}");
                    rtmapi_callback_h_writer.Write($"{GetType(kvp2.Item1, kvp2.Item2, enums)} {kvp2.Item1.TrimEnd('?').ToLower()}");
                    first = false;
                }
            }
            rtmapi_callback_h_writer.WriteLine(") = 0;");
            rtmapi_h_writer.WriteLine(");");
        }

        foreach (var e in enums)
        {
            rtmapi_h_writer.WriteLine($"\tstatic std::string ToString({e.Key} val);");
            rtmapi_cpp_writer.WriteLine($"std::string DaneiAgoraRTMApi::ToString({e.Key} val)");
            rtmapi_cpp_writer.WriteLine("{");
            rtmapi_cpp_writer.WriteLine("\tswitch(val)");
            rtmapi_cpp_writer.WriteLine("\t{");
            foreach(var p in e.Value)
            {
                rtmapi_cpp_writer.WriteLine($"\t\tcase {e.Key}::{p.Item1}:");
                rtmapi_cpp_writer.WriteLine($"\t\t\treturn \"{p.Item1}\";");
            }

            rtmapi_cpp_writer.WriteLine("\t\tdefault:");
            rtmapi_cpp_writer.WriteLine("\t\t\treturn \"\";");
            rtmapi_cpp_writer.WriteLine("\t}");
            rtmapi_cpp_writer.WriteLine("}");

        }

        foreach (var e in enums)
        {
            rtmapi_h_writer.WriteLine($"\tstatic {e.Key} {e.Key}_FromString(const std::string& text);");

            rtmapi_cpp_writer.WriteLine($"{e.Key} {e.Key}_FromString(const std::string& text)");
            rtmapi_cpp_writer.WriteLine("{");
            foreach (var p in e.Value)
            {
                rtmapi_cpp_writer.WriteLine($"\tif (text == \"{p.Item1}\")");
                rtmapi_cpp_writer.WriteLine($"\t\treturn {e.Key}::{p.Item1};");
            }

            rtmapi_cpp_writer.WriteLine("\treturn \"\";");
            rtmapi_cpp_writer.WriteLine("}");


        }


        rtmapi_h_writer.WriteLine("};\r\n");
        rtmapi_callback_h_writer.WriteLine("}\r\n");


        foreach (var kvp in dict)
        {
            rtmapi_cpp_writer.Write($"cppcoro::task<int> DaneiAgoraRTMApi::{GetName(kvp.Key)}(const std::string& peerId");

            if (kvp.Value.Item2.Count > 0)
            {
                rtmapi_cpp_writer.Write(", ");
                var first = true;
                foreach (var kvp2 in kvp.Value.Item2)
                {
                    if (kvp2.Item1 == "code")
                        continue;
                    if (!first)
                    {
                        rtmapi_cpp_writer.Write(", ");
                    }
                    //Parameters
                    rtmapi_cpp_writer.Write($"{GetType(kvp2.Item1, kvp2.Item2, enums)} {kvp2.Item1.TrimEnd('?').ToLower()}");
                    first = false;
                }
            }



            rtmapi_cpp_writer.WriteLine(")\r\n{");

            rtmapi_cpp_writer.WriteLine("\tJson::Value jsonRoot;");
            rtmapi_cpp_writer.WriteLine("\tjsonRoot[\"peerId\"] = Json::Value(peerId);");
            rtmapi_cpp_writer.WriteLine($"\tjsonRoot[\"code\"] = Json::Value(ToString(rtmTextMessageCategory::{kvp.Key}));");

            if (kvp.Value.Item2.Count > 0)
            {
                foreach (var kvp2 in kvp.Value.Item2)
                {
                    if (kvp2.Item1 == "code")
                        continue;
                    
                    //Parameters
                    rtmapi_cpp_writer.WriteLine($"\tjsonRoot[\"{(kvp2.Item1)}\"] = Json::Value({Encap(kvp2.Item1,enums)});");
                }
            }
            rtmapi_cpp_writer.WriteLine("""
            	auto jrs = jsonRoot.toStyledString();
            	int r = 0;
            	IMessage* message = this->AgoraRTMService->createMessage();
            	if (message != nullptr) {
            		message->setText(jsonRoot.toStyledString().c_str());
            		SendMessageOptions options{};
            		TokenCompletionSource tcs;
            		InsertIntoResultMap(message->getMessageId(), &tcs);
            		r = this->Channel->sendMessage(message, options);
            		message->release();
            		co_await tcs.Event;
            		co_return tcs.Result;
            	}
            	co_return -1;
            }
            """);
        }

        var message_received_header = """
            void DaneiAgoraRTMApi::onMessageReceived(const char* userId, const IMessage* message)
            {
            	if (message != nullptr) {
            		Json::Reader reader;
            		Json::Value jsonRoot;
            		if (reader.parse(message->getText(), jsonRoot) && !jsonRoot.empty()) {
            			Json::Value code = jsonRoot["code"];
            			if (!code.empty()) {
            				switch (rtmTextMessageCategory_FromString(code.asString())) {
            """;

        var message_received_tail="""
            				default:
            					PLOGE << "Unknow RTM message: " << message->getText();
            					break;
            				}
            			}
            		}

            		PLOGI << "RTM message: " << message->getText();
            	}
            }
            
            """;

        /*
         * 			Json::Value deviceType = jsonRoot["deviceType"];
					Json::Value userid = jsonRoot["userId"];
					Json::Value tuid = jsonRoot["targetUserId"];
					Json::Value peerid = jsonRoot["peerId"];

					this->EventCallback->OnSendUserLoginInfo(
						peerid.isString()?peerid.asString():"",
						GetDeviceTypeFromText(deviceType.isString() ? deviceType.asString() : ""),
						userid.isInt() ? userid.asInt() : -1,
						tuid.isInt() ? tuid.asInt() : -1
					);
         */
        rtmapi_cpp_writer.WriteLine(message_received_header);
        foreach (var kvp in dict)
        {
            rtmapi_cpp_writer.WriteLine($"\t\t\t\tcase rtmTextMessageCategory::{kvp.Key}:");
            rtmapi_cpp_writer.WriteLine("\t\t\t\t{");
            foreach (var kvp2 in kvp.Value.Item2)
            {
                if (kvp2.Item1 == "code")
                    continue;
                var ie = enums.ContainsKey(kvp2.Item1);
                //Parameters
                if (ie)
                {
                    rtmapi_cpp_writer.WriteLine($"\t\t\t\t\tJson::Value {kvp2.Item1} = {kvp2.Item1}_FromString(jsonRoot[\"{kvp2.Item1}\"]);");
                }
                else
                {
                    rtmapi_cpp_writer.WriteLine($"\t\t\t\t\tJson::Value {kvp2.Item1} = jsonRoot[\"{kvp2.Item1}\"];");
                }

            }
            rtmapi_cpp_writer.WriteLine($"\t\t\t\t\tthis->On{GetName(kvp.Key)}(");
            for(int t = 0;t<kvp.Value.Item2.Count;t++)
            {
                var item = kvp.Value.Item2[t];
                if (item.Item1 == "code")
                    continue;
                rtmapi_cpp_writer.Write($"\t\t\t\t\t\t{item.Item1}");
                if (t < kvp.Value.Item2.Count - 1)
                {
                    rtmapi_cpp_writer.WriteLine(",");
                }
                else
                {
                    rtmapi_cpp_writer.WriteLine();
                }
            }
            rtmapi_cpp_writer.WriteLine("\t\t\t\t\t);");
            rtmapi_cpp_writer.WriteLine("\t\t\t\t}");
        }
        rtmapi_cpp_writer.WriteLine(message_received_tail);

    }
    public static string Encap(string val,Dictionary<string,List<(string,string )>> enums)
    {
        var ie = enums.ContainsKey(val);
        val = val.TrimEnd('?').ToLower();
        return ie ? $"ToString({val})" : val;
    }

    public static string GetEnumValue(string v, int i)
        => v.StartsWith('\'') && v.EndsWith('\'') || v.StartsWith('\"') && v.EndsWith('\"')
            ? i.ToString() : v;
    public static List<(string, string)> ParseEnum(string enum_text)
    {
        var results = new List<(string, string)>();
        var builder = new StringBuilder();
        var incomment = false;
        for (int i = 0; i < enum_text.Length - 1; i++)
        {
            char c = enum_text[i + 0];
            char n = enum_text[i + 1];
            if (c == '/' && n == '*')
            {
                incomment = true;
                i++;
                continue;
            }
            else if (c == '*' && n == '/')
            {
                incomment = false;
                i++;
                continue;
            }
            if (!incomment)
            {
                builder.Append(c);
            }
        }
        enum_text = builder.ToString();
        if (!string.IsNullOrEmpty(enum_text))
        {
            using var sr = new StringReader(enum_text);
            string? line = null;
            while (null != (line = sr.ReadLine()))
            {
                line = line.Trim();
                int p = line.IndexOf("//");
                if (p >= 0) line = line[..p].Trim().TrimEnd(',').Trim();

                if (line.Length == 0) continue;
                line = line.TrimEnd(',');
                var sps = line.Split('=');
                for (int i = 0; i < sps.Length; i++)
                {
                    sps[i] = sps[i].Trim();
                }
                if (sps.Length == 2)
                {
                    var name = sps[0];
                    var value = sps[1];
                    results.Add((name.Trim('\''), value));
                }
                else if (sps.Length == 1)
                {
                    var value = sps[0];
                    var name = value.Trim('\'').ToUpper();
                    results.Add((name, value));

                }
            }
        }

        return results;
    }
    public static string GetValue(string v, int i) => IsNumber(v) ? v : i.ToString();

    public static bool IsNumber(string s) => s.All(char.IsDigit);

    public static string GetType(string name, List<string> values, Dictionary<string, List<(string, string)>> dict)
    {
        if (values.Count == 1)
        {
            switch (values[0])
            {
                case "teamId":
                case "rtcUid":
                case "targetUserId":
                case "UserInfoState.userId":
                    return "int";
                case "text":
                case "done":
                    return CONST_STD_STRING_REF;
                case "flag":
                    return "bool";
            }
            if (values[0].EndsWith('{'))
                return values[0].Trim('{');
            if (name == "sender")
                return "int";
            if (values[0] == "" || values[0].ToLower().Contains("name"))
                return CONST_STD_STRING_REF;
            if (name == "targetUserId"/* && values[0] == "\"all\""*/)
                return "int"; //固定写法 targetUserId 此时应该是-1

            return dict.ContainsKey(name) ? name : CONST_STD_STRING_REF;
        }
        else if (values.Count == 2)
        {
            if (values[0] == "0" && values[1] == "1"
                || values[0] == "1" && values[1] == "0"
                || values[0].Equals("true", StringComparison.CurrentCultureIgnoreCase) && values[1].Equals("false", StringComparison.CurrentCultureIgnoreCase)
                || values[0].Equals("false", StringComparison.OrdinalIgnoreCase) && values[1].Equals("true", StringComparison.CurrentCultureIgnoreCase))
                return "bool";

        }
        return values.All(v => (v.StartsWith('"') && v.EndsWith('\"')) || (v.StartsWith('\'') && v.EndsWith('\'')))
            ? CONST_STD_STRING_REF
            : "???";
    }

    public static string GetName(string name)
    {
        var builder = new StringBuilder();
        var upper = true;
        foreach (var c in name)
        {
            if (c == '_')
            {
                upper = true;
                continue;
            }
            if (upper)
            {
                builder.Append(char.ToUpper(c));
                upper = false;
            }
            else
            {
                builder.Append(char.ToLower(c));
            }
        }
        return builder.ToString().TrimEnd('.').TrimEnd('?');
    }
}
