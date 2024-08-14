#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/mman.h>

using namespace std;
#define BUFFER_SIZE 128

int main()
{
    /* 文件名 */
    const char *filename = "./text.txt";

    int fd = open(filename, O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(-1);
    }
    /* 获取文件大小 */
    int length = lseek(fd, 0, SEEK_END);
    // cout << length << endl;

    void *addr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED)
    {
        perror("mmap error:");
        exit(-1);
    }
    /* 关闭文件描述符 */
    close(fd);

    /* 创建进程 */
    pid_t pid = fork();
    if(pid > 0)
    {
        cout << "parent process... " << endl;

        /* 父进程 - 负责写 */
        const char *str = "hello world. how are you. I am fine, thank you.";
        /* 字符串拷贝. */
        strncpy(static_cast<char*>(addr), str, strlen(str) + 1);
    }
    else if(pid == 0)
    {
        cout << "child process... " << endl;

        /* 子进程 - 负责读 */
        usleep(1000);

        /* 地址拷贝. */
        char buffer[BUFFER_SIZE] = { 0 };
        memcpy(buffer, addr, sizeof(buffer));

        // printf("%s\n", static_cast<char *>(addr));
        cout << "buffer: " << buffer << endl;
    }
    else
    {
        perror("fork error: ");
        exit(-1);
    }

    /* 接触映射 */
    munmap(addr, length);

    return 0;
}