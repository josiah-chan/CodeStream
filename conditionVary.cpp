#include <iostream>

using namespace std;

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory>

/* 线程同步 - 互斥锁 */
pthread_mutex_t g_mutex;

/* 阻塞线程 - 条件变量 */
pthread_cond_t g_cond;

/* 结点结构 */
struct Node
{
    /* 数据域 */
    int data;
    /* 指针域 */
    std::shared_ptr<Node> next;
};

/* 链表的头结点 */
// Node *g_head = NULL;
std::shared_ptr<Node> g_head = nullptr;

/* 生产者函数 */
void *handleProduce(void *arg)
{
    while (1)
    {
        int randomNum = rand() % 100 + 1;

        /* 创建一个结点 */
        // Node *newNode = static_cast<Node *>(malloc(sizeof(Node) * 1));
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        /* 结点初始化 */
        newNode->data = randomNum;

        /* 上锁 */
        pthread_mutex_lock(&g_mutex);

        /* 头插 */
        newNode->next = g_head;
        g_head = newNode;

        printf("============ produce: %lu, %d\n", pthread_self(), newNode->data);

        /* 解锁 */
        pthread_mutex_unlock(&g_mutex);

        /* 通知阻塞的消费者线程，解除阻塞, 发信号 */
        pthread_cond_signal(&g_cond);

        /* 休息 */
        usleep(800000);
    }

    pthread_exit(NULL);
}

/* 消费者函数 */
void *handleConsume(void *arg)
{
    while (1)
    {
        /* 加锁 */
        pthread_mutex_lock(&g_mutex);

        /* 这里改成while, 响应不同情形下 */
        while (g_head == NULL)
        {
            /* 没有数据, 等待生产者发出信号, pthread_cong_signal() */
            pthread_cond_wait(&g_cond, &g_mutex);

            /* 当条件变量被满足的时候，解除阻塞，并且又会对互斥锁重新加上锁 */
        }

        // Node *eatNode = g_head;
        std::shared_ptr<Node> eatNode = g_head;
        g_head = g_head->next;

        /* 解锁 */
        pthread_mutex_unlock(&g_mutex);

        cout << "============ consume: " << pthread_self() << ", " << eatNode->data << endl;
    }

    pthread_exit(NULL);
}

int main()
{
    /* 随机数种子 */
    srand(static_cast<unsigned int>(time(nullptr)));

    /* 初始化锁 */
    pthread_mutex_init(&g_mutex, NULL);
    /* 初始化条件变量 */
    pthread_cond_init(&g_cond, NULL);

    /* 生产者线程 */
    pthread_t produce;
    int ret = pthread_create(&produce, NULL, handleProduce, NULL);
    if (ret == -1)
    {
        perror("produce_thread create error");
        _exit(-1);
    }

    /* 消费者线程 */
    pthread_t consume;
    ret = pthread_create(&consume, NULL, handleConsume, NULL);
    if (ret == -1)
    {
        perror("consume_thread create error");
        _exit(-1);
    }

    /* 阻塞回收子线程资源 */
    pthread_join(produce, NULL);
    pthread_join(consume, NULL);

    pthread_mutex_destroy(&g_mutex);

    pthread_cond_destroy(&g_cond);

    return 0;
}