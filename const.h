/**
 * @file const.h
 * @author DawnNights (2224825532@qq.com)
 * @brief 消息常量定义
 * @version 1.0
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#define MESSAGE_UNKNOW -1               // 消息类型_未定义
#define MESSAGE_FRIEND 1                // 队列_继续执行
#define MESSAGE_GROUP 2                 // 队列_中断_阻塞
#define MESSAGE_DISCUSSION_GROUP 3      // 消息类型_讨论组
#define MESSAGE_GROUP_TEMP 4            // 消息类型_群临时会话
#define MESSAGE_DISCUSSION_GROUP_TEMP 5 // 消息类型_讨论组临时会话
#define MESSAGE_ONLINE_TEMP 6           // 信息_在线临时会话

#define HANDLE_CANCLE 0              // 处理_忽略或取消
#define HANDLE_CONFIRM 10            // 处理_同意或确定
#define HANDLE_REFUSAL 20            // 处理_拒绝
#define HANDLE_UNILATERAL_CONSENT 10 // 处理_单向同意

#define MESSAGE_MAKE_FRIENDS_UNILATERALLY 1000      // 消息类型_被单向添加好友
#define MESSAGE_MAKE_FRIENDS 1001                   // 消息类型_被请求添加好友
#define MESSAGE_FRIEND_STATUS_CHANGE 1002           // 消息类型_好友状态改变
#define MESSAGE_DELETED_FRIEND 1003                 // 消息类型_被删除好友
#define MESSAGE_FRIEND_SIGNATURE_CHANGE 1004        // 消息类型_好友签名变更
#define MESSAGE_DYNAMIC_REVIEW 1005                 // 消息类型_说说被评论
#define MESSAGE_FRIEND_ENTERING 1006                // 消息类型_好友正在输入
#define MESSAGE_TODAY_FRIEND_CHAT_FIRST 1007        // 消息类型_好友今天首次发起会话
#define MESSAGE_SHAKE_BY_FRIENDS 1008               // 消息类型_被好友抖动
#define MESSAGE_FRIEND_FILE_RECEPTION 1009          // 消息类型_好友文件接收
#define MESSAGE_FRIEND_VIDEO_RECEPTION 1010         // 消息类型_好友视频接收
#define MESSAGE_WHO_WANT_JOIN_GROUP 2001            // 消息类型_某人申请加入群
#define MESSAGE_WHO_INVITED_JOIN_GROUP 2002         // 消息类型_某人被邀请加入群
#define MESSAGE_SLEF_INVITED_JOIN_GROUP 2003        // 消息类型_我被邀请加入群
#define MESSAGE_WHO_APPROVED_JOIN_GROUP 2005        // 消息类型_某人被批准加入了群
#define MESSAGE_WHO_LEFT_GROUP 2006                 // 消息类型_某人退出群
#define MESSAGE_WHO_EXPELLED_GROUP 2007             // 消息类型_某人被管理移除群
#define MESSAGE_GROUP_DISSOLUTION 2008              // 消息类型_某群被解散
#define MESSAGE_GROUP_WHO_BECOME_OP 2009            // 消息类型_某人成为管理
#define MESSAGE_GROUP_WHO_NO_LONGER_OP 2010         // 消息类型_某人被取消管理
#define MESSAGE_GROUP_CARD_CHANGE 2011              // 消息类型_群名片变动
#define MESSAGE_GROUP_NAME_CHANGE 2012              // 消息类型_群名变动
#define MESSAGE_GROUP_ANNOUNCEMENT_CHANGE 2013      // 消息类型_群公告变动
#define MESSAGE_GROUP_WHO_SHUT_UP 2014              // 消息类型_对象被禁言
#define MESSAGE_GROUP_WHO_NOT_SHUT_UP 2015          // 消息类型_对象被解除禁言
#define MESSAGE_GROUP_ALL_SHUT_UP 2016              // 消息类型_群管开启全群禁言
#define MESSAGE_GROUP_ALL_NOT_SHUT_UP 2017          // 消息类型_群管关闭全群禁言
#define MESSAGE_GROUP_ALLOW_ANONYMOUS_CHAT 2018     // 消息类型_群管开启匿名聊天
#define MESSAGE_GROUP_NOT_ALLOW_ANONYMOUS_CHAT 2019 // 消息类型_群管关闭匿名聊天
#define MESSAGE_GROUP_RECALL_MESSAGE 2020           // 消息类型_群撤回消息
#define MESSAGE_GROUP_FILE_RECEPTION 2021           // 消息类型_群文件接收
#define MESSAGE_GROUP_VIDEO_RECEPTION 2022          // 消息类型_群视频接收
#define MESSAGE_HTBOT_COMPLETE 10000                // 消息类型_框架加载完成
#define MESSAGE_HTBOT_RESTART 10001                 // 消息类型_框架即将重启
#define MESSAGE_ADDED_NEW_USER 11000                // 消息类型_添加了一个新的帐号
#define MESSAGE_QQ_LOGIN_COMPLETED 11001            // 消息类型_QQ登录完成
#define MESSAGE_QQ_MANUAL_OFFLINE 11002             // 消息类型_QQ被手动离线
#define MESSAGE_QQ_FORCED_OFFLINE 11003             // 消息类型_QQ被强制离线
#define MESSAGE_QQ_NO_RESPONSE 11004                // 消息类型_QQ长时间无响应或掉线
#define MESSAGE_PLUGIN_LOADED 12000                 // 消息类型_本插件载入 返回 HANDLE_REFUSAL可拒绝加载
#define MESSAGE_PLUGIN_ENABLE 12001                 // 消息类型_用户启用本插件 返回 HANDLE_REFUSAL可拒绝启用
#define MESSAGE_PLUGIN_DISABLED 12002               // 消息类型_用户禁用本插件
#define MESSAGE_PLUGIN_CLICKED 12003                // 消息类型_插件被点击 点击方式参考子类型.1 = 左键单击 2 = 右键单击 3 = 左键双击
#define MESSAGE_RECEIVED_TENPAY_TRANSFER 80001      // 消息类型_收到财付通转账

#define QUEUE_IGNORE 0   // 队列_未处理
#define QUEUE_CONTINUE 1 // 队列_继续执行
#define QUEUE_BLOCK 2    // 队列_中断_阻塞