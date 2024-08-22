#include "chatRoom.h"
#include "SharedTypes.h"

ChatRoom::ChatRoom(const StdTcpSocketPtr &client) : m_clientSock(client) {}

ChatRoom::~ChatRoom() = default;

void ChatRoom::chatEnter()
{
    ChatMenu();

    int choice = 0;
    cin >> choice;

    choice += m_offset;

    switch (choice)
    {
    case FUNC_ADD_FRIEND:
        addFriends();
        break;
    case FUNC_DEL_FRIEND:
        deleteFriends();
        break;
    default:
        break;
    }
}

void ChatRoom::ChatMenu()
{
    /* 清除屏幕并将光标移动到左上角 */
    std::cout << "\033[2J\033[1;1H" << std::flush;
    cout << "1.添加好友" << endl;
    cout << "2.删除好友" << endl;
    cout << "3.好友聊天" << endl;
    cout << "4.好友列表" << endl;

    cout << "5.创建群聊" << endl;
    cout << "6.退出群聊" << endl;
    cout << "7.加入群聊" << endl;
    cout << "8.邀请进群" << endl;
    cout << "9.群聊天" << endl;
}

void ChatRoom::addFriends()
{
    Message msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FUNC_ADD_FRIEND;

    string addName;
    cout << "请输入要添加联系人的用户名:" << endl;
    cin >> addName;
    strncpy(msg.targetName, addName.c_str(), sizeof(msg.targetName) - 1);

    /* 发送信息给服务器 */
    m_clientSock->sendMessage(static_cast<const void *>(&msg), sizeof(msg));
}

void ChatRoom::deleteFriends()
{
    Message msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FUNC_DEL_FRIEND;

    string delName;
    cout << "请输入删除联系人的用户名..." << endl;
    cin >> delName;
    strncpy(msg.name, delName.c_str(), sizeof(msg.name) - 1);

    /* 发送信息给服务器 */
    m_clientSock->sendMessage(static_cast<const void *>(&msg), sizeof(msg));
}
