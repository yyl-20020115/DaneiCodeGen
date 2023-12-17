## 老师接收学员 IDE 中代码的状态，运行，停止状态。此功能需要配合童程在线客户端才能完整体现。
UserEvent:SEND_CODE_STATUS: 'SEND_CODE_STATUS'

```javascript
// 发送消息体
{
  "code": rtmTextMessageCategory.SEND_CODE_STATUS,     // rt
  "type": 'runStart' | 'openIDE'  // runStart 情况下，status 1就是开启运行了。没有0的状态。  openIDE 1就是打开了IDE, 0就是关闭了IDE
  "status": 1 | 0,
  "sender": rtcUid,
}
```

## window7 Aero 功能是否启用
UserEvent:IS_AERO_GLASS_ENABLED: 'IS_AERO_GLASS_ENABLED'，由于 electron 的透明窗口依赖 aero，当用户关闭此功能后，创建的透明窗口就会是黑屏。所以这些机器会提示不支持画笔功能。纯 native 开发透明窗口，不应该使用这类 api 开发透明窗口。

```javascript
// 发送消息体
{
  "code": rtmTextMessageCategory.IS_AERO_GLASS_ENABLED,
  "enable": 1 | 0,   // 1启用  2 关闭
  "sender": rtcUid,
}
```


## 是否固定学员屏幕

UserEvent:FIXED_STUDENT_WINDOW: 'FIXED_STUDENT_WINDOW'，固定屏幕后屏幕不可放大缩小，不可拖动，一直置顶。

```javascript
// 发送消息体
{
  "code": rtmTextMessageCategory.FIXED_STUDENT_WINDOW,
  "fixed": flag, // flag 0 固定  1不固定
}
```


## 远程控制

UserEvent:CONTROL_SCREEN: '10014'

```javascript
{
  "code": rtmTextMessageCategory.CONTROL_SCREEN,
  "targetUserId": targetUserId,
  "status": CONTROL_STATUS {
            /**
             * 未曾远程过。默认状态
             */
            NO_CONTROL_RECORD = 0,
            /**
             * 已经同意远程，并初始化好，回执给请求方，主控
             */
            CONTROL_READY = 6,
            /**
             * 正在远程，中间状态，远程成功设置
             */
            CONTROL_ING = 1,
            /**
             * 同意远程，中间状态，同意后会发起远程覆盖此状态
             */
            CONTROL_AGREE = 2,
            /**
             * 结束远程，断开连接或者结束后设置
             */
            CONTROL_END = 3,
            /**
             * 请求远程，主控发送给被控的指令
             */
            CONTROL_ASK = 4,
            /**
             * 拒绝远程，被控端弹窗点击拒绝或者关闭按钮回执给主控的状态
             */
            CONTROL_REFUED = 5,
            /**
             * 控制失败，此状态没用
             */
            CONTROL_ERROR= 7,
            /**
             * 发起请求后等待响应，用户取消远程后设置
             */
            CONTROL_CANCEL =8,
            /**
             * 停止远程控制窗口，发送结束远程控制的消息指令
             */
            STOP_CONTROL_WINDOW = 9,
          }
  "statusName?": controlName,  // 远端要展示的文案
  "server_address": address,  // 被控端启动服务后拿到的地址
  "server_session": session,  // 被控端启动服务后拿到的会话id.  address 和 sessions应该成对出现，单个无法实现远程。
  "sender": UserInfoState.userId,
}
```

## 修改用户的昵称

UserEvent:NICKNAME_CHANGE: '10015', 昵称被老师修改后，全员广播修改其本地用户列表中的昵称

```javascript
{
    "code": rtmTextMessageCategory.NICKNAME_CHANGE,
    "targetUserId": targetUserId,
    "nickName": nickName,
  }
```

## 华为画笔

UserEvent:HWWHITE_BOARD: '20000'

```javascript
{
  "code": rtmTextMessageCategory.HWWHITE_BOARD,
  "targetUserId": targetUserId,
  "status": WHITE_BOARD_MSG_TYPES.{
              WB_CREACT = "wb-creact", // 创建白板 没用
              WB_SAVESHAPE = "wb-saveshape", // 有图形绘制如矩形，椭圆等画板数据都通过这个类型发送, 设置此属性需要同步设置param属性，设置方式见下方
              WB_REDO = "wb-redo", // 重做, 设置此属性需要同步设置param属性，设置方式见下方
              WB_UNDO = "wb-undo", // 撤销, 设置此属性需要同步设置param属性，设置方式见下方
              WB_CLEAR = "wb-clear", // 清空, 设置此属性需要同步设置param属性，设置方式见下方
              WB_TEARDOWN = "wb-teardown", // 没用, 设置此属性需要同步设置param属性，设置方式见下方
            }
  "param":  status === WB_SAVESHAPE // 当有图形绘制时通过param传递数据信息，param的组装如下
              {
                type: "shapeSave", // 固定
                data: that.instance.shapeToJSON_Hb(shape.shape), // 导出的图形数据，详见画板接口.md文档
                canvas: this.noteBounds, // electron rtc sdk 渲染到屏幕上canvas的bounds
              }
            status === WE_REDO
              {
                type: "redo", // 固定格式，常用来通知被注释者重做撤销的操作
              }
            status === WB_UNDO
              {
                type: "undo", // 固定格式，常用来通知被注释者撤销上一次操作
              }
            status === WB_CLEAR
              {
                type: "clear", // 固定格式，常用来通知被注释者清空画板
              }
            status === WB_TEARDOWN
              {
                type: "clear", // 固定格式，销毁画板调用
              }
}
```

