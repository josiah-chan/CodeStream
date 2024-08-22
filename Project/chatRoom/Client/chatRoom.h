#ifndef CHAT_ROOM_H
#define CHAT_ROOM_H

#include <cstring>
#include <limits>
using namespace std;
#include "stdTcpServer.h"

class ChatRoom
{
public:
    /* 构造函数 */
    ChatRoom(const StdTcpSocketPtr &client);

    /* 析构函数 */
    ~ChatRoom();

public:
    void chatEnter();

private:
    /* 聊天菜单 */
    void ChatMenu();

    /* 添加好友 */
    void addFriends();

    /* 删除好友 */
    void deleteFriends();

private:
    StdTcpSocketPtr m_clientSock;

    /* 枚举菜单偏移 */
    static const int m_offset = 3;
};

#endif // CHAT_ROOM_H