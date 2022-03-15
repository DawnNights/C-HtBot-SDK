/**
 * @file htapi.h
 * @author DawnNights (2224825532@qq.com)
 * @brief 装载易语言DLL的Api
 * @version 1.0
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <windows.h>

typedef unsigned char bool;

/**
 * @brief   取框架版本号
 */
char *(*Api_GetVer)();

/**
 * @brief   取当前框架内部时间戳
 */
int (*Api_GetTimeStamp)();

/**
 * @brief   取框架日志
 */
char *(*Api_GetLog)();

/**
 * @brief   取得插件自身启用状态，启用真 禁用假
 */
bool (*Api_IsEnable)();

/**
 * @brief   请求禁用插件自身
 */
void (*Api_DisabledPlugin)();

/**
 * @brief   在框架记录页输出一行信息
 * @param   content  输出的内容
 */
void (*Api_OutPut)(char *content);

/**
 * @brief   取用户名
 * @param   self_id  机器人QQ
 * @param   user_id  欲取得的QQ的号码
 */
char *(*Api_GetNick)(char *self_id, char *user_id);

/**
 * @brief   向对象、目标发送信息 支持好友 群 讨论组 群临时会话 讨论组临时会话
 * @param   self_id  机器人QQ
 * @param   message_type  1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 6在线临时会话
 * @param   group_id  发送群信息、讨论组信息、群临时会话信息、讨论组临时会话信息时填写
 * @param   user_id  最终接收这条信息的对象QQ
 * @param   content  信息内容
 */
void (*Api_SendMsg)(char *self_id, int message_type, char *group_id, char *user_id, char *content);

/**
 * @brief   发送XML消息
 * @param   self_id  机器人QQ
 * @param   message_type  同Api_SendMsg  1好友 2群 3讨论组 4群临时会话 5讨论组临时会话
 * @param   group_id  发群内、临时会话必填 好友可不填
 * @param   user_id  临时会话、好友必填 发至群内可不填
 * @param   xml_code  XML代码
 * @param   sub_type  00 基本 02 点歌 其他不明
 */
void (*Api_SendXml)(char *self_id, int message_type, char *group_id, char *user_id, char *xml_code, int sub_type);

/**
 * @brief   发送JSON结构消息
 * @param   self_id  机器人QQ
 * @param   message_type  同Api_SendMsg  1好友 2群 3讨论组 4群临时会话 5讨论组临时会话
 * @param   group_id  发群内、临时会话必填 好友可不填
 * @param   user_id  临时会话、好友必填 发至群内可不填
 * @param   json_code  Json结构内容
 */
void (*Api_SendJson)(char *self_id, int message_type, char *group_id, char *user_id, char *json_code);

/**
 * @brief   取得好友列表，返回获取到的原始JSON格式信息，需自行解析
 * @param self_id  机器人QQ
 */
char *(*Api_GetFriendList)(char *self_id);

/**
 * @brief   取得好友列表，返回内容#换行符分割
 * @param self_id  机器人QQ
 */
char *(*Api_GetFriendList_B)(char *self_id);

/**
 * @brief   取得群列表，返回获取到的原始JSON格式信息，需自行解析
 * @param self_id  机器人QQ
 */
char *(*Api_GetGroupList)(char *self_id);

/**
 * @brief   取得群列表，#换行符分割 不受最高获取500群限制（如需获取群名称请对应调用 Api_GetGroupName 理论群名获取不会频繁）
 * @param self_id  机器人QQ
 */
char *(*Api_GetGroupList_A)(char *self_id);

/**
 * @brief   取得群列表，返回获取到的原始JSON格式信息，需自行解析
 * @param self_id  机器人QQ
 */
char *(*Api_GetGroupList_B)(char *self_id);

/**
 * @brief   取得群成员列表，返回获取到的原始JSON格式信息，需自行解析（有群员昵称）
 * @param self_id  机器人QQ
 * @param group_id  欲取群成员列表群号
 */
char *(*Api_GetGroupMemberList)(char *self_id, char *group_id);

/**
 * @brief   取得群成员列表，#换行符分割 失败返回空（无群员昵称）
 * @param self_id  机器人QQ
 * @param group_id 字面意思
 */
char *(*Api_GetGroupMemberList_B)(char *self_id, char *group_id);

/**
 * @brief   取得群成员列表，返回获取到的原始JSON格式信息，需自行解析（有群员昵称）
 * @param self_id  机器人QQ
 * @param group_id  欲取群成员列表群号
 */
