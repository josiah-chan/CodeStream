#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 64

void my_copyFile(const char *dest, const char *src)
{
    int fd1 = open(src, O_RDONLY);
    if (fd1 < 0)
    {
        perror("open error");
        _exit(-1);
    }

    int permession = 0;
    permession |= R_OK;

    /* 判断是否有写权限 */
    if (access(src, W_OK) == 0)
    {
        printf("原文件可写\n");
        permession |= W_OK;
    }

    /* 判断是否有执行权限 */
    if (access(src, X_OK) == 0)
    {
        printf("源文件可执行\n");
        permession |= X_OK;
    }

    /* 打开目标文件 */
    int fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, permession);
    if (fd2 < 0)
    {
        perror("dest open error");
        _exit(-1);
    }

    /* 开始读写文件 */
    char buffer[BUFFER_SIZE] = {0};
    size_t readBytes = 0;

    while ((readBytes = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        if (write(fd2, buffer, readBytes) != readBytes)
        {
            perror("write error");
            close(fd1);
            close(fd2);
            _exit(-1);
        }
    }

    /* 关闭文件描述符号 */
    close(fd1);
    close(fd2);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("文件路径输入错误, 重新输入\n");
        _exit(-1);
    }

    const char *src = argv[1];
    const char *dest = argv[2];

    my_copyFile(dest, src);

    return 0;
}