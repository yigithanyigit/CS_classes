#include<stdlib.h>

typedef struct DLINKED_LIST_NODE_s *DLINKED_LIST_NODE;
typedef struct DLINKED_LIST_NODE_s{
	DLINKED_LIST_NODE next; /*Do not change the order.*/
	DLINKED_LIST_NODE prev;
	void *data;
} DLINKED_LIST_NODE_t[1];

typedef struct DLINKED_LIST_s *DLINKED_LIST;
typedef struct DLINKED_LIST_s{
	DLINKED_LIST_NODE head; /*May overlap with next.*/
} DLINKED_LIST_t[1];

DLINKED_LIST dlinked_list_init()
{
	return NULL;
}

void dlinked_list_free(DLINKED_LIST list)
{
}

int dlinked_list_prepend(DLINKED_LIST list, void *data)
{
}

int dlinked_list_append(DLINKED_LIST list, void *data)
{
}

int dlinked_list_insert(DLINKED_LIST list, void *data, int idx)
{
	DLINKED_LIST_NODE node, curr;
	int i;
	node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	if(node != NULL) {
		i = 0;
		node->data = data;
		curr = list->head;
		if(idx>0 && curr!=NULL) {
			i = i + 1;
			while(i<idx && curr->next!=NULL) {
				curr = curr->next;
				i++;
			}
			node->next = curr->next;
			curr->next = node;
			node->prev = curr;
			node->next->prev = node;
		}
		else {
			node->next = list->head;
			list->head = node;
			node->prev = NULL;
		}
		return i;
	} else {
		return -1;
	}
}

int dlinked_list_set(DLINKED_LIST list, void *data, int idx)
{
}

void *dlinked_list_get(DLINKED_LIST list, int idx)
{
}

void *dlinked_list_remove(DLINKED_LIST list, int idx)
{
	DLINKED_NODE curr, node;
	int i;
	void *data;
	data = NULL;
	i = 1;
	curr = list->head;
	if(idx > 0) {
		if(curr != NULL) {
			while(curr->next != NULL && i<idx){
				curr = curr->next;
				i++;
			}
			if(curr->next != NULL) {
				node = curr->next;
				node->next->prev = curr;
				curr->next = node->next;
				data = node->data;
				free(node);
			}
		}
	}
	else {
		node = list->head;
		node->next->prev = NULL;
		list->head = node->next;
		data = node->data;
		free(node);
	}
	return data;
}

void dlinked_list_removeall(DLINKED_LIST list)
{
}



int dlinked_list_size(DLINKED_LIST list)
{
	DLINKED_NODE curr;
	int size;
	size = 0;
	curr = list->head;
	while(curr != NULL) {
		size = size + 1;
		curr = curr->next;
	}
	return size;
}















