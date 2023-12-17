## rtm 监听到离开房间消息
RTMEvent:LEAVE_CHANNEL: 'LEAVE_CHANNEL'，rtm 监听到离开房间消息，此消息是 rtm 自有监听 memberLeft 的转化形式。API 同声网官网。

- 收到此消息要检查是否正在远程，如果远程中，需要关闭远程的控制窗口
- 如果需要退出应用，应该走退出应用流程。

```javascript
// 监听消息体
const { userId, exit } = data; // data 收到的消息
```

## 房间属性更改

RTMEvent:ATTRIBUTES_UPDATED: 'ATTRIBUTES_UPDATED'

- 设置房间单人或多人共享模式的状态同步。
- 老师分享学员共享，让其他学员可观看的状态同步。

```javascript
// 监听消息体
const { shareControlStaus, shareId } = attributes; // attributes 频道同步接收到的消息体
// shareControlStaus  单人或多人共享模式
// shareId  老师需要学员订阅的学生rtcSid
```
## rtm 的连接状态变化-实现多终端登录控制

RTMEvent:CONNECTION_STATE_CHANGED: 'ConnectionStateChanged'，用来实现多终端登录控制。当返回的状态中抓到 reason == "REMOTE_LOGIN" 我们应该停止当前的教室。提示远端登录

```javascript
const { newState, reason } = rtmConnectionState;
switch (newState) {
  case "ABORTED":
    // 终止
    if (reason == "REMOTE_LOGIN") {
      leaveRoom(false); // 销毁sdk
      // 确认提示框
      Confirm({
        title: "即将关闭教室",
        text: "另一个终端接入，请确认没有丢失账户和密码",
        flag: true,
        hideClose: true,
      })
        .then(() => {
          // 如果有远程窗口，销毁远程
          if (roomInfo.mainControlId != "") {
            classroomService.controlDestroySession();
          }
          // 销毁所有用到的窗口
          destroyWindow();
        })
        .catch(() => {
          window.close();
        });
    } else {
      messageError("消息通道已被终止,请重启教室");
    }
    break;
  case "DISCONNECTED":
    messageError("消息通道已断开,请重启教室");
    // 断开
    break;
}
```

## 发送消息关闭/开启视频

UserEvent:MUTE_VIDEO: '10002'

```javascript
// 发送消息体
{
  "code": rtmTextMessageCategory.MUTE_VIDEO,
  "targetUserId": targetUserId,
  "status": video, // 1 开启 0 关闭
}
```

## 发送消息关闭/开启音频

UserEvent:MUTE_AUDIO: '10000'

```javascript
// 发送消息体
{
  "code": rtmTextMessageCategory.MUTE_VIDEO,
  "targetUserId": targetUserId,
  "status": audio, // 1 开启 0 关闭
}
```

## 屏幕共享控制

UserEvent:SHARE_SCREEN: '10009'

```javascript
// 发送消息体
{
  "code": rtmTextMessageCategory.SHARE_SCREEN,
  "targetUserId": targetUserId,
  "status": SHARE_STATUS.{
            /**
             * 正在共享中，一个中间状态，一般不会通过rtm发送此状态
             */
            SHAREING = 1,
            /**
             * 同意共享，用户点击同意共享后发送给老师回执状态。本地启动共享后，状态被SHAREING 覆盖
             */
            SHARE_AGREE = 2,
            /**
             * 未曾共享过。默认的状态。
             */
            NO_SHARE_RECORD = 0,
            /**
             * 停止共享。用户结束共享
             */
            SHARE_END = 3,
            /**
             * 请求共享，老师请求用户共享，用户会弹出确认提示。
             */
            SHARE_ASK = 4,
            /**
             * 拒绝共享，老师请求用户共享，用户会弹出确认提示，点击拒绝后回执老师的状态
             */
            SHARE_REFUED = 5,
            /**
             * 停止屏幕共享: 此状态没用
             */
            SHARE_STOP = 6,
            /****
             * 共享屏幕的分辨率： 用户共享成功后，需发送一下自己共享的分辨率。供给观看这画板创建使用。
             */
            SHARE_SCREEN_RESOLUTION = 7,
          }

  "statusName?": shareName,  // 对面接收到应该显示的文案
  "bounds?": bounds,   // 当code是 SHARE_SCREEN_RESOLUTION 的时候起作用，用来设置共享者共享分辨率
  "sender": UserInfoState.userId,
}
```
## 通知其他人，我是什么类型的设备

UserEvent:TELL_MY_NEWS:'TELL_MY_NEWS'，是手机进入的，还是网页进入的，还是 pc 客户端进入的

```javascript
{
  "code": rtmTextMessageCategory.TELL_MY_NEWS,
  "deviceType": DEVICE_TYPE {
                  'mobile' = 'mobile',
                  'miniprogram' = 'miniprogram', // 没用到
                  'pcweb'='pcweb'
                }, // 不同类型设置
  "targetUserId": "all",
  "userId": rtcUid // 发送者
}
```


std::string DaneiAgoraRTMApi::GetTextMessageCat(rtmTextMessageCategory cat)
{
	switch (cat) {
	case rtmTextMessageCategory::TELL_MY_NEWS:
		return "TELL_MY_NEWS";
	case rtmTextMessageCategory::MUTE_AUDIO:
		return "10000";
	case rtmTextMessageCategory::MUTE_VIDEO:
		return "10002";
	case rtmTextMessageCategory::SHARE_SCREEN:
		return "10009";
	case rtmTextMessageCategory::SEND_CODE_STATUS:
		return "SEND_CODE_STATUS";
	case rtmTextMessageCategory::UPLOAD_LOG:
		return "UPLOAD_LOG";
	default:
		return "";
	}
}

rtmTextMessageCategory DaneiAgoraRTMApi::GetCatFromText(const std::string& text)
{
	if (text == "TELL_MY_NEWS") {
		return rtmTextMessageCategory::TELL_MY_NEWS;
	}
	else if (text == "10000")
	{
		return rtmTextMessageCategory::MUTE_AUDIO;
	}
	else if (text == "10002") {
		return rtmTextMessageCategory::MUTE_VIDEO;
	}
	else if (text == "10009")
	{
		return rtmTextMessageCategory::SHARE_SCREEN;
	}
	else if (text == "SEND_CODE_STATUS")
	{
		return rtmTextMessageCategory::SEND_CODE_STATUS;
	}
	else if (text == "UPLOAD_LOG")
	{
		return rtmTextMessageCategory::UPLOAD_LOG;
	}
	return rtmTextMessageCategory::NONE;
}

