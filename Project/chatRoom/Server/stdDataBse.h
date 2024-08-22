#ifndef STD_DATA_BASE_H
#define STD_DATA_BASE_H

#include <string>
#include <vector>

using VecResult = std::vector<std::vector<std::string>>;

class StdDataBase
{

public:
    virtual ~StdDataBase() = default;

public:
    /* 连接数据库 */
    virtual bool connectDB(const std::string &dbFileName) = 0;

    /* 执行SQL语句 */
    virtual bool execute(const std::string &sql) = 0;

    /* 查询SQl语句 */
    virtual VecResult query(const std::string &sql) = 0;

    /* 关闭数据库 */
    virtual void closeDB() = 0;
};

#endif // STD_DATA_BASE_H