char *(*Api_GetGroupMemberList_C)(char *self_id, char *group_id);

/**
 * @brief   取包括群主在内的群管列表
 * @param self_id  机器人QQ
 * @param group_id  欲取管理员列表群号
 */
char *(*Api_GetAdminList)(char *self_id, char *group_id);

/**
 * @brief   取得机器人网页操作用的Cookies
 * @param self_id  机器人QQ
 */
char *(*Api_GetCookies)(char *self_id);

/**
 * @brief   取得腾讯微博页面操作用参数P_skey
 * @param self_id  机器人QQ
 */
char *(*Api_GetBlogPsKey)(char *self_id);

/**
 * @brief   取得QQ空间页面操作用参数P_skey
 * @param self_id  机器人QQ
 */
char *(*Api_GetZonePsKey)(char *self_id);

/**
 * @brief   取得QQ群页面操作用参数P_skey
 * @param self_id  机器人QQ
 */
char *(*Api_GetGroupPsKey)(char *self_id);

/**
 * @brief   取得腾讯课堂页面操作用参数P_skey
 * @param self_id  机器人QQ
 */
char *(*Api_GetClassRoomPsKey)(char *self_id);

/**
 * @brief   取得机器人网页操作用参数Bkn或G_tk
 * @param self_id  机器人QQ
 */
char *(*Api_GetBkn)(char *self_id);

/**
 * @brief   取得机器人网页操作用参数长Bkn或长G_tk
 * @param self_id  机器人QQ
 */
char *(*Api_GetBkn32)(char *self_id);

/**
 * @brief   取得机器人网页操作用参数长Ldw
 * @param self_id  机器人QQ
 */
char *(*Api_GetLongLdw)(char *self_id);

/**
 * @brief   取得机器人网页操作用的Clientkey
 * @param self_id  机器人QQ
 */
char *(*Api_GetClientkey)(char *self_id);

/**
 * @brief   取得机器人网页操作用的长Clientkey
 * @param self_id  机器人QQ
 */
char *(*Api_GetLongClientkey)(char *self_id);

/**
 * @brief   获取会话SessionKey密钥
 * @param self_id  机器人QQ
 */
char *(*Api_SessionKey)(char *self_id);

/**
 * @brief   设置机器人在线状态+附加信息
 * @param self_id  机器人QQ
 * @param state  隐身
 * @param state_info  最大255字节
 */
void (*Api_SetStatus)(char *self_id, int state, char *state_info);

/**
 * @brief   获取机器人状态信息，成功返回：昵称、帐号、在线状态、速度、收信、发信、在线时间，失败返回空
 * @param self_id  机器人QQ
 */
char *(*Api_GetStatus)(char *self_id);

/**
 * @brief   取群公告
 * @param self_id  机器人QQ
 * @param group_id  欲取得公告的群号
 */
char *(*Api_GetNotice)(char *self_id, char *group_id);

/**
 * @brief   根据图片GUID取得图片下载连接
 * @param self_id  机器人QQ
 * @param im_type  1 群 讨论组  2临时会话和好友
 * @param group_id  图片所属对应的群号（可随意乱填写，只有群图片需要填写）
 * @param im_GUID  例如[pic={xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}.jpg]
 */
char *(*Api_GetPicLink)(char *self_id, int im_type, char *group_id, char *im_GUID);

/**
 * @brief   调用一次点一下，成功返回空，失败返回理由如：每天最多给他点十个赞哦，调用此Api时应注意频率，每人每日可被赞10次，每日每Q最多可赞50人
 * @param self_id  机器人QQ
 * @param user_id  填写被赞人QQ
 */
char *(*Api_Like)(char *self_id, char *user_id);

/**
 * @brief   上传QQ语音，成功返回语音GUID  失败返回空
 * @param self_id  机器人QQ
 * @param voice_data  语音字节集数据（AMR Silk编码）
 */
char *(*Api_UpLoadVoice)(char *self_id, int voice_data);

/**
 * @brief   上传图片（通过读入字节集方式），可使用网页链接或本地读入，成功返回该图片GUID，失败返回空
 * @param self_id  机器人QQ
 * @param post_type  1好友、临时会话  2群、讨论组 Ps：好友临时会话用类型 1，群讨论组用类型 2；当填写错误时，图片GUID发送不会成功
 * @param from_id  上传该图片所属的群号或QQ
 * @param im_data  图片字节集数据
 */
char *(*Api_UpLoadPic)(char *self_id, int post_type, char *from_id, int im_data);

