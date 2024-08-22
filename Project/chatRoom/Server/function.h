#ifndef FUNCTION_H
#define FUNCTION_H_

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <json-c/json.h>
#include "stdTcpServer.h"
#include "SharedTypes.h"
#include "sqliteDataBase.h"
#include "mysqlDataBase.h"

using namespace std;

inline std::string getCurrentTime()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

inline void log(const std::string &message, const std::string &level = "INFO")
{
    std::cout << "[" << getCurrentTime() << "] [" << level << "] " << message << std::endl;
}

class Function
{
public:
    /* 构造函数 */
    Function(std::shared_ptr<StdTcpSocket> &clientInfo);
    /* 析构函数 */

    ~Function() = default;
private:
    /* 判断用户名是否存在 */
    bool isUserExist(const char *username);

    /* 保存用户信息 */
    bool saveUserInfo(const char *username, const char *password);

    /* 判断用户名和密码是否匹配 */
    bool isUserPasswordMatch(const char *username, const char *password);

    /* 用户是否已经在线 */
    bool isUserOnline(const char *username);

public:
    /* 处理注册 */
    void handleRegister(const std::string &msg);

    /* 处理登录 */
    void handleLogin(const std::string &msg);

    /* 处理添加好友 */
    void handleAddFriend(const std::string &msg);

    /* 处理删除好友 */
    void handleDeleteFriend(const std::string &msg);

    /* 处理创建群组 */
    void handleCreateGroup(const std::string &msg);

    /* 处理退出群组 */
    void handleExitGroup(const std::string &msg);

private:
    /* 通信类对象 */
    std::shared_ptr<StdTcpSocket> &m_clientInfo;
    /* Sqlite3数据库 */
    SqliteDataBase m_sqliteDatabase;
    /* Mysql数据库 */
    std::shared_ptr<StdDataBase> m_mysqlDatabase;
};

#endif // FUNCTION_H