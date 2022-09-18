#include <stdlib.h>

typedef struct LINKED_QUEUE_NODE_s *LINKED_QUEUE_NODE;
typedef struct LINKED_QUEUE_NODE_s
{
	LINKED_QUEUE_NODE next;
	void *data;
} LINKED_QUEUE_NODE_t[1];

typedef struct LINKED_QUEUE_s *LINKED_QUEUE;
typedef struct LINKED_QUEUE_s
{
	LINKED_QUEUE_NODE head;
	LINKED_QUEUE_NODE tail;
} LINKED_QUEUE_t;

LINKED_QUEUE linked_queue_init()
{
	LINKED_QUEUE queue = NULL;
	queue = (LINKED_QUEUE)malloc(sizeof(LINKED_QUEUE_t));
	//printf("QUE: %u \n", queue);
	if (queue != NULL)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	return queue;
	
	
}

void linked_queue_free(LINKED_QUEUE queue)
{
	free(queue);
}

int linked_queue_is_empty(LINKED_QUEUE queue)
{
	return 0;
}

int linked_queue_size(LINKED_QUEUE queue)
{
	return 0;
}

int linked_queue_enqueue(LINKED_QUEUE queue, void *data)
{
	LINKED_QUEUE_NODE node;
	node = (LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
		if (queue->tail == NULL)
		{
			queue->head = node;
		}
		else
		{
			queue->tail->next = node;
		}
		queue->tail = node;
		return 1;
	}
	else
	{
		return 0;
	}
}

void *linked_queue_dequeue(LINKED_QUEUE queue)
{
	LINKED_QUEUE_NODE node;
	void *data;
	if (queue->head == NULL)
	{
		return NULL;
	}
	else
	{
		if (queue->head == queue->tail)
		{
			queue->tail = NULL;
		}
		node = queue->head;
		queue->head = node->next;
		data = node->data;
		free(node);
		return data;
	}
}