/**
 * @brief   申请加群.为了避免广告、群发行为。出现验证码时将会直接失败不处理
 * @param self_id  机器人QQ
 * @param group_id  欲申请加入的群号
 * @param message  附加理由，可留空（需回答正确问题时，请填写问题答案）
 */
void (*Api_JoinGroup)(char *self_id, char *group_id, char *message);

/**
 * @brief   退群
 * @param self_id  机器人QQ
 * @param group_id  欲退出的群号
 */
void (*Api_QuitGroup)(char *self_id, char *group_id);

/**
 * @brief   好友语音上传并发送 （成功返回真 失败返回假）
 * @param self_id  机器人QQ
 * @param user_id  接收语音人QQ
 * @param voice_data  语音字节集数据（AMR Silk编码）
 */
bool (*Api_SendVoice)(char *self_id, char *user_id, int voice_data);

/**
 * @brief   主动加好友 成功返回真 失败返回假 当对象设置需要正确回答问题或不允许任何人添加时无条件失败
 * @param self_id  机器人QQ
 * @param user_id  加谁
 * @param message  加好友提交的理由
 */
bool (*Api_AddFriend)(char *self_id, char *user_id, char *message);

/**
 * @brief   将好友拉入黑名单
 * @param self_id  机器人QQ
 * @param user_id  被拉黑对象
 */
void (*Api_AddBkList)(char *self_id, char *user_id);

/**
 * @brief   解除好友黑名单
 * @param self_id  机器人QQ
 * @param user_id  解除对象
 */
void (*Api_DelBkList)(char *self_id, char *user_id);

/**
 * @brief   禁言群成员W
 * @param self_id  机器人QQ
 * @param group_id  禁言对象所在群.
 * @param user_id  禁言对象.留空为全群禁言
 * @param secs  单位:秒 最大为1个月. 为零解除对象或全群禁言
 */
bool (*Api_Shutup)(char *self_id, char *group_id, char *user_id, int secs);

/**
 * @brief   根据群号+QQ判断指定群员是否被禁言  获取失败的情况下亦会返回假
 * @param self_id  机器人QQ
 * @param group_id  欲查询的群号
 * @param user_id  需要查询的对象QQ
 */
bool (*Api_IsShutup)(char *self_id, char *group_id, char *user_id);

/**
 * @brief   开关群匿名消息发送功能    成功返回真  失败返回假
 * @param self_id  机器人QQ
 * @param group_id  需开关群匿名功能群号
 * @param start  真开    假关
 */
bool (*Api_SetAnon)(char *self_id, char *group_id, bool start);

/**
 * @brief   取出讨论组列表 （返回格式为 换行符分割开的）
 * @param self_id  机器人QQ
 */
char *(*Api_GetDisGroupList)(char *self_id);

/**
 * @brief   取出讨论组成员列表 （返回格式为 换行符分割开的）
 * @param self_id  机器人QQ
 * @param group_id  需获取的讨论组ID
 */
char *(*Api_GetDisGroupMemberList)(char *self_id, char *group_id);

/**
 * @brief   向好友发起窗口抖动，调用此Api腾讯会限制频率
 * @param self_id  机器人QQ
 * @param user_id  接收抖动消息的QQ
 */
bool (*Api_ShakeWindow)(char *self_id, char *user_id);

/**
 * @brief   获取对象资料 此方式为http，调用时应自行注意控制频率（成功返回JSON格式自行解析）
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
char *(*Api_GetObjInfo)(char *self_id, char *user_id);

/**
 * @brief   删除好友 成功返回真 失败返回假
 * @param self_id  机器人QQ
 * @param user_id  被删除对象
 */
bool (*Api_DelFriend)(char *self_id, char *user_id);

/**
 * @brief   屏蔽或接收某群消息
 * @param self_id  机器人QQ
 * @param group_id 字面意思
 * @param shield  真 为屏蔽接收  假为接收并提醒
 */
void (*Api_SetShieldedGroup)(char *self_id, char *group_id, bool shield);

/**
 * @brief   设置或取消群管理员   成功返回真  失败返回假
 * @param self_id 字面意思
 * @param group_id 字面意思
 * @param user_id 字面意思
 * @param setop  真 为设置管理  假为取消管理
 */
bool (*Api_SetAdmin)(char *self_id, char *group_id, char *user_id, bool setop);

/**
 * @brief   消息撤回（成功返回空，失败返回腾讯给出的理由）
 * @param self_id  机器人QQ
 * @param group_id  需撤回消息群号
 * @param message_num  需撤回消息序号
 * @param message_id  需撤回消息ID
 */
