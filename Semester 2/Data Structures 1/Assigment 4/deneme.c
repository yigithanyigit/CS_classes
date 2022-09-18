#include <stdlib.h>
#include "linked_queue.h"

typedef struct MQUEUE_s
{
    LINKED_QUEUE queues;
    char **queue_names;
    int queue_count;

} MQUEUE_t[1], *MQUEUE;

int mqueue_init()
{
    MQUEUE q = NULL;
    q = malloc(sizeof(MQUEUE_t));
    if (q != NULL)
    {
        q->queue_count = 0;
        q->queue_names = malloc(sizeof(char * ));
        q->queues = malloc(sizeof(LINKED_QUEUE_t));
    }
    
    return q;
}


int main()
{
    MQUEUE mq = mqueue_init();
    for (int i = 0; i < 10; i++)
    {
        LINKED_QUEUE q = linked_queue_init();
        mq->queues = realloc(mq->queues ,sizeof(LINKED_QUEUE_t) * (mq->queue_count + 1));
        mq->queues[mq->queue_count] = *q;
        mq->queue_count += 1;
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", mq->queues[i]);
    }
    

    return 0;
}