#include "GlobalHeader.h"

int main()
{
    int pipefd[2] = {0};
    if (pipe(pipefd) == -1)
    {
        fprintf(stderr, "pipe create error\n");
        _exit(-1);
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(-1);
    }
    else if (pid == 0)
    {
        /* 关闭读端 */
        close(pipefd[0]);

        fprintf(stdout, "I am child process\n");

        char buffer[128] = "hello, world";
        int writeBytes = write(pipefd[1], buffer, sizeof(buffer));
        if (writeBytes < 0)
        {
            perror("write error");
            _exit(-1);
        }

        _exit(0);
    }
    else if (pid > 0)
    {
        sleep(1);

        close(pipefd[1]);

        fprintf(stdout, "I am farther process\n");

        char buffer[128] = {0};
        int readBytes = read(pipefd[0], buffer, sizeof(buffer));
        if (readBytes < 0)
        {
            perror("read error");
            _exit(-1);
        }

        fprintf(stdout, "buffer: %s\n", buffer);

        wait(NULL);
    }

    return 0;
}