char *(*Api_WithdrawMsg)(char *self_id, char *group_id, char *message_num, char *message_id);

/**
 * @brief   置正在输入状态（发送消息后会打断状态）
 * @param self_id  机器人QQ
 * @param user_id  置正在输入状态接收对象
 */
void (*Api_BeInput)(char *self_id, char *user_id);

/**
 * @brief   取对象好友添加验证方式 （00 允许任何人  01 需要身份验证  03 需回答正确问题  04 需回答问题  99 已经是好友）
 * @param self_id  机器人QQ
 * @param user_id  需获取对象QQ
 */
char *(*Api_GetQQAddMode)(char *self_id, char *user_id);

/**
 * @brief   查询对象是否在线
 * @param self_id  机器人QQ
 * @param user_id  需获取对象QQ
 */
bool (*Api_IsOnline)(char *self_id, char *user_id);

/**
 * @brief   查询对象在线状态   返回 1、在线 2、Q我 3、离开 4、忙碌 5、勿扰 6、隐身或离线
 * @param self_id  机器人QQ
 * @param user_id  需获取对象QQ
 */
int (*Api_GetOnlineState)(char *self_id, char *user_id);

/**
 * @brief   查询对象群当前人数和上限人数
 * @param self_id  机器人QQ
 * @param group_id  需查询的群号
 */
char *(*Api_GetGroupMemberNum)(char *self_id, char *group_id);

/**
 * @brief   查询对方是否允许在线状态临时会话消息（非讨论组和群临时）
 * @param self_id  机器人QQ
 * @param user_id  需获取对象QQ
 */
bool (*Api_GetWpa)(char *self_id, char *user_id);

/**
 * @brief   QQ群签到（成功返回真 失败返回假）
 * @param self_id  机器人QQ
 * @param group_id  QQ群号
 * @param area  签到地名（Pro可自定义）
 * @param content  想发表的内容
 */
bool (*Api_SignIn)(char *self_id, char *group_id, char *area, char *content);

/**
 * @brief   取对象群名片
 * @param self_id  机器人QQ
 * @param group_id  群号
 * @param user_id  欲取得群名片的QQ号码
 */
char *(*Api_GetGroupCard)(char *self_id, char *group_id, char *user_id);

/**
 * @brief   向框架帐号列表添加一个Q.当该Q已存在时则覆盖密码
 * @param uin  机器人QQ
 * @param password  机器人密码
 * @param auto_login  运行框架时是否自动登录该Q.若添加后需要登录该Q则需要通过Api_Login操作
 */
bool (*Api_AddQQ)(char *uin, char *password, bool auto_login);

/**
 * @brief   删除框架帐号列表内指定QQ，不可在执行登录过程中删除QQ否则有几率引起错误
 * @param self_id  机器人QQ
 */
void (*Api_DelQQ)(char *self_id);

/**
 * @brief   登录指定QQ，应确保QQ号码在列表中已存在
 * @param self_id  机器人QQ
 */
bool (*Api_Login)(char *self_id);

/**
 * @brief   令指定QQ下线，应确保QQ号码已在列表中且在线
 * @param self_id  机器人QQ
 */
void (*Api_Logout)(char *self_id);

/**
 * @brief   是否QQ好友（双向） 好友返回真 非好友或获取失败返回假
 * @param self_id  机器人QQ
 * @param user_id  需获取对象QQ
 */
bool (*Api_IfFriend)(char *self_id, char *user_id);

/**
 * @brief   调用一次点一下，成功返回空，失败返回理由如：每天最多给他点十个赞哦，调用此Api时应注意频率，每人每日可被赞10次，每日每Q最多可赞50人
 * @param self_id  机器人QQ
 * @param user_id  填写被赞人QQ
 */
char *(*Api_UpVote)(char *self_id, char *user_id);

/**
 * @brief   获取等级 活跃天数 升级剩余活跃天数
 * @param self_id  机器人QQ
 */
char *(*Api_GetQQLevel)(char *self_id);

/**
 * @brief   Tea加密
 * @param src  需加密的内容
 * @param KEY 字面意思
 */
char *(*Api_TeaEncrypt)(char *src, char *KEY);

/**
 * @brief   Tea解密
 * @param src  需解密的内容
 * @param KEY 字面意思
 */
char *(*Api_TeaDecrypt)(char *src, char *KEY);

/**
 * @brief   群号转群ID
 * @param group_id 字面意思
 */
char *(*Api_GNGetGid)(char *group_id);

