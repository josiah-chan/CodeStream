#include "GlobalHeader.h"

void handleSignal(int signal)
{
    fprintf(stdout, "捕捉到终端信号\n");
    exit(0);
}

int main()
{
    signal(SIGINT, handleSignal);

    while (1)
    {
        sleep(1);
        fprintf(stdout, "等待接受信号退出\n");
    }    

    return 0;
}