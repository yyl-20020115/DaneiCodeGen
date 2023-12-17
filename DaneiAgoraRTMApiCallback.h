class DaneiAgoraRTMApiCallback
{
public:
	virtual void OnSendCodeStatus(const std::string& peerId, const std::string& type, bool status, int sender) = 0;
	virtual void OnIsAeroGlassEnabled(const std::string& peerId, bool enable, int sender) = 0;
	virtual void OnFixedStudentWindow(const std::string& peerId, bool fixed) = 0;
	virtual void OnControlScreen(const std::string& peerId, int targetuserid, CONTROL_STATUS control_status, const std::string& statusname, const std::string& server_address, const std::string& server_session, int sender) = 0;
	virtual void OnNicknameChange(const std::string& peerId, int targetuserid, const std::string& nickname) = 0;
	virtual void OnHwwhiteBoard(const std::string& peerId, int targetuserid, WHITE_BOARD_MSG_TYPES white_board_msg_types, const std::string& param) = 0;
	virtual void OnEndClass(const std::string& peerId, int targetuserid) = 0;
	virtual void OnMuteSpeak(const std::string& peerId, const std::string& scene, int to, const std::string& tip) = 0;
	virtual void OnLockClass(const std::string& peerId, LOCK_STATUS lock_status) = 0;
	virtual void OnDistributeQuestions(const std::string& peerId, questionStatusType questionstatustype) = 0;
	virtual void OnSubmitQuetions(const std::string& peerId, int targetuserid) = 0;
	virtual void OnExamEnd(const std::string& peerId, int targetuserid) = 0;
	virtual void OnStudentLookQuestions(const std::string& peerId, const std::string& type, bool show) = 0;
	virtual void OnTeacherSendAward(const std::string& peerId, int targetuserid, const std::string& messagedata) = 0;
	virtual void OnVideoMirrorOn(const std::string& peerId, int targetuserid, MESSAGE_DATA message_data) = 0;
	virtual void OnDeviceCheck(const std::string& peerId, int targetuserid, DEVICE_ASK_TYPE device_ask_type, int sender, const std::string& senderscreen) = 0;
	virtual void OnDriveaway(const std::string& peerId, int targetuserid) = 0;
	virtual void OnUploadLog(const std::string& peerId, int targetuserid) = 0;
}