/**
 * @brief   群ID转群号
 * @param gid 字面意思
 */
char *(*Api_GidGetGN)(char *gid);

/**
 * @brief   修改对象群名片 成功返回真 失败返回假
 * @param self_id  机器人QQ
 * @param group_id  对象所处群号
 * @param user_id  被修改名片人QQ
 * @param card  需要修改的名片
 */
bool (*Api_SetGroupCard)(char *self_id, char *group_id, char *user_id, char *card);

/**
 * @brief   将对象移除群
 * @param self_id  机器人QQ
 * @param group_id  被执行群号
 * @param user_id  被执行对象
 * @param blacklist  真为不再接收，假为接收
 */
void (*Api_KickGroupMBR)(char *self_id, char *group_id, char *user_id, bool blacklist);

/**
 * @brief   退出讨论组
 * @param self_id  机器人QQ
 * @param group_id  需退出的讨论组ID
 */
void (*Api_QuitDisGroup)(char *self_id, char *group_id);

/**
 * @brief   将对象移除讨论组
 * @param self_id  机器人QQ
 * @param group_id  需执行的讨论组ID
 * @param user_id  被执行对象
 */
void (*Api_KickDisGroupMBR)(char *self_id, char *group_id, char *user_id);

/**
 * @brief   修改讨论组名称
 * @param self_id  机器人QQ
 * @param group_id  需执行的讨论组ID
 * @param group_name  需修改的名称
 */
void (*Api_SetDisGroupName)(char *self_id, char *group_id, char *group_name);

/**
 * @brief   修改好友备注姓名
 * @param self_id  机器人QQ
 * @param user_id  需获取对象好友QQ
 * @param name  需要修改的备注姓名
 */
void (*Api_SetFriendsRemark)(char *self_id, char *user_id, char *name);

/**
 * @brief   取好友备注姓名（成功返回备注，失败或无备注返回空）
 * @param self_id  机器人QQ
 * @param user_id  需获取对象好友QQ
 */
char *(*Api_GetFriendsRemark)(char *self_id, char *user_id);

/**
 * @brief   向服务器发送原始封包（成功返回服务器返回的包 失败返回空）
 * @param self_id  机器人QQ
 * @param packet  封包内容
 */
char *(*Api_SendPack)(char *self_id, char *packet);

/**
 * @brief   取框架所有QQ列表 包括未登录以及登录失败的QQ 换行符分割
 */
char *(*Api_GetQQList)();

/**
 * @brief   取框架在线可用的QQ列表 换行符分割
 */
char *(*Api_GetOnlineQQlist)();

/**
 * @brief   取框架离线QQ列表 换行符分割
 */
char *(*Api_GetOffLineList)();

/**
 * @brief   查询对象或自身QQ达人天数（返回实际天数 失败返回-1）
 * @param self_id  机器人QQ
 * @param user_id  需查询对象或机器人QQ
 */
int (*Api_GetExpertDays)(char *self_id, char *user_id);

/**
 * @brief   发布群公告（返回结果Json），调用此API应保证self_id为管理员
 * @param self_id  机器人QQ
 * @param group_id  欲发布公告的群号
 * @param title  公告标题
 * @param content  公告内容
 */
char *(*Api_PBGroupNotic)(char *self_id, char *group_id, char *title, char *content);

/**
 * @brief   抽取群礼物（返回结果Json，需群聊等级LV5后）
 * @param self_id  机器人QQ
 */
char *(*Api_TakeGift)(char *self_id);

/**
 * @brief   查询我的群礼物（返回Json格式）
 * @param self_id  机器人QQ
 */
char *(*Api_CheckGift)(char *self_id);

/**
 * @brief   送群礼物（返回Json格式）
 * @param self_id  机器人QQ
 * @param group_id  需送礼物群号
 * @param user_id  赠予礼物对象
 * @param pid  礼物pid
 */
char *(*Api_GiveGift)(char *self_id, char *group_id, char *user_id, char *pid);

/**
 * @brief   查询对象或自身群聊等级（返回Json格式）
 * @param self_id  机器人QQ
 * @param group_id  查询群号
 * @param user_id  需查询对象或机器人QQ
 */
char *(*Api_GetGroupChatLv)(char *self_id, char *group_id, char *user_id);

/**
 * @brief   QQ群作业发布（返回Json格式）
 * @param self_id  机器人QQ
 * @param group_id  需要发布的群号
 * @param name 字面意思
 * @param title 字面意思
 * @param content 字面意思
 */
