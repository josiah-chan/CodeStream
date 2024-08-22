#include <unistd.h>
#include "SharedTypes.h"
#include "chatRoom.h"

/* 日志函数 */
void log(const std::string &message, const std::string &level = "INFO")
{
    cout << "[" << level << "] " << message << std::endl;
}

/* 界面菜单 */
void interfaceMenu()
{
    /* 清除屏幕并将光标移动到左上角 */
    std::cout << "\033[2J\033[1;1H" << std::flush;
    cout << "===== 聊天室客户端 =====\n";
    cout << "1. 注册" << endl;
    cout << "2. 登录" << endl;
    cout << "3. 退出" << endl;
    cout << "========================\n";
}

/* 注册功能 */
void registerFunc(StdTcpSocketPtr &client)
{
    /* 清除屏幕并将光标移动到左上角 */
    std::cout << "\033[2J\033[1;1H" << std::flush;
    log("开始注册流程...");

    string username, passwd;
    cout << "请输入注册的用户名: ";
    cin >> username;
    cout << "请输入你的注册密码: ";
    cin >> passwd;

    /* 发送信息给服务器 */
    Message msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FUNC_REGISTER;
    strncpy(msg.name, username.c_str(), sizeof(msg.name) - 1);
    strncpy(msg.passwd, passwd.c_str(), sizeof(msg.passwd) - 1);

    /* 将用户和密码发送给服务器 */
    client->sendMessage(&msg, sizeof(msg));
    log("发送注册请求到服务器");

    ReplyMsg recvBuffer;
    memset(&recvBuffer, 0, sizeof(ReplyMsg));
    client->recvMessage(&recvBuffer, sizeof(ReplyMsg));

    if (recvBuffer.statusCode == REPLY_REGISTER_SUCCESS)
    {
        log("注册成功", "SUCCESS");
        sleep(1);
    }
    else if (recvBuffer.statusCode == REPLY_REGISTER_USER_EXIST)
    {
        log("注册失败，用户已存在, 等待界面跳转...", "ERROR");
        sleep(1);
    }
}

/* 登录功能 */
void loginFunc(StdTcpSocketPtr &client)
{
    /* 清除屏幕并将光标移动到左上角 */
    std::cout << "\033[2J\033[1;1H" << std::flush;
    log("开始登录流程");

    string username, passwd;
    cout << "请输入登录用户名: ";
    cin >> username;
    cout << "请输入你的密码: ";
    cin >> passwd;

    /* 发送信息给服务器 */
    Message msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FUNC_LOGIN;
    strncpy(msg.name, username.c_str(), sizeof(msg.name) - 1);
    strncpy(msg.passwd, passwd.c_str(), sizeof(msg.passwd) - 1);

    /* 将用户和密码发送给服务器 */
    client->sendMessage(&msg, sizeof(msg));
    log("正在发送登录请求到服务器...");

    ReplyMsg recvBuffer;
    memset(&recvBuffer, 0, sizeof(ReplyMsg));
    client->recvMessage(&recvBuffer, sizeof(ReplyMsg));

    if (recvBuffer.statusCode == REPLY_LOGIN_SUCCESS)
    {
        log("登录成功", "SUCCESS");
        sleep(2);
        ChatRoom chatroom(client);
        chatroom.chatEnter();
    }
    else if (recvBuffer.statusCode == REPLY_LOGIN_PASSWD_ERROR)
    {
        log("登录失败，密码错误", "ERROR");
    }
    else if (recvBuffer.statusCode == REPLY_LOGIN_NO_USER)
    {
        log("登录失败，用户不存在", "ERROR");
    }
    sleep(1);
}

int main()
{
    log("客户端启动");
    /* 客户端 */
    StdTcpSocketPtr client = std::make_shared<StdTcpSocket>();
    /* 连接服务器 */
    const char *serverIp = "127.0.0.1";
    int ret = client->connectToServer(serverIp, 8080);
    if (ret != 0)
    {
        log("连接服务器失败", "ERROR");
        _exit(-1);
    }

    log("成功连接到服务器, 等待跳转...");
    sleep(1);

    int choice;
    while (1)
    {
        interfaceMenu();
        cout << "请输入你的选项: ";
        cin >> choice;

        switch (choice)
        {
        case FUNC_REGISTER:
            registerFunc(client);
            break;

        case FUNC_LOGIN:
            loginFunc(client);
            break;

        case FUNC_EXIT:
            log("客户端退出");
            exit(0);

        default:
            std::cin.clear(); // 清除错误标志
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            log("无效的选项, 请按任意键重试...", "WARNING");
            std::cin.ignore();
            break;
        }
    }

    return 0;
}