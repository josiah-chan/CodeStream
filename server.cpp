#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <pthread.h>

#define SERVER_PORT 8080

void *handleClientInfo(void *arg)
{
    /* 线程分离，让系统管理 */
    pthread_detach(pthread_self());
    /* 通信的文件描述符 */
    int connfd = *(int *)arg;
    /* 读取客户端发送的缓冲区 */
    char buffer[1024] = {0};
    int readBytes = 0;

    while (1)
    {
        readBytes = read(connfd, buffer, sizeof(buffer));
        if (readBytes < 0)
        {
            cout << "readBytes < 0" << endl;
            break;
        }
        else if (readBytes == 0)
        {
            /* 客户端断开连接 */
            cout << "readBytes = 0" << endl;
            break;
        }
        else
        {
            cout << "buffer: " << buffer << endl;
            /* 字母小写改为大写 */
            for (int idx = 0; idx < readBytes; idx++)
            {
                buffer[idx] = toupper(buffer[idx]);
            }

            write(connfd, buffer, readBytes);
        }
    }

    /* 回收资源 */
    close(connfd);
    /* 线程退出 */
    pthread_exit(NULL);
}

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

    /* 设置端口复用 */
    int optVal = 1;
    int ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal));
    if (ret != 0)
    {
        perror("bind error");
        _exit(-1);
    }

    /* 将文件描述符和本地的IP与端口进行绑定 */
    struct sockaddr_in localAddress;
    memset(&localAddress, 0, sizeof(localAddress));
    /* 地址族 */
    localAddress.sin_family = AF_INET;
    /* 本地地址小端字节序，转换成网络大端字节序 */
    localAddress.sin_port = htons(SERVER_PORT);
    localAddress.sin_addr.s_addr = htonl(INADDR_ANY); /* 具体的ip地址 */
    /* 绑定 */
    ret = bind(sockfd, reinterpret_cast<const sockaddr *>(&localAddress), sizeof(localAddress));
    if (ret != 0)
    {
        perror("bind error");
        _exit(-1);
    }

    /* 给监听的套接字设置监听 */
    ret = listen(sockfd, 0);
    if (ret != 0)
    {
        perror("listen error!");
        _exit(-1);
    }
    cout << "server listen ... " << endl;

    int connfd = 0;

    while (1)
    {
        /* 每接受新的客户端连接 - 解除阻塞 */
        connfd = accept(sockfd, NULL, NULL);
        if (connfd == -1)
        {
            perror("accept error");
            _exit(-1);
        }
        cout << "与客户端建立连接, connfd: " << connfd << endl;

        /* 程序达到这个地方：就需要单独开辟线程去处理用户的请求 */
        /* 创建一个新的线程 */
        pthread_t tid = 0;
        ret = pthread_create(&tid, NULL, handleClientInfo, (void *)&connfd);
        if (ret != 0)
        {
            perror("thread craete error");
            _exit(-1);
        }

        /* 休眠 5 s, 给足等待线程创建的时间， */
        sleep(5);
    }

    /* 释放资源 */
    close(connfd);
    /* 关闭文件描述符 */
    close(sockfd);

    cout << "servel exited... Byebye!" << endl;
}