char *(*Api_PBHomeWork)(char *self_id, char *group_id, char *name, char *title, char *content);

/**
 * @brief   管理员邀请对象入群，频率过快会失败
 * @param self_id  机器人QQ
 * @param group_id  被邀请加入的群号
 * @param user_id  被邀请人QQ号码（多个号码使用 #换行符 分割）
 */
void (*Api_AdminInviteGroup)(char *self_id, char *group_id, char *user_id);

/**
 * @brief   非管理员邀请对象入群，频率过快会失败
 * @param self_id  机器人QQ
 * @param group_id  被邀请加入的群号
 * @param user_id  被邀请人QQ号码（多个号码使用 #换行符 分割）
 */
void (*Api_NoAdminInviteGroup)(char *self_id, char *group_id, char *user_id);

/**
 * @brief   取对象性别 1男 2女  未知或失败返回-1
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
int (*Api_GetGender)(char *self_id, char *user_id);

/**
 * @brief   取Q龄 成功返回Q龄 失败返回-1
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
int (*Api_GetQQAge)(char *self_id, char *user_id);

/**
 * @brief   取年龄 成功返回年龄 失败返回-1
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
int (*Api_GetAge)(char *self_id, char *user_id);

/**
 * @brief   取个人说明
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
char *(*Api_GetPerExp)(char *self_id, char *user_id);

/**
 * @brief   取个人签名
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
char *(*Api_GetSign)(char *self_id, char *user_id);

/**
 * @brief   取邮箱，获取对象QQ资料内邮箱栏为邮箱时返回
 * @param self_id  机器人QQ
 * @param user_id 字面意思
 */
char *(*Api_GetEmail)(char *self_id, char *user_id);

/**
 * @brief   设置个人签名
 * @param self_id  机器人QQ
 * @param content 字面意思
 */
void (*Api_SetSign)(char *self_id, char *content);

/**
 * @brief   设置机器人性别
 * @param self_id  机器人QQ
 * @param gender  “1”为男 “2”为女
 */
void (*Api_SetGender)(char *self_id, char *gender);

/**
 * @brief   设置机器人昵称
 * @param self_id  机器人QQ
 * @param nickname  需要设置的昵称
 */
void (*Api_SetNick)(char *self_id, char *nickname);

