#include "messageHandle.h"

/* 构造函数 */
MessageHandle::MessageHandle(std::shared_ptr<StdTcpSocket> &clientInfo) : m_function(clientInfo)
{
    /* 注册业务 */
    m_handles[FUNC_REGISTER] = [this](const std::string &msg)
    { m_function.handleRegister(msg); };

    m_handles[FUNC_LOGIN] = [this](const std::string &msg)
    { m_function.handleLogin(msg); };

    m_handles[FUNC_ADD_FRIEND] = [this](const std::string &msg)
    { m_function.handleAddFriend(msg); };

    m_handles[FUNC_DEL_FRIEND] = [this](const std::string &msg)
    { m_function.handleDeleteFriend(msg); };

    m_handles[FUNC_SEARCH_MUSIC] = [this](const std::string &msg)
    { m_function.handleOnlineMusicInfo(msg); };
}

/* 析构函数 */
MessageHandle::~MessageHandle() = default;

void MessageHandle::handleMessage(const std::string &msg)
{
    /* msg是json字符串 */
    /* 1.将json字符串转成json对象 */
    json_object *jsonObj = json_tokener_parse(msg.c_str());
    int type = 0;

    if (jsonObj != nullptr)
    {
        /* 2.根据key得到的value */
        type = json_object_get_int(json_object_object_get(jsonObj, "type"));
    }
    else
    {
        cout << "parse error" << endl;
    }

    auto iter = m_handles.find(type);
    if (iter != m_handles.end())
    {
        /* 执行回调函数 */
        iter->second(msg);
    }
    else
    {
        /* 处理未知消息的类型 */
        std::cout << "unknown message type." << std::endl;
    }
}