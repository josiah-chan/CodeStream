#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    /* 创建命名管道 */
    const char *path = "./fifoInfo";
    int ret = mkfifo(path, 0644);
    if (ret != 0)
    {
        perror("mkfifo error: ");
        exit(-1);
    }

    pid_t pid = fork();
    char *message = "hello world!!!";

    if (pid < 0)
    {
        perror("进程创建失败!");
        _exit(-1);
    }
    else if (pid == 0)
    {
        /* 子进程代码 */
        printf("I am child process\n");

        int fd1 = open(path, O_WRONLY);
        if (fd1 == -1)
        {
            perror("child open fifo error");
            _exit(-1);
        }

        int writeBytes = write(fd1, message, strlen(message));
        if(writeBytes < 0)
        {
            perror("write error");
            _exit(-1);
        }

        close(fd1);
        exit(0);
    }
    else if (pid > 0)
    {
        sleep(3);
        /* 父进程代码 */
        char buffer[64] = { 0 };
        printf("I am farther process\n");

        int fd2 = open(path, O_RDONLY);
        if (fd2 == -1)
        {
            perror("farther open error");
            _exit(-1);
        }

        int readBytes = read(fd2, buffer, sizeof(buffer));
        if (readBytes < 0)
        {
            perror("read error");
            _exit(-1);
        }

        printf("buffer: %s\n" ,buffer);

        wait(NULL);

        close(fd2);

    }

    /* 删除命名管道 */
    unlink(path);

    return 0;
}