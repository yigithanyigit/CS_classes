#include <string.h>
#include <time.h>
#include "linked_queue.h"

/* DEFINE THE MQUEUE HERE */
typedef struct MQUEUE_s
{
    LINKED_QUEUE queues;
    char **queue_names;
    int queue_count;

} MQUEUE_t[1], *MQUEUE;

/* IMPLEMENT THE FUNCTIONS HERE */

MQUEUE mqueue_init()
{
    MQUEUE q = NULL;
    q = malloc(sizeof(MQUEUE_t));
    if (q != NULL)
    {
        q->queue_count = 0;
        q->queue_names = malloc(sizeof(char *));
        q->queues = malloc(sizeof(LINKED_QUEUE_t));
    }

    return q;
}

int mqueue_add_queue_with_name(MQUEUE mqueue, char *queue_name)
{
    LINKED_QUEUE q = linked_queue_init();
    LINKED_QUEUE temp_queues = realloc(mqueue->queues , sizeof(LINKED_QUEUE_t) * (mqueue->queue_count + 1));
    char **temp_queue_names = realloc(mqueue->queue_names, sizeof(char *) * (mqueue->queue_count + 1));
    printf("%p %p %p \n", q, temp_queues, temp_queue_names);
    if (q && temp_queues && temp_queue_names != NULL)
    {
        mqueue->queues = temp_queues;
        mqueue->queue_names = temp_queue_names;
        mqueue->queues[mqueue->queue_count] = *q;
        //strcpy(mqueue->queue_names[mqueue->queue_count], queue_name);
        mqueue->queue_names[mqueue->queue_count] = queue_name;
        printf("%s ", mqueue->queue_names[mqueue->queue_count]);
        mqueue->queue_count++;
        printf("1\n");
        return 1;
    }
    else
    {
        printf("0\n");
        return 0;
    }
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
            printf("debug-EU");
            mqueue_enqueue_with_name(mqueue, "EU Passport Control", data);
            printf("Citizen %d\t enters to \tEU Passport Control\n", *data);
        }
        else if (rnd < 60)
        {
            printf("debug-NON-EU");
            mqueue_enqueue_with_name(mqueue, "Non-EU Passport Control", data);
            printf("Citizen %d\t enters to \tNon-EU Passport Control\n", *data);
        }
        rnd = rand() % 100;
        if (rnd < 30)
        {
            printf("debug-EU");
            data = mqueue_dequeue_with_name(mqueue, "EU Passport Control");
            if (data != NULL)
            {
                printf("Citizen %d\t exits \t\tEU Passport Control\n", *data);
            }
        }
        else if (rnd < 50)
        {
            printf("debug-NON-EU");
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

    // mqueue_free(mqueue);

    return 0;
}
