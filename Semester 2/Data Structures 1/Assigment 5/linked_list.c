#include <stdio.h>
#include "linked_list.h"

LINKED_LIST linked_list_init()
{
    struct LINKED_LIST_s *list = NULL;
    list = malloc(sizeof(LINKED_LIST_t));
    list->head = NULL;
    return list;
}

void linked_list_free(LINKED_LIST list)
{
    free(list);
}

void linked_list_prepend(LINKED_LIST list, void *data)
{
    struct LINKED_LIST_NODE_s *new_node = NULL;
    new_node = malloc(sizeof(struct LINKED_LIST_NODE_s));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
};

void linked_list_append(LINKED_LIST list, void *data)
{
    struct LINKED_LIST_NODE_s *node = list->head;
    struct LINKED_LIST_NODE_s *new_node = NULL;
    new_node = malloc(sizeof(struct LINKED_LIST_NODE_s));

    new_node->data = data;

    new_node->next = NULL;

    if (node == NULL)
    {
        node = new_node;
    }

    while (node != NULL)
    {
        node = node->next;
    }

    node = new_node;

    return;
}

void linked_list_insert(LINKED_LIST list, void *data, int idx)
{
    struct LINKED_LIST_NODE_s *node, *prev;
    int i;
    node = malloc(sizeof(struct LINKED_LIST_NODE_s));
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
        return;
    }
    else
    {
        return;
    }
}

void linked_list_set(LINKED_LIST list, void *data, int idx)
{
    struct LINKED_LIST_NODE_s *node, *prev;
    int i;
    node = malloc(sizeof(struct LINKED_LIST_NODE_s));
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
        return;
    }
    else
    {
        return;
    }
}

void *linked_list_get(LINKED_LIST list, int idx)
{
    size_t i;
    void *res = NULL;
    struct LINKED_LIST_NODE_s *node;
    node = list->head;
    for (i = 0; i < idx; i++)
    {
        if (node == NULL)
        {
            return res;
        }
        node = node->next;
    }
    return res;
}

void *linked_list_remove(LINKED_LIST list, int idx)
{
    size_t i;
    void *res = NULL;
    struct LINKED_LIST_NODE_s *node;
    node = list->head;
    for (i = 0; i < idx; i++)
    {
        if (node == NULL)
        {

            return res;
        }
        node = node->next;
    }
    res = node->next->data;
    free(node->next);
    node->next = NULL;
    return res;
}
void linked_list_removeall(LINKED_LIST list)
{
    struct LINKED_LIST_NODE_s *node, *prev;
    node = list->head;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
        free(prev);
    }
}
void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2)
{
    struct LINKED_LIST_NODE_s *node1;
    node1 = list->head;
    while (node1->next != NULL)
    {
        node1 = node1->next;
    }
    node1->next = list2->head;
}

void linked_list_print_all_int(LINKED_LIST list)
{
    struct LINKED_LIST_NODE_s *node;
    node = list->head;
    while (node != NULL)
    {

        printf("%d ", (int *)node->data);
        node = node->next;
    }
}

struct LINKED_LIST_NODE_s *linked_list_slice(LINKED_LIST list, int start, int end)
{
    size_t i = 0, j = 0, q = 0;
    struct LINKED_LIST_s *res_list = linked_list_init();
    struct LINKED_LIST_s *initial_list = linked_list_init();
    struct LINKED_LIST_NODE_s *node, *slice_start, *slice_end;
    node = list->head;

    while (node != NULL)
    {
        if (i < start || i > end)
        {
            linked_list_insert(initial_list, node->data, j);
            j++;
        }
        else if (i >= start && i <= end)
        {
            linked_list_insert(res_list, node->data, q);
            q++;
        }
        node = node->next;
        i++;
    }
    list->head = initial_list->head;
    //linked_list_print_all_int(list);
    return res_list;
}
void linked_list_insert_piece(LINKED_LIST list, LINKED_LIST piece, int index)
{
    size_t i;
    struct LINKED_LIST_NODE_s *list_node;
    struct LINKED_LIST_NODE_s *piece_node, *piece_last;
    list_node = list->head;
    piece_node = piece->head;
    piece_last = piece->head;
    while (piece_last->next != NULL)
    {
        piece_last = piece_last->next;
    }
    for (i = 1; i < index; i++)
    {
        list_node = list_node->next;
    }
    piece_last->next = list_node->next;
    list_node->next = piece_node;
}
void linked_list_trim(LINKED_LIST list, int left, int right)
{
    size_t i = 0;
    struct LINKED_LIST_s *res_list = linked_list_init();
    struct LINKED_LIST_NODE_s *node = list->head;
    while (node != NULL)
    {
        if (i >= left && i <= left + right)
        {
            linked_list_insert(res_list, node->data, i);
        }
        i++;
        node = node->next;
    }
    list->head = res_list->head;
}
