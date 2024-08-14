#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handleSignal(int sig)
{
    fprintf(stdout, "捕捉到终端信号 %d\n", sig);
    exit(0);
}

int main()
{
    struct sigaction sigTset;   // 初始化结构体
    memset(&sigTset, 0, sizeof(sigTset));

    sigTset.sa_flags = 0;
    sigTset.sa_handler = handleSignal; // 指定信号处理函数

    /* 屏蔽信号集 */
    sigemptyset(&sigTset.sa_mask);

    fprintf(stdout, "程序正在运行, 按CTRL+C退出...\n");

    if (sigaction(SIGINT, &sigTset, nullptr) == -1)
    {
        perror("sigaction error");
        exit(-1);
    }

    while (1)
    {
        pause();
    }

    return 0;
}