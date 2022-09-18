#include <string.h>
#include <time.h>
#include "linked_queue.h"

/* DEFINE THE MQUEUE HERE */
typedef struct
{
    int queue_count;
    char **queue_names;
    LINKED_QUEUE *queues;
} MQUEUE_t[1], *MQUEUE;

/* IMPLEMENT THE FUNCTIONS HERE */
MQUEUE mqueue_init()
{
    MQUEUE que = (MQUEUE)malloc(sizeof(MQUEUE_t));
    if (que != NULL)
    {
        que->queues = (LINKED_QUEUE *)malloc(sizeof(LINKED_QUEUE_t));
        que->queue_count = 0;
        que->queue_names = (char **)malloc(sizeof(char *));
        return que;
    }
    else
        return NULL;
}

int mqueue_add_queue_with_name(MQUEUE mqueue, char *queue_name)
{
    LINKED_QUEUE linked_que = linked_queue_init();
    LINKED_QUEUE *temp_queues = (LINKED_QUEUE *)realloc(mqueue->queues, sizeof(LINKED_QUEUE_t) * (mqueue->queue_count + 1));
    char **temp_queue_names = (char **)realloc(mqueue->queue_names, sizeof(char *) * (mqueue->queue_count + 1));
    // printf("%p %p %p \n", linked_que, temp_queues, temp_queue_names);

    if (linked_que && temp_queues && temp_queue_names != NULL)
    {
        mqueue->queues = temp_queues;
        mqueue->queue_names = temp_queue_names;
        mqueue->queues[mqueue->queue_count] = linked_que;
        mqueue->queue_names[mqueue->queue_count] = queue_name;
        mqueue->queue_count++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void mqueue_free(MQUEUE mqueue)
{
    int i;
    for (i = 0; i < mqueue->queue_count; i++)
    {
        if (mqueue->queues[i]->head != mqueue->queues[i]->tail)
        {
            while (mqueue->queues[i]->head != NULL)
            {
                linked_queue_dequeue(mqueue->queues[i]);
            }
        }
        free(mqueue->queues[i]);
    }
}

void mqueue_print(MQUEUE mqueue)
{
    int i;
    for (i = 0; i < mqueue->queue_count; i++)
    {
        printf("QUEUE NAME: %s \n", mqueue->queue_names[i]);
        LINKED_QUEUE_NODE que = mqueue->queues[i]->head;
        printf("QUEUE: ");

        while (que != NULL)
        {
            printf("%d ", *(int *)que->data);
            que = que->next;
        }
        printf("\n");
        printf("-------------- \n");
    }
}

int mqueue_enqueue_with_name(MQUEUE mqueue, char *queue_name, void *data)
{
    int i;
    for (i = 0; i < mqueue->queue_count; i++)
    {
        if (strcmp(mqueue->queue_names[i], queue_name) == 0)
        {
            linked_queue_enqueue(mqueue->queues[i], data);
            return 1;
        }
    }
    return 0;
}

void *mqueue_dequeue_with_name(MQUEUE mqueue, char *queue_name)
{
    int i;
    void *data = NULL;
    for (i = 0; i < mqueue->queue_count; i++)
    {
        if (strcmp(mqueue->queue_names[i], queue_name) == 0)
        {
            data = linked_queue_dequeue(mqueue->queues[i]);
        }
    }
    return data;
}

int main()
{
    srand(time(NULL));
    MQUEUE mqueue = mqueue_init();
    mqueue_add_queue_with_name(mqueue, "EU Passport Control");
    mqueue_add_queue_with_name(mqueue, "Non-EU Passport Control");

    int rnd, *data;
    char *names[] = {"EU Passport Control", "Non-EU Passport Control"};

    for (int i = 0; i < 30; i++)
    {

        rnd = rand() % 100;
        data = (int *)malloc(sizeof(int));
        *data = rand() % 100;

        if (rnd < 20)
        {
            mqueue_enqueue_with_name(mqueue, "EU Passport Control", data);
            printf("Citizen %d\t enters to \tEU Passport Control\n", *data);
        }
        else if (rnd < 60)
        {
            mqueue_enqueue_with_name(mqueue, "Non-EU Passport Control", data);
            printf("Citizen %d\t enters to \tNon-EU Passport Control\n", *data);
        }
        rnd = rand() % 100;
        if (rnd < 30)
        {
            data = mqueue_dequeue_with_name(mqueue, "EU Passport Control");
            if (data != NULL)
            {
                printf("Citizen %d\t exits \t\tEU Passport Control\n", *data);
            }
        }
        else if (rnd < 50)
        {
            data = mqueue_dequeue_with_name(mqueue, "Non-EU Passport Control");
            if (data != NULL)
            {
                printf("Citizen %d\t exits \t\tNon-EU Passport Control\n", *data);
            }
        }
    }
    printf("\n---------------------------\n");
    printf("\nCurrent queue lines:\n\n");
    mqueue_print(mqueue);

    mqueue_free(mqueue);

    return 0;
}
