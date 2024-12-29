/**
 * @file
 * @brief This file is used for testing LOCK functionality.
 */

#include <unistd.h>
#include "lockLib.h"

#define BUFFER_SIZE 10

static int buffer[BUFFER_SIZE] = {};
static int count = 0;
static LOCK rwLock = {};

void *producer(void *arg)
{
    int i = 0;
    for(i = 0; i < 100; ++ i)
    {
        LOCK_WRITE_TAKE(rwLock);
        if(count < BUFFER_SIZE)
        {
            sleep(1);
            DBG_ALZ("producer: %d", i);
            buffer[count] = i;
            count ++;
        }
        LOCK_WRITE_RELEASE(rwLock);
    }
    return NULL;
}

void *consumer(void *arg)
{
    while (1) 
    {
        LOCK_WRITE_TAKE(rwLock);
        if (count > 0) {
            int item = buffer[count - 1];
            DBG_ALZ("Consumed: %d", item);
            count--;
        }
        LOCK_WRITE_RELEASE(rwLock);
        sleep(0.5); // 模拟消费时间
    }
    return NULL;
}

int main()
{
    pthread_t producerThread = 0;
    pthread_t consumerThread = 0;
    pthread_t consumerThread1 = 0;
    struct sched_param param;

    if(RET_VAL_NO_ERROR != LOCK_INIT(rwLock))
    {
        DBG_ERR("init rwlock failed");
        return -1;
    }

    if(pthread_create(&producerThread, NULL, producer, NULL))
    {
        DBG_ERR("create producer thread failed");
        return -1;
    }

    if(pthread_create(&consumerThread, NULL, consumer, NULL))
    {
        DBG_ERR("create consumer thread failed");
        return -1;
    }

    if(pthread_create(&consumerThread1, NULL, consumer, NULL))
    {
        DBG_ERR("create consumer1 thread failed");
        return -1;
    }
    
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (pthread_setschedparam(consumerThread1, SCHED_FIFO, &param)) {
        DBG_ERR("set consumer1 thread priority failed");
        return -1;
    }

    param.sched_priority = sched_get_priority_max(SCHED_FIFO) - 1;
    if (pthread_setschedparam(consumerThread, SCHED_FIFO, &param)) {
        DBG_ERR("set consumer thread priority failed");
        return -1;
    }

    param.sched_priority = sched_get_priority_max(SCHED_FIFO) - 2;
    if (pthread_setschedparam(producerThread, SCHED_FIFO, &param)) {
        DBG_ERR("set producer thread priority failed");
        return -1;
    }

    pthread_join(consumerThread, NULL);
    pthread_join(consumerThread1, NULL);
    pthread_join(producerThread, NULL);
    
    LOCK_DESTROY(rwLock);

    return 0;
}