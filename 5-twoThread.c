#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t g_mutex;
pthread_cond_t g_cond;
int turn = 0;

void *printA(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&g_mutex);

        while (turn != 0)
        {
            pthread_cond_wait(&g_cond, &g_mutex);
        }

        usleep(500000);

        fprintf(stdout, "A");
        fflush(stdout);
        turn = 1;

        pthread_cond_signal(&g_cond);
        pthread_mutex_unlock(&g_mutex);
        // usleep(500000); // 休眠0.1秒，使输出更易观察
    }
    pthread_exit(NULL);
}

void *printB(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&g_mutex);

        while (turn != 1)
        {
            pthread_cond_wait(&g_cond, &g_mutex);
        }

        usleep(500000);

        fprintf(stdout, "B");
        fflush(stdout);
        turn = 0;

        pthread_cond_signal(&g_cond);
        pthread_mutex_unlock(&g_mutex);
        // usleep(500000); // 休眠0.1秒，使输出更易观察
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_A, thread_B;

    /* 初始化锁 */
    pthread_mutex_init(&g_mutex, NULL);
    /* 初始化条件变量 */
    pthread_cond_init(&g_cond, NULL);

    int ret = pthread_create(&thread_A, NULL, printA, NULL);
    if (ret != 0)
    {
        perror("线程A创建失败!");
        _exit(-1);
    }

    ret = pthread_create(&thread_B, NULL, printB, NULL);
    if (ret != 0)
    {
        perror("线程B创建失败");
        _exit(-1);
    }

    if (pthread_join(thread_A, NULL) != 0)
    {
        perror("join thread_A error");
        exit(-2);
    }

    if (pthread_join(thread_B, NULL) != 0)
    {
        perror("join thread_B error");
        exit(-2);
    }

    pthread_mutex_destroy(&g_mutex);
    pthread_cond_destroy(&g_cond);

    return 0;
}