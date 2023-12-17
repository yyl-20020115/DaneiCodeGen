std::string DaneiAgoraRTMApi::ToString(rtmTextMessageCategory val)
{
	switch(val)
	{
		case rtmTextMessageCategory::SEND_CODE_STATUS:
			return "SEND_CODE_STATUS";
		case rtmTextMessageCategory::IS_AERO_GLASS_ENABLED:
			return "IS_AERO_GLASS_ENABLED";
		case rtmTextMessageCategory::FIXED_STUDENT_WINDOW:
			return "FIXED_STUDENT_WINDOW";
		case rtmTextMessageCategory::CONTROL_SCREEN:
			return "CONTROL_SCREEN";
		case rtmTextMessageCategory::NICKNAME_CHANGE:
			return "NICKNAME_CHANGE";
		case rtmTextMessageCategory::HWWHITE_BOARD:
			return "HWWHITE_BOARD";
		case rtmTextMessageCategory::END_CLASS:
			return "END_CLASS";
		case rtmTextMessageCategory::MUTE_SPEAK:
			return "MUTE_SPEAK";
		case rtmTextMessageCategory::LOCK_CLASS:
			return "LOCK_CLASS";
		case rtmTextMessageCategory::DISTRIBUTE_QUESTIONS:
			return "DISTRIBUTE_QUESTIONS";
		case rtmTextMessageCategory::SUBMIT_QUETIONS:
			return "SUBMIT_QUETIONS";
		case rtmTextMessageCategory::EXAM_END:
			return "EXAM_END";
		case rtmTextMessageCategory::STUDENT_LOOK_QUESTIONS:
			return "STUDENT_LOOK_QUESTIONS";
		case rtmTextMessageCategory::TEACHER_SEND_AWARD:
			return "TEACHER_SEND_AWARD";
		case rtmTextMessageCategory::VIDEO_MIRROR_ON:
			return "VIDEO_MIRROR_ON";
		case rtmTextMessageCategory::DEVICE_CHECK:
			return "DEVICE_CHECK";
		case rtmTextMessageCategory::DRIVEAWAY:
			return "DRIVEAWAY";
		case rtmTextMessageCategory::UPLOAD_LOG:
			return "UPLOAD_LOG";
		default:
			return "";
	}
}
std::string DaneiAgoraRTMApi::ToString(CONTROL_STATUS val)
{
	switch(val)
	{
		case CONTROL_STATUS::NO_CONTROL_RECORD:
			return "NO_CONTROL_RECORD";
		case CONTROL_STATUS::CONTROL_READY:
			return "CONTROL_READY";
		case CONTROL_STATUS::CONTROL_ING:
			return "CONTROL_ING";
		case CONTROL_STATUS::CONTROL_AGREE:
			return "CONTROL_AGREE";
		case CONTROL_STATUS::CONTROL_END:
			return "CONTROL_END";
		case CONTROL_STATUS::CONTROL_ASK:
			return "CONTROL_ASK";
		case CONTROL_STATUS::CONTROL_REFUED:
			return "CONTROL_REFUED";
		case CONTROL_STATUS::CONTROL_ERROR:
			return "CONTROL_ERROR";
		case CONTROL_STATUS::CONTROL_CANCEL:
			return "CONTROL_CANCEL";
		case CONTROL_STATUS::STOP_CONTROL_WINDOW:
			return "STOP_CONTROL_WINDOW";
		default:
			return "";
	}
}
std::string DaneiAgoraRTMApi::ToString(WHITE_BOARD_MSG_TYPES val)
{
	switch(val)
	{
		case WHITE_BOARD_MSG_TYPES::WB_CREACT:
			return "WB_CREACT";
		case WHITE_BOARD_MSG_TYPES::WB_SAVESHAPE:
			return "WB_SAVESHAPE";
		case WHITE_BOARD_MSG_TYPES::WB_REDO:
			return "WB_REDO";
		case WHITE_BOARD_MSG_TYPES::WB_UNDO:
			return "WB_UNDO";
		case WHITE_BOARD_MSG_TYPES::WB_CLEAR:
			return "WB_CLEAR";
		case WHITE_BOARD_MSG_TYPES::WB_TEARDOWN:
			return "WB_TEARDOWN";
		default:
			return "";
	}
}
std::string DaneiAgoraRTMApi::ToString(LOCK_STATUS val)
{
	switch(val)
	{
		case LOCK_STATUS::LOCK:
			return "LOCK";
		case LOCK_STATUS::UNLOCK:
			return "UNLOCK";
		default:
			return "";
	}
}
std::string DaneiAgoraRTMApi::ToString(questionStatusType val)
{
	switch(val)
	{
		case questionStatusType::NOPUSH:
			return "NOPUSH";
		case questionStatusType::PUSHING:
			return "PUSHING";
		case questionStatusType::PUSHED:
			return "PUSHED";
		case questionStatusType::add:
			return "add";
		default:
			return "";
	}
}
std::string DaneiAgoraRTMApi::ToString(MESSAGE_DATA val)
{
	switch(val)
	{
		case MESSAGE_DATA::"USERID": RTCUID:
			return ""USERID": RTCUID";
		case MESSAGE_DATA::"TYPE": 1 | 0:
			return ""TYPE": 1 | 0";
		default:
			return "";
	}
}
std::string DaneiAgoraRTMApi::ToString(DEVICE_ASK_TYPE val)
{
	switch(val)
	{
		case DEVICE_ASK_TYPE::ASK:
			return "ASK";
		case DEVICE_ASK_TYPE::SUPPORT:
			return "SUPPORT";
		case DEVICE_ASK_TYPE::NO_SUPPORT:
			return "NO_SUPPORT";
		case DEVICE_ASK_TYPE::NO_SUPPORT_ELECTRON:
			return "NO_SUPPORT_ELECTRON";
		default:
			return "";
	}
}
rtmTextMessageCategory rtmTextMessageCategory_FromString(const std::string& text)
{
	if (text == "SEND_CODE_STATUS")
		return rtmTextMessageCategory::SEND_CODE_STATUS;
	if (text == "IS_AERO_GLASS_ENABLED")
		return rtmTextMessageCategory::IS_AERO_GLASS_ENABLED;
	if (text == "FIXED_STUDENT_WINDOW")
		return rtmTextMessageCategory::FIXED_STUDENT_WINDOW;
	if (text == "CONTROL_SCREEN")
		return rtmTextMessageCategory::CONTROL_SCREEN;
	if (text == "NICKNAME_CHANGE")
		return rtmTextMessageCategory::NICKNAME_CHANGE;
	if (text == "HWWHITE_BOARD")
		return rtmTextMessageCategory::HWWHITE_BOARD;
	if (text == "END_CLASS")
		return rtmTextMessageCategory::END_CLASS;
	if (text == "MUTE_SPEAK")
		return rtmTextMessageCategory::MUTE_SPEAK;
	if (text == "LOCK_CLASS")
		return rtmTextMessageCategory::LOCK_CLASS;
	if (text == "DISTRIBUTE_QUESTIONS")
		return rtmTextMessageCategory::DISTRIBUTE_QUESTIONS;
	if (text == "SUBMIT_QUETIONS")
		return rtmTextMessageCategory::SUBMIT_QUETIONS;
	if (text == "EXAM_END")
		return rtmTextMessageCategory::EXAM_END;
	if (text == "STUDENT_LOOK_QUESTIONS")
		return rtmTextMessageCategory::STUDENT_LOOK_QUESTIONS;
	if (text == "TEACHER_SEND_AWARD")
		return rtmTextMessageCategory::TEACHER_SEND_AWARD;
	if (text == "VIDEO_MIRROR_ON")
		return rtmTextMessageCategory::VIDEO_MIRROR_ON;
	if (text == "DEVICE_CHECK")
		return rtmTextMessageCategory::DEVICE_CHECK;
	if (text == "DRIVEAWAY")
		return rtmTextMessageCategory::DRIVEAWAY;
	if (text == "UPLOAD_LOG")
		return rtmTextMessageCategory::UPLOAD_LOG;
	return "";
}
CONTROL_STATUS CONTROL_STATUS_FromString(const std::string& text)
{
	if (text == "NO_CONTROL_RECORD")
		return CONTROL_STATUS::NO_CONTROL_RECORD;
	if (text == "CONTROL_READY")
		return CONTROL_STATUS::CONTROL_READY;
	if (text == "CONTROL_ING")
		return CONTROL_STATUS::CONTROL_ING;
	if (text == "CONTROL_AGREE")
		return CONTROL_STATUS::CONTROL_AGREE;
	if (text == "CONTROL_END")
		return CONTROL_STATUS::CONTROL_END;
	if (text == "CONTROL_ASK")
		return CONTROL_STATUS::CONTROL_ASK;
	if (text == "CONTROL_REFUED")
		return CONTROL_STATUS::CONTROL_REFUED;
	if (text == "CONTROL_ERROR")
		return CONTROL_STATUS::CONTROL_ERROR;
	if (text == "CONTROL_CANCEL")
		return CONTROL_STATUS::CONTROL_CANCEL;
	if (text == "STOP_CONTROL_WINDOW")
		return CONTROL_STATUS::STOP_CONTROL_WINDOW;
	return "";
}
WHITE_BOARD_MSG_TYPES WHITE_BOARD_MSG_TYPES_FromString(const std::string& text)
{
	if (text == "WB_CREACT")
		return WHITE_BOARD_MSG_TYPES::WB_CREACT;
	if (text == "WB_SAVESHAPE")
		return WHITE_BOARD_MSG_TYPES::WB_SAVESHAPE;
	if (text == "WB_REDO")
		return WHITE_BOARD_MSG_TYPES::WB_REDO;
	if (text == "WB_UNDO")
		return WHITE_BOARD_MSG_TYPES::WB_UNDO;
	if (text == "WB_CLEAR")
		return WHITE_BOARD_MSG_TYPES::WB_CLEAR;
	if (text == "WB_TEARDOWN")
		return WHITE_BOARD_MSG_TYPES::WB_TEARDOWN;
	return "";
}
LOCK_STATUS LOCK_STATUS_FromString(const std::string& text)
{
	if (text == "LOCK")
		return LOCK_STATUS::LOCK;
	if (text == "UNLOCK")
		return LOCK_STATUS::UNLOCK;
	return "";
}
questionStatusType questionStatusType_FromString(const std::string& text)
{
	if (text == "NOPUSH")
		return questionStatusType::NOPUSH;
	if (text == "PUSHING")
		return questionStatusType::PUSHING;
	if (text == "PUSHED")
		return questionStatusType::PUSHED;
	if (text == "add")
		return questionStatusType::add;
	return "";
}
MESSAGE_DATA MESSAGE_DATA_FromString(const std::string& text)
{
	if (text == ""USERID": RTCUID")
		return MESSAGE_DATA::"USERID": RTCUID;
	if (text == ""TYPE": 1 | 0")
		return MESSAGE_DATA::"TYPE": 1 | 0;
	return "";
}
DEVICE_ASK_TYPE DEVICE_ASK_TYPE_FromString(const std::string& text)
{
	if (text == "ASK")
		return DEVICE_ASK_TYPE::ASK;
	if (text == "SUPPORT")
		return DEVICE_ASK_TYPE::SUPPORT;
	if (text == "NO_SUPPORT")
		return DEVICE_ASK_TYPE::NO_SUPPORT;
	if (text == "NO_SUPPORT_ELECTRON")
		return DEVICE_ASK_TYPE::NO_SUPPORT_ELECTRON;
	return "";
}
cppcoro::task<int> DaneiAgoraRTMApi::SendCodeStatus(const std::string& peerId, const std::string& type, bool status, int sender)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::SEND_CODE_STATUS));
	jsonRoot["type"] = Json::Value(type);
	jsonRoot["status"] = Json::Value(status);
	jsonRoot["sender"] = Json::Value(sender);
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
cppcoro::task<int> DaneiAgoraRTMApi::IsAeroGlassEnabled(const std::string& peerId, bool enable, int sender)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::IS_AERO_GLASS_ENABLED));
	jsonRoot["enable"] = Json::Value(enable);
	jsonRoot["sender"] = Json::Value(sender);
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
cppcoro::task<int> DaneiAgoraRTMApi::FixedStudentWindow(const std::string& peerId, bool fixed)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::FIXED_STUDENT_WINDOW));
	jsonRoot["fixed"] = Json::Value(fixed);
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
cppcoro::task<int> DaneiAgoraRTMApi::ControlScreen(const std::string& peerId, int targetuserid, CONTROL_STATUS control_status, const std::string& statusname, const std::string& server_address, const std::string& server_session, int sender)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::CONTROL_SCREEN));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
	jsonRoot["CONTROL_STATUS"] = Json::Value(ToString(control_status));
	jsonRoot["statusName?"] = Json::Value(statusname);
	jsonRoot["server_address"] = Json::Value(server_address);
	jsonRoot["server_session"] = Json::Value(server_session);
	jsonRoot["sender"] = Json::Value(sender);
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
cppcoro::task<int> DaneiAgoraRTMApi::NicknameChange(const std::string& peerId, int targetuserid, const std::string& nickname)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::NICKNAME_CHANGE));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
	jsonRoot["nickName"] = Json::Value(nickname);
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
cppcoro::task<int> DaneiAgoraRTMApi::HwwhiteBoard(const std::string& peerId, int targetuserid, WHITE_BOARD_MSG_TYPES white_board_msg_types, const std::string& param)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::HWWHITE_BOARD));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
	jsonRoot["WHITE_BOARD_MSG_TYPES"] = Json::Value(ToString(white_board_msg_types));
	jsonRoot["param"] = Json::Value(param);
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
cppcoro::task<int> DaneiAgoraRTMApi::EndClass(const std::string& peerId, int targetuserid)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::END_CLASS));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
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
cppcoro::task<int> DaneiAgoraRTMApi::MuteSpeak(const std::string& peerId, const std::string& scene, int to, const std::string& tip)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::MUTE_SPEAK));
	jsonRoot["scene"] = Json::Value(scene);
	jsonRoot["to"] = Json::Value(to);
	jsonRoot["tip"] = Json::Value(tip);
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
cppcoro::task<int> DaneiAgoraRTMApi::LockClass(const std::string& peerId, LOCK_STATUS lock_status)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::LOCK_CLASS));
	jsonRoot["LOCK_STATUS"] = Json::Value(ToString(lock_status));
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
cppcoro::task<int> DaneiAgoraRTMApi::DistributeQuestions(const std::string& peerId, questionStatusType questionstatustype)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::DISTRIBUTE_QUESTIONS));
	jsonRoot["questionStatusType"] = Json::Value(ToString(questionstatustype));
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
cppcoro::task<int> DaneiAgoraRTMApi::SubmitQuetions(const std::string& peerId, int targetuserid)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::SUBMIT_QUETIONS));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
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
cppcoro::task<int> DaneiAgoraRTMApi::ExamEnd(const std::string& peerId, int targetuserid)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::EXAM_END));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
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
cppcoro::task<int> DaneiAgoraRTMApi::StudentLookQuestions(const std::string& peerId, const std::string& type, bool show)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::STUDENT_LOOK_QUESTIONS));
	jsonRoot["type"] = Json::Value(type);
	jsonRoot["show"] = Json::Value(show);
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
cppcoro::task<int> DaneiAgoraRTMApi::TeacherSendAward(const std::string& peerId, int targetuserid, const std::string& messagedata)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::TEACHER_SEND_AWARD));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
	jsonRoot["messageData"] = Json::Value(messagedata);
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
cppcoro::task<int> DaneiAgoraRTMApi::VideoMirrorOn(const std::string& peerId, int targetuserid, MESSAGE_DATA message_data)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::VIDEO_MIRROR_ON));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
	jsonRoot["MESSAGE_DATA"] = Json::Value(ToString(message_data));
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
cppcoro::task<int> DaneiAgoraRTMApi::DeviceCheck(const std::string& peerId, int targetuserid, DEVICE_ASK_TYPE device_ask_type, int sender, const std::string& senderscreen)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::DEVICE_CHECK));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
	jsonRoot["DEVICE_ASK_TYPE"] = Json::Value(ToString(device_ask_type));
	jsonRoot["sender"] = Json::Value(sender);
	jsonRoot["senderScreen"] = Json::Value(senderscreen);
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
cppcoro::task<int> DaneiAgoraRTMApi::Driveaway(const std::string& peerId, int targetuserid)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::DRIVEAWAY));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
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
cppcoro::task<int> DaneiAgoraRTMApi::UploadLog(const std::string& peerId, int targetuserid)
{
	Json::Value jsonRoot;
	jsonRoot["peerId"] = Json::Value(peerId);
	jsonRoot["code"] = Json::Value(ToString(rtmTextMessageCategory::UPLOAD_LOG));
	jsonRoot["targetUserId"] = Json::Value(targetuserid);
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
void DaneiAgoraRTMApi::onMessageReceived(const char* userId, const IMessage* message)
{
	if (message != nullptr) {
		Json::Reader reader;
		Json::Value jsonRoot;
		if (reader.parse(message->getText(), jsonRoot) && !jsonRoot.empty()) {
			Json::Value code = jsonRoot["code"];
			if (!code.empty()) {
				switch (rtmTextMessageCategory_FromString(code.asString())) {
				case rtmTextMessageCategory::SEND_CODE_STATUS:
				{
					Json::Value type = jsonRoot["type"];
					Json::Value status = jsonRoot["status"];
					Json::Value sender = jsonRoot["sender"];
					this->OnSendCodeStatus(
						type,
						status,
						sender
					);
				}
				case rtmTextMessageCategory::IS_AERO_GLASS_ENABLED:
				{
					Json::Value enable = jsonRoot["enable"];
					Json::Value sender = jsonRoot["sender"];
					this->OnIsAeroGlassEnabled(
						enable,
						sender
					);
				}
				case rtmTextMessageCategory::FIXED_STUDENT_WINDOW:
				{
					Json::Value fixed = jsonRoot["fixed"];
					this->OnFixedStudentWindow(
						fixed
					);
				}
				case rtmTextMessageCategory::CONTROL_SCREEN:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					Json::Value CONTROL_STATUS = CONTROL_STATUS_FromString(jsonRoot["CONTROL_STATUS"]);
					Json::Value statusName? = jsonRoot["statusName?"];
					Json::Value server_address = jsonRoot["server_address"];
					Json::Value server_session = jsonRoot["server_session"];
					Json::Value sender = jsonRoot["sender"];
					this->OnControlScreen(
						targetUserId,
						CONTROL_STATUS,
						statusName?,
						server_address,
						server_session,
						sender
					);
				}
				case rtmTextMessageCategory::NICKNAME_CHANGE:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					Json::Value nickName = jsonRoot["nickName"];
					this->OnNicknameChange(
						targetUserId,
						nickName
					);
				}
				case rtmTextMessageCategory::HWWHITE_BOARD:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					Json::Value WHITE_BOARD_MSG_TYPES = WHITE_BOARD_MSG_TYPES_FromString(jsonRoot["WHITE_BOARD_MSG_TYPES"]);
					Json::Value param = jsonRoot["param"];
					this->OnHwwhiteBoard(
						targetUserId,
						WHITE_BOARD_MSG_TYPES,
						param
					);
				}
				case rtmTextMessageCategory::END_CLASS:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					this->OnEndClass(
						targetUserId
					);
				}
				case rtmTextMessageCategory::MUTE_SPEAK:
				{
					Json::Value scene = jsonRoot["scene"];
					Json::Value to = jsonRoot["to"];
					Json::Value tip = jsonRoot["tip"];
					this->OnMuteSpeak(
						scene,
						to,
						tip
					);
				}
				case rtmTextMessageCategory::LOCK_CLASS:
				{
					Json::Value LOCK_STATUS = LOCK_STATUS_FromString(jsonRoot["LOCK_STATUS"]);
					this->OnLockClass(
						LOCK_STATUS
					);
				}
				case rtmTextMessageCategory::DISTRIBUTE_QUESTIONS:
				{
					Json::Value questionStatusType = questionStatusType_FromString(jsonRoot["questionStatusType"]);
					this->OnDistributeQuestions(
						questionStatusType
					);
				}
				case rtmTextMessageCategory::SUBMIT_QUETIONS:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					this->OnSubmitQuetions(
						targetUserId
					);
				}
				case rtmTextMessageCategory::EXAM_END:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					this->OnExamEnd(
						targetUserId
					);
				}
				case rtmTextMessageCategory::STUDENT_LOOK_QUESTIONS:
				{
					Json::Value type = jsonRoot["type"];
					Json::Value show = jsonRoot["show"];
					this->OnStudentLookQuestions(
						type,
						show
					);
				}
				case rtmTextMessageCategory::TEACHER_SEND_AWARD:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					Json::Value messageData = jsonRoot["messageData"];
					this->OnTeacherSendAward(
						targetUserId,
						messageData
					);
				}
				case rtmTextMessageCategory::VIDEO_MIRROR_ON:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					Json::Value MESSAGE_DATA = MESSAGE_DATA_FromString(jsonRoot["MESSAGE_DATA"]);
					this->OnVideoMirrorOn(
						targetUserId,
						MESSAGE_DATA
					);
				}
				case rtmTextMessageCategory::DEVICE_CHECK:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					Json::Value DEVICE_ASK_TYPE = DEVICE_ASK_TYPE_FromString(jsonRoot["DEVICE_ASK_TYPE"]);
					Json::Value sender = jsonRoot["sender"];
					Json::Value senderScreen = jsonRoot["senderScreen"];
					this->OnDeviceCheck(
						targetUserId,
						DEVICE_ASK_TYPE,
						sender,
						senderScreen
					);
				}
				case rtmTextMessageCategory::DRIVEAWAY:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					this->OnDriveaway(
						targetUserId
					);
				}
				case rtmTextMessageCategory::UPLOAD_LOG:
				{
					Json::Value targetUserId = jsonRoot["targetUserId"];
					this->OnUploadLog(
						targetUserId
					);
				}
				default:
					PLOGE << "Unknow RTM message: " << message->getText();
					break;
				}
			}
		}

		PLOGI << "RTM message: " << message->getText();
	}
}

