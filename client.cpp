#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
/* 地址转成二进制头文件 */
#include <arpa/inet.h>
#define SERVER_PORT 8080

int main()
{
    /* 创建套接字 */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket error");
        _exit(-1);
    }
    cout << "sockfd: " << sockfd << endl;

    /* 连接服务器 */
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);

    const char *ip = "localhost";
    /* 转成二进制 */
    inet_pton(AF_INET, ip, &serverAddress.sin_addr.s_addr);
    // inet_addr(ip);

    /* 开始连接 */
    int ret = connect(sockfd, reinterpret_cast<const sockaddr *>(&serverAddress), sizeof(serverAddress));
    if (ret != 0)
    {
        perror("connect error");
        _exit(-1);
    }

    char writeBuffer[128] = {0};
    char readBuffer[128] = {0};
    while (1)
    {
        cout << "请输入要发送的信息: " << endl;
        cin >> writeBuffer;

        write(sockfd, writeBuffer, strlen(writeBuffer) + 1);
        /* 休眠 */
        sleep(2);

        read(sockfd, readBuffer, sizeof(readBuffer));

        cout << "receive from server: " << readBuffer << endl;
    }

    /* 关闭文件描述符 */
    close(sockfd);

    return 0;
}