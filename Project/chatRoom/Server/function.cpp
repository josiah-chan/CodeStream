#include "function.h"

Function::Function(std::shared_ptr<StdTcpSocket> &clientInfo) : m_clientInfo(clientInfo), m_mysqlDatabase(std::make_shared<MysqlDataBase>())
{
    m_sqliteDatabase.connectDB("./test2.db");
    m_mysqlDatabase->connectDB("chatRoom");
}

bool Function::isUserExist(const char *username)
{
    std::string sql = "SELECT count(*) FROM userInfo where username = '%s';";
    char requestSql[128] = {0};
    sprintf(requestSql, sql.c_str(), username);

    cout << requestSql << endl;

    VecResult res = m_mysqlDatabase->query(requestSql);
    if (res[0][0] == "0")
    {
        return false;
    }
    return true;
}

bool Function::saveUserInfo(const char *username, const char *password)
{
    std::string sql = "INSERT INTO userInfo (username, passwd) values ('%s', '%s');";
    char requestSql[128] = {0};
    sprintf(requestSql, sql.c_str(), username, password);

    if (m_mysqlDatabase->execute(requestSql) != true)
    {
        cout << "file " << __FILE__ << " :" << __LINE__ << endl;
        return false;
    }

    return true;
}

bool Function::isUserPasswordMatch(const char *username, const char *passwd)
{
    std::string sql = "SELECT count(*) FROM userInfo where username = '%s' and passwd = '%s';";
    char requestSql[128] = {0};
    sprintf(requestSql, sql.c_str(), username, passwd);

    cout << requestSql << endl;

    VecResult res = m_mysqlDatabase->query(requestSql);
    if (res[0][0] == "0")
    {
        return false;
    }
    return true;
}

bool Function::isUserOnline([[maybe_unused]] const char *username)
{
    return true;
}

void Function::handleRegister(const std::string &msg)
{
    cout << "handleRegister: " << "File: " << __FILE__ << "\tLine: " << __LINE__ << endl;
    cout << msg << endl;

    const char *username = nullptr;
    const char *passwd = nullptr;
    json_object *jsonObj = json_tokener_parse(msg.c_str());
    if (jsonObj)
    {
        username = json_object_get_string(json_object_object_get(jsonObj, "username"));
        passwd = json_object_get_string(json_object_object_get(jsonObj, "passwd"));
    }

    /* 构建json字符串 */
    /* 1. 创建json对象 */
    json_object *resJsonObj = json_object_new_object();
    /* 2. 设置 <key, value> */
    json_object_object_add(resJsonObj, "type", json_object_new_int(FUNC_REGISTER));

    /* 判断用户是否存在 */
    if (isUserExist(username))
    {
        json_object_object_add(resJsonObj, "result", json_object_new_string("failed"));
        json_object_object_add(resJsonObj, "reason", json_object_new_string("用户已存在"));
        log("Registration failed - User already exists: " + std::string(username), "WARNING");
    }
    else
    {
        /* 保存到数据库 */
        saveUserInfo(username, passwd);
        json_object_object_add(resJsonObj, "result", json_object_new_string("success"));
        log("Registration successful for user: " + std::string(username));
    }

    /* 将json对象转成json字符串 */
    const char *resStr = json_object_to_json_string(resJsonObj);
    m_clientInfo->sendMessage(resStr);
}

void Function::handleAddFriend(const std::string &msg)
{
}

void Function::handleDeleteFriend(const std::string &msg)
{
}

void Function::handleCreateGroup(const std::string &msg)
{
}

void Function::handleExitGroup(const std::string &msg)
{
}

void Function::handleLogin(const std::string &msg)
{
    cout << "handleLogin: " << "File: " << __FILE__ << "\tLine: " << __LINE__ << endl;

    const char *username = nullptr;
    const char *passwd = nullptr;
    json_object *jsonObj = json_tokener_parse(msg.c_str());
    if (jsonObj)
    {
        username = json_object_get_string(json_object_object_get(jsonObj, "username"));
        passwd = json_object_get_string(json_object_object_get(jsonObj, "passwd"));
    }

    /* 构建json字符串 */
    /* 1. 创建json对象 */
    json_object *resJsonObj = json_object_new_object();
    /* 2. 设置 <key, value> */
    json_object_object_add(resJsonObj, "type", json_object_new_int(FUNC_LOGIN));

    /* 判断用户是否已经注册 */
    if (isUserExist(username) == false)
    {
        /* 程序进入，说明用户不存在 */
        json_object_object_add(resJsonObj, "result", json_object_new_string("failed"));
        json_object_object_add(resJsonObj, "reason", json_object_new_string("用户不存在"));
        /* 将消息发送到客户端 */
    }
    else
    {
        /* 如果用户存在，判断用户名和密码是否匹配 */
        if (isUserPasswordMatch(username, passwd) == false)
        {
            json_object_object_add(resJsonObj, "result", json_object_new_string("failed"));
            json_object_object_add(resJsonObj, "reason", json_object_new_string("密码错误"));
        }
        else
        {
            json_object_object_add(resJsonObj, "result", json_object_new_string("success"));
        }
    }

    /* 将json对象转成json字符串 */
    const char *resStr = json_object_to_json_string(resJsonObj);

    cout << "resStr: " << resStr << endl;

    m_clientInfo->sendMessage(resStr);
}