#include <iostream>
using namespace std;
#include <sqlite3.h>
#include <stdio.h>
#include <unistd.h>
#include <iomanip> // 用于 setw 和 left
#include <vector>

#define BUFFER_SIZE 64

void execute(sqlite3 *myDB)
{
    /* 创建数据库表 */
    const char *sql = "CREATE TABLE IF NOT EXISTS userInfo (  \
                        username text not null, \
                        passwd text not null   \
                             );";

    /* 执行sql语句 */
    int ret = sqlite3_exec(myDB, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        cout << " sqlite3 exec error: " << sqlite3_errmsg(myDB) << endl;
        _exit(-1);
    }

    /* 增加数据 */
    std::string username, passwd;
    cout << "请输入 username:" << endl;
    cin >> username;
    // cout << "请输入 passwd:" << endl;
    // cin >> passwd;

#if 0
    std::string sqlString;
    sqlString = "INSERT INTO userInfo (username, passwd) VALUES ('" + std::string(username) + "','" + std::string(passwd) + "');";

    cout << sqlString << endl;

    ret = sqlite3_exec(myDB, sqlString.c_str(), NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        cout << " sqlite3 exec error: " << sqlite3_errmsg(myDB) << endl;
        _exit(-1);
    }

#else
    // char buffer[64] = "INSERT INTO userInfo (username, passwd) VALUES ('%s', '%s');";
    // char requestSql[128] = {0};
    // sprintf(requestSql, buffer, username.c_str(), passwd.c_str());
    // cout << requestSql << endl;

    // ret = sqlite3_exec(myDB, requestSql, NULL, NULL, NULL);
    // if (ret != SQLITE_OK)
    // {
    //     cout << " sqlite3 exec error: " << sqlite3_errmsg(myDB) << endl;
    //     _exit(-1);
    // }

#endif
    /* 修改密码 */
    char buffer[64] = "UPDATE userInfo SET passwd = '123456' WHERE username = '%s';";
    char requestSql[128] = {0};
    sprintf(requestSql, buffer, username.c_str());
    cout << requestSql << endl;

    ret = sqlite3_exec(myDB, requestSql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        cout << " sqlite3 exec error: " << sqlite3_errmsg(myDB) << endl;
        _exit(-1);
    }
}

int main()
{
    sqlite3 *myDB = nullptr;

    const char *basename = "./test.db";

    /* 连接数据库 */
    int ret = sqlite3_open(basename, &myDB);
    if (ret != SQLITE_OK)
    {
        cout << " sqlite3 open error: " << sqlite3_errmsg(myDB) << endl;
        _exit(-1);
    }

    char buffer[BUFFER_SIZE] = "SELECT * FROM students;";

    int pnRow = 0;
    int pnColumn = 0;
    char **pazResult = nullptr;
    ret = sqlite3_get_table(myDB, buffer, &pazResult, &pnRow, &pnColumn, NULL);
    if (ret != SQLITE_OK)
    {
        cout << " sqlite3 open error: " << sqlite3_errmsg(myDB) << endl;
        _exit(-1);
    }

    cout << "Row: " << pnRow << "\tColumn: " << pnColumn << endl;

    // int colWidth = 10; // 设置列宽度

    vector<vector<std::string>> Datas;

    for (int idx = 1; idx <= pnRow; idx++)
    {
        vector<string> rowData;

        for (int jdx = 0; jdx < pnColumn; jdx++)
        {
            // cout << left << setw(colWidth) << pazResult[idx * pnColumn + jdx] << " ";
            rowData.push_back(pazResult[idx * pnColumn + jdx]);
        }
        // cout << endl;
        Datas.push_back(rowData);
    }

    cout << "rows: " << Datas.size() << endl;

    for (size_t idx = 0; idx < Datas.size(); idx++)
    {
        vector<string> rowData = Datas[idx];
        for (size_t jdx = 0; jdx < rowData.size(); jdx++)
        {
            cout << "rowData[" << jdx << "] = " << rowData[jdx] << "\t";
        }
        cout << endl;
    }

    /* 关闭数据库 */
    sqlite3_close(myDB);

    return 0;
}