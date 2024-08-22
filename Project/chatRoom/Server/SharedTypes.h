#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

enum FunctionOption
{
    FUNC_REGISTER = 1, /* 注册 */
    FUNC_LOGIN,        /* 登录 */
    FUNC_EXIT,         /* 退出 */
    FUNC_ADD_FRIEND,   /* 添加好友 */
    FUNC_DEL_FRIEND,   /* 删除好友 */
    FUNC_NEW_GROUP,    /* 建群 */
    FUNC_EXIT_GROUP,   /* 退群 */
    FUNC_SEARCH_MUSIC, /* 搜索服务器音乐 */
    FUNC_ONLINE_MUSIC  /* 处理在线音乐 */
};

enum ReplyCode
{
    REPLY_REGISTER_SUCCESS,    /* 注册成功 */
    REPLY_REGISTER_USER_EXIST, /* 用户已存在 */
    
    REPLY_LOGIN_SUCCESS,       /* 登录成功 */
    REPLY_LOGIN_PASSWD_ERROR,  /* 密码错误 */
    REPLY_LOGIN_NO_USER        /* 用户不存在 */
};

struct Message
{
    FunctionOption type;
    char name[20];
    char passwd[20];
    char targetName[20];
};

struct ReplyMsg
{
    FunctionOption type;   /* 操作类型 */
    ReplyCode statusCode;  /* 回复的状态码 */
};

#endif  //SHARED_TYPES_H