void Api_Init(LPCSTR lpLibFileName)
{
    HMODULE htdll = LoadLibraryA(lpLibFileName);
    Api_GetVer = (char *(*)())GetProcAddress(htdll, "Api_GetVer");
    Api_GetTimeStamp = (int (*)())GetProcAddress(htdll, "Api_GetTimeStamp");
    Api_GetLog = (char *(*)())GetProcAddress(htdll, "Api_GetLog");
    Api_IsEnable = (bool (*)())GetProcAddress(htdll, "Api_IsEnable");
    Api_DisabledPlugin = (void (*)())GetProcAddress(htdll, "Api_DisabledPlugin");
    Api_OutPut = (void (*)(char *))GetProcAddress(htdll, "Api_OutPut");
    Api_GetNick = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetNick");
    Api_SendMsg = (void (*)(char *, int, char *, char *, char *))GetProcAddress(htdll, "Api_SendMsg");
    Api_SendXml = (void (*)(char *, int, char *, char *, char *, int))GetProcAddress(htdll, "Api_SendXml");
    Api_SendJson = (void (*)(char *, int, char *, char *, char *))GetProcAddress(htdll, "Api_SendJson");
    Api_GetFriendList = (char *(*)(char *))GetProcAddress(htdll, "Api_GetFriendList");
    Api_GetFriendList_B = (char *(*)(char *))GetProcAddress(htdll, "Api_GetFriendList_B");
    Api_GetGroupList = (char *(*)(char *))GetProcAddress(htdll, "Api_GetGroupList");
    Api_GetGroupList_A = (char *(*)(char *))GetProcAddress(htdll, "Api_GetGroupList_A");
    Api_GetGroupList_B = (char *(*)(char *))GetProcAddress(htdll, "Api_GetGroupList_B");
    Api_GetGroupMemberList = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetGroupMemberList");
    Api_GetGroupMemberList_B = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetGroupMemberList_B");
    Api_GetGroupMemberList_C = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetGroupMemberList_C");
    Api_GetAdminList = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetAdminList");
    Api_GetCookies = (char *(*)(char *))GetProcAddress(htdll, "Api_GetCookies");
    Api_GetBlogPsKey = (char *(*)(char *))GetProcAddress(htdll, "Api_GetBlogPsKey");
    Api_GetZonePsKey = (char *(*)(char *))GetProcAddress(htdll, "Api_GetZonePsKey");
    Api_GetGroupPsKey = (char *(*)(char *))GetProcAddress(htdll, "Api_GetGroupPsKey");
    Api_GetClassRoomPsKey = (char *(*)(char *))GetProcAddress(htdll, "Api_GetClassRoomPsKey");
    Api_GetBkn = (char *(*)(char *))GetProcAddress(htdll, "Api_GetBkn");
    Api_GetBkn32 = (char *(*)(char *))GetProcAddress(htdll, "Api_GetBkn32");
    Api_GetLongLdw = (char *(*)(char *))GetProcAddress(htdll, "Api_GetLongLdw");
    Api_GetClientkey = (char *(*)(char *))GetProcAddress(htdll, "Api_GetClientkey");
    Api_GetLongClientkey = (char *(*)(char *))GetProcAddress(htdll, "Api_GetLongClientkey");
    Api_SessionKey = (char *(*)(char *))GetProcAddress(htdll, "Api_SessionKey");
    Api_SetStatus = (void (*)(char *, int, char *))GetProcAddress(htdll, "Api_SetStatus");
    Api_GetStatus = (char *(*)(char *))GetProcAddress(htdll, "Api_GetStatus");
    Api_GetNotice = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetNotice");
    Api_GetPicLink = (char *(*)(char *, int, char *, char *))GetProcAddress(htdll, "Api_GetPicLink");
    Api_Like = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_Like");
    Api_UpLoadVoice = (char *(*)(char *, int))GetProcAddress(htdll, "Api_UpLoadVoice");
    Api_UpLoadPic = (char *(*)(char *, int, char *, int))GetProcAddress(htdll, "Api_UpLoadPic");
    Api_JoinGroup = (void (*)(char *, char *, char *))GetProcAddress(htdll, "Api_JoinGroup");
    Api_QuitGroup = (void (*)(char *, char *))GetProcAddress(htdll, "Api_QuitGroup");
    Api_SendVoice = (bool (*)(char *, char *, int))GetProcAddress(htdll, "Api_SendVoice");
    Api_AddFriend = (bool (*)(char *, char *, char *))GetProcAddress(htdll, "Api_AddFriend");
    Api_AddBkList = (void (*)(char *, char *))GetProcAddress(htdll, "Api_AddBkList");
    Api_DelBkList = (void (*)(char *, char *))GetProcAddress(htdll, "Api_DelBkList");
    Api_Shutup = (bool (*)(char *, char *, char *, int))GetProcAddress(htdll, "Api_Shutup");
    Api_IsShutup = (bool (*)(char *, char *, char *))GetProcAddress(htdll, "Api_IsShutup");
    Api_SetAnon = (bool (*)(char *, char *, bool))GetProcAddress(htdll, "Api_SetAnon");
    Api_GetDisGroupList = (char *(*)(char *))GetProcAddress(htdll, "Api_GetDisGroupList");
    Api_GetDisGroupMemberList = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetDisGroupMemberList");
    Api_ShakeWindow = (bool (*)(char *, char *))GetProcAddress(htdll, "Api_ShakeWindow");
    Api_GetObjInfo = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetObjInfo");
    Api_DelFriend = (bool (*)(char *, char *))GetProcAddress(htdll, "Api_DelFriend");
    Api_SetShieldedGroup = (void (*)(char *, char *, bool))GetProcAddress(htdll, "Api_SetShieldedGroup");
    Api_SetAdmin = (bool (*)(char *, char *, char *, bool))GetProcAddress(htdll, "Api_SetAdmin");
    Api_WithdrawMsg = (char *(*)(char *, char *, char *, char *))GetProcAddress(htdll, "Api_WithdrawMsg");
    Api_BeInput = (void (*)(char *, char *))GetProcAddress(htdll, "Api_BeInput");
    Api_GetQQAddMode = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetQQAddMode");
    Api_IsOnline = (bool (*)(char *, char *))GetProcAddress(htdll, "Api_IsOnline");
    Api_GetOnlineState = (int (*)(char *, char *))GetProcAddress(htdll, "Api_GetOnlineState");
    Api_GetGroupMemberNum = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetGroupMemberNum");
    Api_GetWpa = (bool (*)(char *, char *))GetProcAddress(htdll, "Api_GetWpa");
    Api_SignIn = (bool (*)(char *, char *, char *, char *))GetProcAddress(htdll, "Api_SignIn");
    Api_GetGroupCard = (char *(*)(char *, char *, char *))GetProcAddress(htdll, "Api_GetGroupCard");
    Api_AddQQ = (bool (*)(char *, char *, bool))GetProcAddress(htdll, "Api_AddQQ");
    Api_DelQQ = (void (*)(char *))GetProcAddress(htdll, "Api_DelQQ");
    Api_Login = (bool (*)(char *))GetProcAddress(htdll, "Api_Login");
    Api_Logout = (void (*)(char *))GetProcAddress(htdll, "Api_Logout");
    Api_IfFriend = (bool (*)(char *, char *))GetProcAddress(htdll, "Api_IfFriend");
    Api_UpVote = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_UpVote");
    Api_GetQQLevel = (char *(*)(char *))GetProcAddress(htdll, "Api_GetQQLevel");
    Api_TeaEncrypt = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_TeaEncrypt");
    Api_TeaDecrypt = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_TeaDecrypt");
    Api_GNGetGid = (char *(*)(char *))GetProcAddress(htdll, "Api_GNGetGid");
    Api_GidGetGN = (char *(*)(char *))GetProcAddress(htdll, "Api_GidGetGN");
    Api_SetGroupCard = (bool (*)(char *, char *, char *, char *))GetProcAddress(htdll, "Api_SetGroupCard");
    Api_KickGroupMBR = (void (*)(char *, char *, char *, bool))GetProcAddress(htdll, "Api_KickGroupMBR");
    Api_QuitDisGroup = (void (*)(char *, char *))GetProcAddress(htdll, "Api_QuitDisGroup");
    Api_KickDisGroupMBR = (void (*)(char *, char *, char *))GetProcAddress(htdll, "Api_KickDisGroupMBR");
    Api_SetDisGroupName = (void (*)(char *, char *, char *))GetProcAddress(htdll, "Api_SetDisGroupName");
    Api_SetFriendsRemark = (void (*)(char *, char *, char *))GetProcAddress(htdll, "Api_SetFriendsRemark");
    Api_GetFriendsRemark = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetFriendsRemark");
    Api_SendPack = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_SendPack");
    Api_GetQQList = (char *(*)())GetProcAddress(htdll, "Api_GetQQList");
    Api_GetOnlineQQlist = (char *(*)())GetProcAddress(htdll, "Api_GetOnlineQQlist");
    Api_GetOffLineList = (char *(*)())GetProcAddress(htdll, "Api_GetOffLineList");
    Api_GetExpertDays = (int (*)(char *, char *))GetProcAddress(htdll, "Api_GetExpertDays");
    Api_PBGroupNotic = (char *(*)(char *, char *, char *, char *))GetProcAddress(htdll, "Api_PBGroupNotic");
    Api_TakeGift = (char *(*)(char *))GetProcAddress(htdll, "Api_TakeGift");
    Api_CheckGift = (char *(*)(char *))GetProcAddress(htdll, "Api_CheckGift");
    Api_GiveGift = (char *(*)(char *, char *, char *, char *))GetProcAddress(htdll, "Api_GiveGift");
    Api_GetGroupChatLv = (char *(*)(char *, char *, char *))GetProcAddress(htdll, "Api_GetGroupChatLv");
    Api_PBHomeWork = (char *(*)(char *, char *, char *, char *, char *))GetProcAddress(htdll, "Api_PBHomeWork");
    Api_AdminInviteGroup = (void (*)(char *, char *, char *))GetProcAddress(htdll, "Api_AdminInviteGroup");
    Api_NoAdminInviteGroup = (void (*)(char *, char *, char *))GetProcAddress(htdll, "Api_NoAdminInviteGroup");
    Api_GetGender = (int (*)(char *, char *))GetProcAddress(htdll, "Api_GetGender");
    Api_GetQQAge = (int (*)(char *, char *))GetProcAddress(htdll, "Api_GetQQAge");
    Api_GetAge = (int (*)(char *, char *))GetProcAddress(htdll, "Api_GetAge");
    Api_GetPerExp = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetPerExp");
    Api_GetSign = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetSign");
    Api_GetEmail = (char *(*)(char *, char *))GetProcAddress(htdll, "Api_GetEmail");
    Api_SetSign = (void (*)(char *, char *))GetProcAddress(htdll, "Api_SetSign");
    Api_SetGender = (void (*)(char *, char *))GetProcAddress(htdll, "Api_SetGender");
    Api_SetNick = (void (*)(char *, char *))GetProcAddress(htdll, "Api_SetNick");
}