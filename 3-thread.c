#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int g_value = 0;
/* 定义互斥锁，防止竞争 */
pthread_mutex_t g_mutex;

void *thread_func(void *arg)
{
    pthread_mutex_lock(&g_mutex);
    for (int i = 0; i < 1000; i++)
    {
        g_value++;
    }
    pthread_mutex_unlock(&g_mutex);

    int *result = (int *)malloc(sizeof(int));
    *result = g_value;
    return (void *)result;
}

int main()
{
    pthread_t thread;
    int *pthread_result;

    pthread_mutex_init(&g_mutex, NULL);

    /* 创建线程 */
    if (pthread_create(&thread, NULL, thread_func, NULL) != 0)
    {
        fprintf(stderr, "线程创建失败\n");
        exit(-1);
    }

    if (pthread_join(thread, (void **)&pthread_result) != 0)
    {
        fprintf(stderr, "error joining thread\n");
        exit(-2);
    }

    fprintf(stdout, "最后的g_value值: %d\n", *pthread_result);

    free(pthread_result);
    pthread_mutex_destroy(&g_mutex);

    return 0;
}