#include "stdTcpServer.h"
#include <unistd.h>
#include <sstream>
#include <vector>
#include "SharedTypes.h"
#include "messageHandle.h"
#include "threadPool.h"

using namespace std;

void *handleClientInfo(void *arg)
{
    /* 线程分离 */
    pthread_detach(pthread_self());

    auto *pClientInfo = static_cast<std::shared_ptr<StdTcpSocket> *>(arg);
    auto clientInfo = *pClientInfo;

    log("New client connected. Thread ID: " + std::to_string(pthread_self()));

    MessageHandle handles(clientInfo);

    /* 接受的缓冲区 */
    std::string buffer;
    while (true)
    {
        int readBytes = clientInfo->recvMessage(buffer);
        if (readBytes < 0)
        {
            perror("read eror");
            break;
        }
        if (readBytes == 0)
        {
            log("Client disconnected. Thread ID: " + std::to_string(pthread_self()), "WARNING");
            break;
        }
        else
        {
            // log("Received message type: " + std::string(buffer));

            /* 执行注册的方法 */
            handles.handleMessage(buffer);
        }
        buffer.clear();
    }
    return NULL;
}

int main()
{
    /* 创建线程池对象 */
    ThreadPool pool(3, 8, 20);

    /* 创建服务器对象 */
    StdTcpServer server;

    /* 设置监听 */
    bool res = server.setListen(SERVER_PORT);
    if (res == false)
    {
        cout << "listen error" << endl;
        _exit(-1);
    }

    cout << "server listen... " << endl;

    // int ret = 0;
    while (1)
    {
        auto clientInfo = server.getClientSock();
#if 0
        pthread_t tid;
        ret = pthread_create(&tid, NULL, handleClientInfo, &clientInfo);
        if (ret != 0)
        {
            perror("thread create error");
            _exit(-1);
        }
#else
        // pool.addTask(handleClientInfo, &clientInfo);
        pool.addTask(handleClientInfo, new std::shared_ptr<StdTcpSocket>(clientInfo));
#endif
        /* 休眠 */
        sleep(5);
    }
}