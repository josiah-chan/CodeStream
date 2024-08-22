#include <iostream>
using namespace std;

#include <pthread.h>
#include <unistd.h>
/* 信号量的头文件 */
#include <semaphore.h>

/* 信号量 */
sem_t g_sem;

void printer(const char *str)
{
    if( str == NULL)
    {
        return;
    }

    /* P操作: 信号量减 1 */
    sem_wait(&g_sem);

    while( *str != '\0')
    {
        cout << *(str++);
        fflush(stdout);
        usleep(500000);
    }
    cout << endl;

    /* V操作: 信号量加 1 */
    sem_post(&g_sem);
}

void *thread_func1(void *arg)
{
    /* 线程分离 */
    pthread_detach(pthread_self());

    const char *str = "hello";
    printer(str);

    /* 线程退出 */
    pthread_exit(NULL);
}

void *thread_func2(void *arg)
{
    /* 线程分离 */
    pthread_detach(pthread_self());

    const char *str = "world";
    printer(str);

    /* 线程退出 */
    pthread_exit(NULL);
}

int main()
{
    /* 初始化信号量 */
    int initVal = 1;
    sem_init(&g_sem, 0, initVal);

    pthread_t tid1;
    int ret = pthread_create(&tid1, NULL, thread_func1, NULL);
    if (ret != 0)
    {
        perror("thread create error!");
        _exit(-1);
    }

    pthread_t tid2;
    ret = pthread_create(&tid2, NULL, thread_func2, NULL);
    if (ret != 0)
    {
        perror("thread create error!");
        _exit(-1);
    }

    int cnt = 60;
    while (cnt--)
    {
        sleep(1);
    }

    /* 销毁信号量 */
    sem_destroy(&g_sem);

    return 0;
}