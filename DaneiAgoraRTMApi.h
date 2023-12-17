enum class rtmTextMessageCategory :int
{
	NONE = -1,
	SEND_CODE_STATUS = -2,
	IS_AERO_GLASS_ENABLED = -3,
	FIXED_STUDENT_WINDOW = -4,
	CONTROL_SCREEN = 10014,
	NICKNAME_CHANGE = 10015,
	HWWHITE_BOARD = 20000,
	END_CLASS = 10020,
	MUTE_SPEAK = 10021,
	LOCK_CLASS = -10,
	DISTRIBUTE_QUESTIONS = -11,
	SUBMIT_QUETIONS = -12,
	EXAM_END = -13,
	STUDENT_LOOK_QUESTIONS = -14,
	TEACHER_SEND_AWARD = -15,
	VIDEO_MIRROR_ON = -16,
	DEVICE_CHECK = -17,
	DRIVEAWAY = -18,
	UPLOAD_LOG = -19,
};

enum class rtmTextMessageCategory :int
{
	SEND_CODE_STATUS = SEND_CODE_STATUS,
	IS_AERO_GLASS_ENABLED = IS_AERO_GLASS_ENABLED,
	FIXED_STUDENT_WINDOW = FIXED_STUDENT_WINDOW,
	CONTROL_SCREEN = 10014,
	NICKNAME_CHANGE = 10015,
	HWWHITE_BOARD = 20000,
	END_CLASS = 10020,
	MUTE_SPEAK = 10021,
	LOCK_CLASS = LOCK_CLASS,
	DISTRIBUTE_QUESTIONS = DISTRIBUTE_QUESTIONS,
	SUBMIT_QUETIONS = SUBMIT_QUETIONS,
	EXAM_END = EXAM_END,
	STUDENT_LOOK_QUESTIONS = STUDENT_LOOK_QUESTIONS,
	TEACHER_SEND_AWARD = TEACHER_SEND_AWARD,
	VIDEO_MIRROR_ON = VIDEO_MIRROR_ON,
	DEVICE_CHECK = DEVICE_CHECK,
	DRIVEAWAY = DRIVEAWAY,
	UPLOAD_LOG = UPLOAD_LOG,
};
enum class CONTROL_STATUS :int
{
	NO_CONTROL_RECORD = 0,
	CONTROL_READY = 6,
	CONTROL_ING = 1,
	CONTROL_AGREE = 2,
	CONTROL_END = 3,
	CONTROL_ASK = 4,
	CONTROL_REFUED = 5,
	CONTROL_ERROR = 7,
	CONTROL_CANCEL = 8,
	STOP_CONTROL_WINDOW = 9,
};
enum class WHITE_BOARD_MSG_TYPES :int
{
	WB_CREACT = -1,
	WB_SAVESHAPE = -2,
	WB_REDO = -3,
	WB_UNDO = -4,
	WB_CLEAR = -5,
	WB_TEARDOWN = -6,
};
enum class LOCK_STATUS :int
{
	LOCK = 1,
	UNLOCK = 2,
};
enum class questionStatusType :int
{
	NOPUSH = -1,
	PUSHING = -2,
	PUSHED = -3,
	add = 100,
};
enum class MESSAGE_DATA :int
{
	"USERID": RTCUID = "userId": rtcUid,
	"TYPE": 1 | 0 = "type": 1 | 0,
};
enum class DEVICE_ASK_TYPE :int
{
	ASK = 0,
	SUPPORT = 1,
	NO_SUPPORT = 2,
	NO_SUPPORT_ELECTRON = 3,
};
class DaneiAgoraRTMApi : agora::rtm::IRtmServiceEventHandler, agora::rtm::IChannelEventHandler
{
public:
	cppcoro::task<int> SendCodeStatus(const std::string& peerId, const std::string& type, bool status, int sender);
	cppcoro::task<int> IsAeroGlassEnabled(const std::string& peerId, bool enable, int sender);
	cppcoro::task<int> FixedStudentWindow(const std::string& peerId, bool fixed);
	cppcoro::task<int> ControlScreen(const std::string& peerId, int targetuserid, CONTROL_STATUS control_status, const std::string& statusname, const std::string& server_address, const std::string& server_session, int sender);
	cppcoro::task<int> NicknameChange(const std::string& peerId, int targetuserid, const std::string& nickname);
	cppcoro::task<int> HwwhiteBoard(const std::string& peerId, int targetuserid, WHITE_BOARD_MSG_TYPES white_board_msg_types, const std::string& param);
	cppcoro::task<int> EndClass(const std::string& peerId, int targetuserid);
	cppcoro::task<int> MuteSpeak(const std::string& peerId, const std::string& scene, int to, const std::string& tip);
	cppcoro::task<int> LockClass(const std::string& peerId, LOCK_STATUS lock_status);
	cppcoro::task<int> DistributeQuestions(const std::string& peerId, questionStatusType questionstatustype);
	cppcoro::task<int> SubmitQuetions(const std::string& peerId, int targetuserid);
	cppcoro::task<int> ExamEnd(const std::string& peerId, int targetuserid);
	cppcoro::task<int> StudentLookQuestions(const std::string& peerId, const std::string& type, bool show);
	cppcoro::task<int> TeacherSendAward(const std::string& peerId, int targetuserid, const std::string& messagedata);
	cppcoro::task<int> VideoMirrorOn(const std::string& peerId, int targetuserid, MESSAGE_DATA message_data);
	cppcoro::task<int> DeviceCheck(const std::string& peerId, int targetuserid, DEVICE_ASK_TYPE device_ask_type, int sender, const std::string& senderscreen);
	cppcoro::task<int> Driveaway(const std::string& peerId, int targetuserid);
	cppcoro::task<int> UploadLog(const std::string& peerId, int targetuserid);
	static std::string ToString(rtmTextMessageCategory val);
	static std::string ToString(CONTROL_STATUS val);
	static std::string ToString(WHITE_BOARD_MSG_TYPES val);
	static std::string ToString(LOCK_STATUS val);
	static std::string ToString(questionStatusType val);
	static std::string ToString(MESSAGE_DATA val);
	static std::string ToString(DEVICE_ASK_TYPE val);
	static rtmTextMessageCategory rtmTextMessageCategory_FromString(const std::string& text);
	static CONTROL_STATUS CONTROL_STATUS_FromString(const std::string& text);
	static WHITE_BOARD_MSG_TYPES WHITE_BOARD_MSG_TYPES_FromString(const std::string& text);
	static LOCK_STATUS LOCK_STATUS_FromString(const std::string& text);
	static questionStatusType questionStatusType_FromString(const std::string& text);
	static MESSAGE_DATA MESSAGE_DATA_FromString(const std::string& text);
	static DEVICE_ASK_TYPE DEVICE_ASK_TYPE_FromString(const std::string& text);
};

