#include <iostream>
#include <mysql/mysql.h>
#include <iomanip> // 用于 setw 和 left
using namespace std;
#define MYSQL_PORT 3306

void demoLogic(MYSQL *sqlDB)
{
    /* 创建数据表 */
    const char *sql = "CREATE TABLE if not exists students(               \
                        id INT AUTO_INCREMENT PRIMARY KEY,  \
                        name text not NULL,                 \
                        age int,                            \
                        grade varchar(10));";

    int ret = mysql_query(sqlDB, sql);
    if (ret != 0)
    {
        cout << "mysql_query error:" << mysql_error(sqlDB) << endl;
        exit(-1);
    }
    cout << "创建数据表成功" << endl;

    /* 插入数据 */
    /* 插入三条数据 */
    sql = "INSERT INTO students (name, age, grade) values ('josiah', 26, 'A');";
    ret = mysql_query(sqlDB, sql);
    if (ret != 0)
    {
        cout << "mysql_query error:" << mysql_error(sqlDB) << endl;
        exit(-1);
    }
    cout << "数据插入成功" << endl;

    /* 修改数据 */
    // sql = "UPDATE students set age = 25 where name = 'Alice';";
    // ret = mysql_query(sqlDB, sql);
    // if (ret != 0)
    // {
    //     cout << "mysql_query error:" << mysql_error(sqlDB) << endl;
    //     exit(-1);
    // }
    // cout << "数据修改成功" << endl;

    /* 查询语句 */
    sql = "select * from students;";
    ret = mysql_query(sqlDB, sql);
    if (ret != 0)
    {
        cout << "mysql_query error:" << mysql_error(sqlDB) << endl;
        exit(-1);
    }
    cout << "数据查询成功" << endl;

    /* 结果集合 */
    MYSQL_RES *result = mysql_store_result(sqlDB);
    if (result == nullptr)
    {
        cout << "mysql_store_result error: " << mysql_error(sqlDB) << endl;
        exit(-1);
    }

    /* 获取结果集合的列数 */
    unsigned int columns = mysql_num_fields(result);
    cout << "结果集合的列数: " << columns << endl;

    size_t rows = mysql_num_rows(result);
    cout << "结果集合的行数: " << columns << endl;

    /* 获取数据库表的字段 */
    MYSQL_FIELD *field = nullptr;
    while ((field = mysql_fetch_field(result)) != nullptr)
    {
        cout << "field: " << field->name << endl;
    }

    /* 获取数据 */
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != nullptr)
    {
        /* 每个row变量表示一行 */
        for (int col = 0; col < columns; col++)
        {
            cout << left << setw(8) << row[col] << " ";
        }
        cout << endl;
    }

    /* 释放结果集 */
    mysql_free_result(result);
}

int main()
{
    /* 初始化数据库 */
    MYSQL *sqlDB = nullptr;
    sqlDB = mysql_init(nullptr);
    if (sqlDB == nullptr)
    {
        cout << "mySql_init failed." << endl;
        exit(-1);
    }

    cout << "mySQL 初始化成功..." << endl;

    /* 连接数据库 */
    const char *host = "localhost";
    const char *user = "root";
    const char *passwd = "330133czf";
    const char *baseName = "demoTest";

    if (mysql_real_connect(sqlDB, host, user, passwd, baseName, MYSQL_PORT, NULL, 0) == nullptr)
    {
        cout << "File: " << __FILE__ << " Line:" << __LINE__ << " connect mySQL server error! " << mysql_error(sqlDB) << endl;
        exit(-1);
    }
    else
    {
        cout << "连接成功" << endl;
    }

    // demoLogic(sqlDB);

    /* 事务的开始 */
    if (mysql_query(sqlDB, "START TRANSACTION"))
    {
        cout << "START TRANSACTION " << mysql_error(sqlDB) << endl;
        exit(-1);
    }

    /* 执行sql */
    const char *sql1 = "update students set age = age + 100 where name = 'Bob';";
    const char *sql2 = "update students set age = age - 100 where name = 'Chris';";

    if (mysql_query(sqlDB, sql1))
    {
        /* sql语句有问题 */
        cout << "File: " << __FILE__ << " Line:" << __LINE__ << " sql1  " << mysql_error(sqlDB) << endl;
        mysql_query(sqlDB, "ROLLBACK");
        mysql_close(sqlDB);
        exit(-1);
    }
    else
    {
        /* sql语句没有问题，判断是否影响了Row */
        size_t affectRow = mysql_affected_rows(sqlDB);
        cout << "affectRows: " << affectRow << endl;

        if (affectRow == 0)
        {
            mysql_query(sqlDB, "ROLLBACK");
            exit(-1);
        }
    }

    if (mysql_query(sqlDB, sql2))
    {
        cout << "File: " << __FILE__ << " Line:" << __LINE__ << " sql2 " << mysql_error(sqlDB) << endl;
        mysql_query(sqlDB, "ROLLBACK");
        mysql_close(sqlDB);
        exit(-1);
    }
    else
    {
        /* sql语句没有问题，判断是否影响了Row */
        size_t affectRow = mysql_affected_rows(sqlDB);
        cout << "affectRows: " << affectRow << endl;
        if (affectRow == 0)
        {
            mysql_query(sqlDB, "ROLLBACK");
            exit(-1);
        }
    }

    /* 事务的提交 */
    if (mysql_query(sqlDB, "COMMIT"))
    {
        cout << "File: " << __FILE__ << " Line:" << __LINE__ << " COMMIT " << mysql_error(sqlDB) << endl;
        mysql_query(sqlDB, "ROLLBACK");
        mysql_close(sqlDB);
        exit(-1);
    }

    /* 关闭数据库 */
    mysql_close(sqlDB);

    return 0;
}