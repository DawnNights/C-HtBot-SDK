/**
 * @file main.c
 * @author DawnNights (2224825532@qq.com)
 * @brief 海天机器人的C语言开发SDK
 * @version 1.0
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "const.h"
#include "htapi.h"
#include <stdio.h>

char __stdcall __declspec(dllexport) * ht_info()
{
    Api_Init("Message.DLL");

    return "插件名称{C-Plugin}\r\n\
插件版本{1.0.0}\r\n\
插件作者{DawnNights}\r\n\
插件说明{尝试用C语言编译的插件}\r\n";
}

/**
 * @brief   该函数被动响应各种各样的会话、系统事件
 * @param   self_id 多QQ登录情况下用于识别是哪个Q
 * @param   message_type 接收到消息类型，该类型可在常量表中查询具体定义
 * @param   from_id 信息的源头  群号,好友QQ,讨论组ID,临时会话对象QQ等 如果群内接收到消息则为来源群号
 * @param   user_id 主动触发此事件的对象 如 T人时为T人的管理员QQ  如果群内接收到消息则为发送消息的人的QQ
 * @param   target_id 被动接受此事件的对象 如 T人时为被T对象的QQ
 * @param   message 视情况而定的信息内容  申请入群时为入群理由,添加好友为附加信息,T人之类的为空
 * @param   message_num 此参数暂定用于消息撤回
 * @param   message_id 此参数暂定用于消息撤回
 * @param   raw_message 经过解密后的封包字节数据或json结构信息
 * @param   call_ptr 信息回传指针。 视情况而定的返回附加文本信息  拒绝好友申请时则为拒绝理由
 */
int __stdcall __declspec(dllexport) ht_Event(char *self_id, int message_type, int sub_type, char *from_id, char *user_id, char *target_id, char *message, char *message_num, char *message_id, char *raw_message, int call_ptr)
{
    // 以下代码的效果: 当私聊/群聊中有人发"hello"则回复"hello world"
    if (!strcmp("hello", message))
    {
        if (message_type == MESSAGE_FRIEND)
        {
            Api_SendMsg(self_id, message_type, "", from_id, "hello world");
        }
        else if (message_type == MESSAGE_GROUP)
        {
            Api_SendMsg(self_id, message_type, from_id, "", "hello world");
        }
    }
    return QUEUE_CONTINUE;
}

void __stdcall __declspec(dllexport) ht_Set()
{
    MessageBox(NULL, "本插件载入", "测试", MB_OK);
}

int __stdcall __declspec(dllexport) ht_End()
{
    return 0;
}