## 老师通知全体下课

UserEvent:END_CLASS:'10020'，需要销毁 rtm，rtc，教室内用到的所有窗口。

```javascript
{
    "code": rtmTextMessageCategory.END_CLASS,
    "targetUserId": "all",  // 固定写法 发给所有人的都是all
  }
```

## 网易 IM 专用：对某人禁言

UserEvent:MUTE_SPEAK:'10021'

```javascript
{
  "scene": "team" | "p2p", // team 暂时写死，只有这一个
  "to": teamId,
  "tip": text, // exp: `${rtmTextMessageCategory.MUTE_SPEAK}&${account}&${mute}`  account 网易账户，mute 控制指令
  'done': done, // 此功能没深入了解应该是完成后的回执，功能上没有实现。
}
```

## 教室锁定状态

UserEvent:LOCK_CLASS: 'LOCK_CLASS'

```javascript
{
    "code": rtmTextMessageCategory.LOCK_CLASS,
    "status": LOCK_STATUS {
              LOCK = 1, // 锁定
              UNLOCK = 2, // 未锁定,
              }
  }
```


## 老师发送试题，通知学员开始答题

UserEvent:DISTRIBUTE_QUESTIONS: 'DISTRIBUTE_QUESTIONS'

```javascript
{
  "code": rtmTextMessageCategory.DISTRIBUTE_QUESTIONS,
  "targetUserId",
  "questionNumber", // 题目id
  "questionVersion", // 题目version
  "type": questionStatusType {
          'noPush', // 未开始
          'pushing', // 老师已经发布试题
          'pushed', // 试题已经结束收卷
          'add' = 100,// 新增试题
        }
}
```

## 学生提交答题的试卷

UserEvent:SUBMIT_QUETIONS: 'SUBMIT_QUETIONS'

```javascript
{
  "code": rtmTextMessageCategory.SUBMIT_QUETIONS,
  "targetUserId": UserInfoState.userId,
}
```

## 老师让学员结束答题

UserEvent:EXAM_END: 'EXAM_END'

```javascript
{
  "code": rtmTextMessageCategory.EXAM_END,
  "targetUserId": 'all',
}
```

## 通知学员展示答题卡

UserEvent:STUDENT_LOOK_QUESTIONS: 'STUDENT_LOOK_QUESTIONS'

```javascript
{
    "code": rtmTextMessageCategory.STUDENT_LOOK_QUESTIONS,
    "targetUserId",
    "questionNumber",
    "questionVersion",
    "type": // 题目类型
    "show": true | false // 展开或隐藏答题卡
  }
```

## 老师发送金币

UserEvent:TEACHER_SEND_AWARD: 'TEACHER_SEND_AWARD'

```javascript
{
    "code": rtmTextMessageCategory.TEACHER_SEND_AWARD,
    "targetUserId": "all",
    "messageData": "接口返回数据" // 发送前调用API_TeacherBatchGold 获取
  }
```

## 设置为镜像-同步本地镜像

UserEvent:VIDEO_MIRROR_ON: 'VIDEO_MIRROR_ON'

```javascript
{
  "code": rtmTextMessageCategory.VIDEO_MIRROR_ON,
  "targetUserId": "all",
  "messageData": MESSAGE_DATA{
    "userId": rtcUid, // 本地自己的rtcuid
    "type": 1 | 0, // 1 镜像 0 非镜像
  }
```

## 白板是否支持

UserEvent:DEVICE_CHECK:'DEVICE_CHECK'，由于 win7 aero 问题，使用白板的时候都要问一下是否支持，通过 status 设置 ask 询问是否支持，再通过此接口 设置 status 其他状态告诉发送这当前状态。

```javascript
{
  "code": rtmTextMessageCategory.DEVICE_CHECK,
  "targetUserId": targetUserId,
  "status": DEVICE_ASK_TYPE. {
              ASK=0, // 询问状态
              SUPPORT =1, // 回答状态
              NO_SUPPORT=2, // 回答状态
              NO_SUPPORT_ELECTRON=3 // 回答状态
            }
  "sender": sender, // 发送者
  "senderScreen":  "doubleScreen" | "mainScreen", // 双屏应用，native不用理会这个
  }
```

## 将某个学员移除教室

UserEvent:DRIVEAWAY:'DRIVEAWAY'

```javascript
{
  "code": rtmTextMessageCategory.DRIVEAWAY,
  "targetUserId": user.userId,
}

```


## 上传用户本地的日志

UserEvent:UPLOAD_LOG:'UPLOAD_LOG'

```javascript
{
  "code": rtmTextMessageCategory.UPLOAD_LOG,
  "targetUserId": targetUserId
}
```
