#include "threadpool.h"
#include <cstring>
#include <unistd.h>
#define DEFAULT_MIN_THREADS 3
#define DEFAULT_MAX_THREADS 8

/* 管理者线程函数 */
void *manageThreadFunc(void *arg)
{
    pthread_detach(pthread_self());
    pthread_exit(NULL);
}

/* 工作者线程 */
void *workThreadFunc(void *arg)
{
    /* 线程分离 */
    pthread_detach(pthread_self());

    ThreadPool *pool = static_cast<ThreadPool *>(arg);

    /* 核心目的: 队列中取任务、处理 */
    while (true)
    {
        /* 加锁 */
        pthread_mutex_lock(&(pool->m_mutex));

        /* 队列中查找 */
        while (pool->m_queueSize == 0)
        {
            pthread_cond_wait(&(pool->m_queueNotEmpty), &(pool->m_mutex));
        }

        /* 从任务队列中取出数据 */
        Task_t newTask;
        newTask.function = pool->m_queue[pool->m_queueFront].function;
        newTask.arg = pool->m_queue[pool->m_queueFront].arg;

        /* 移动队头位置 */
        pool->m_queueFront = (pool->m_queueFront + 1) % pool->m_queueCapacity;
        /* 任务队列的任务数减 1 */
        pool->m_queueSize--;

        /* 解锁 */
        pthread_mutex_unlock(&(pool->m_mutex));

        /* 加锁2 */
        pthread_mutex_lock(&(pool->m_busyMutex));
        /* 忙碌线程 */
        pool->m_busyThreadNums++;
        /* 处理任务 */
        newTask.function(newTask.arg);
        /* 处理任务结束闲置 */
        pool->m_busyThreadNums--;
        /* 解锁2 */
        pthread_mutex_unlock(&(pool->m_busyMutex));
        pthread_cond_signal(&(pool->m_queueNotFull));
    }

    /*  */
    pthread_exit(NULL);
}

ThreadPool::ThreadPool(int minThreads, int maxThreads, int maxQueueCapacity)
{
    if (minThreads <= 0 || maxThreads <= 0)
    {
        minThreads = DEFAULT_MIN_THREADS;
        minThreads = DEFAULT_MAX_THREADS;
    }

    m_minThreadsNums = minThreads;
    m_maxThreadsNums = maxThreads;
    m_queueCapacity = maxQueueCapacity;

    /* 任务队列初始化 */
    m_queue = new Task_t[m_queueCapacity];
    if (m_queue == nullptr)
    {
        perror("queue new error.");
        /* 进程退出 */
        _exit(-1);
    }
    /* 情况脏数据 */
    memset(m_queue, 0, sizeof(Task_t) * m_queueCapacity);

    /* 队列的属性 */
    this->m_queueCapacity = 0;
    this->m_queueFront = 0;
    this->m_queueTail = 0;

    /* 线程池创建 */
    this->m_threads = new pthread_t[m_maxThreadsNums];
    if (m_threads == nullptr)
    {
        perror("threads new error");
        /* 进程推出 */
        _exit(-1);
    }
    /* 清空脏数据 */
    memset(m_threads, 0, sizeof(pthread_t) * m_maxThreadsNums);

    /* 启动管理者线程 */
    int ret = pthread_create(&(this->manageThread), NULL, manageThreadFunc, this);
    if (ret == -1)
    {
        perror("manageThread create error.");
        _exit(-1);
    }

    /* 忙碌的线程数 */
    this->m_busyThreadNums = 0;
    /* 存活的线程数 */
    this->m_aliveThreadsNums = 0;
    /* 创建最小数量线程 */
    for (int idx = 0; idx < m_minThreadsNums; idx++)
    {
        ret = pthread_create(&m_threads[idx], NULL, workThreadFunc, this);
        if (ret == -1)
        {
            perror("workThread create error.");
            _exit(-1);
        }
        /* 存活的线程数加 1 */
        m_aliveThreadsNums++;
    }

    /* 初始化🔒 */
    pthread_mutex_init(&m_mutex, NULL);
    /* 初始化锁2 */
    pthread_mutex_init(&m_busyMutex, NULL);
    /* 初始化条件变量 */
    pthread_cond_init(&m_queueNotEmpty, NULL);
    pthread_cond_init(&m_queueNotFull, NULL);
}

ThreadPool::~ThreadPool()
{
    /* 毁锁 */
    pthread_mutex_destroy(&m_mutex);
    pthread_mutex_destroy(&m_busyMutex);
    /* 释放条件变量 */
    pthread_cond_destroy(&m_queueNotEmpty);
    pthread_cond_destroy(&m_queueNotFull);
}

void ThreadPool::addTask(void *(*function)(void *arg), void *arg)
{
    /* 将任务添加到任务队列 */

    /* 上锁 */
    pthread_mutex_lock(&(this->m_mutex));

    while (this->m_queueSize == this->m_queueCapacity)
    {
        pthread_cond_wait(&(this->m_queueNotFull), &(this->m_mutex));
    }

    this->m_queue[m_queueTail].function = function;
    this->m_queue[m_queueTail].arg = arg;

    this->m_queueTail = (this->m_queueTail + 1) % m_queueCapacity;
    /* 任务数量加1 */
    this->m_queueSize++;

    /* 解锁 */
    pthread_mutex_unlock(&this->m_mutex);
    /* 发信号 */
    pthread_cond_signal(&(this->m_queueNotEmpty));
}