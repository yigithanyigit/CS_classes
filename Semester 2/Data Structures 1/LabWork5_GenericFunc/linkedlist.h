#include <stdlib.h>

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s
{
	LINKED_LIST_NODE next; /*Do not change the order.*/
	void *data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s
{
	LINKED_LIST_NODE head; /*May overlap with next.*/
} LINKED_LIST_t[1];

LINKED_LIST linked_list_init()
{
	LINKED_LIST list;
	list = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
	if (list != NULL)
	{
		list->head = NULL;
	}
	return list;
}

void linked_list_free(LINKED_LIST list)
{
	free(list);
}

void linked_list_prepend(LINKED_LIST list, void *data)
{
	return;
}

void linked_list_append(LINKED_LIST list, void *data)
{
	return;
}

int linked_list_insert(LINKED_LIST list, void *data, int idx)
{
	LINKED_LIST_NODE node, prev;
	int i;
	node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	if (node != NULL)
	{
		i = 0;
		node->data = data;
		prev = list->head;
		if (idx > 0 && prev != NULL)
		{
			i = i + 1;
			while (i < idx && prev->next != NULL)
			{
				prev = prev->next;
				i++;
			}
			node->next = prev->next;
			prev->next = node;
		}
		else
		{
			node->next = list->head;
			list->head = node;
		}
		return i;
	}
	else
	{
		return -1;
	}
}

void linked_list_set(LINKED_LIST list, void *data, int idx)
{
	return;
}

void *linked_list_get(LINKED_LIST list, int idx)
{
	LINKED_LIST_NODE temp = list->head;
	int temp_idx = idx;
	while (0 <= temp_idx)
	{
		temp = temp->next;
		temp_idx--;
	}
	printf("%d ", temp->data);
	return temp;
}

void *linked_list_remove(LINKED_LIST list, int idx)
{
	LINKED_LIST_NODE temp = list->head;
	int i;
	if (idx == 0)
	{
		list->head = list->head->next;
		temp->next = NULL;
		free(temp);
		return temp;
	}
	else
	{
		for (i = 0; i < idx - 1; i++)
		{
			temp = temp->next;
		}

		LINKED_LIST_NODE del = temp->next;
		temp->next = temp->next->next;
		del->next = NULL;
		return del;
	}
}

void linked_list_removeall(LINKED_LIST list)
{
	return;
}

void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2)
{
	return;
}

