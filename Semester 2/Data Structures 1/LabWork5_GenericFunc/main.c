#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

void bubble_sort(LINKED_LIST list, int (*compare)(void *, void *))
{
    int pass, count, flag = 0;
    while (!flag)
    {
        flag = 0;
        LINKED_LIST_NODE n = list->head;
        while (n->next != NULL)
        {
            if ((*compare)(n->data, n->next->data) > 0)
            {
                swap(&n, &n->next);
                flag = 1;
            }
            n = n->next;
        }
    }
    return;
}

void swap(LINKED_LIST_NODE n1, LINKED_LIST_NODE n2)
{
    LINKED_LIST_NODE temp = n2->next;
    n2->next = n1;
    n1->next = temp;
}

// Referenced From https://nachtimwald.com/2018/11/27/general-comparison-functions-in-c/
int compare_int(const void *x, const void *y)
{
    int ax = (int *)x;
    int ay = (int *)y;
    if (ax == ay)
        return 0;
    if (ax > ay)
        return 1;
    return -1;
}

int compare_str(void *x, void *y)
{
    return strcmp(x, y);
}

int compare_float(const void *x, const void *y)
{
    float ax = *(float *)x;
    float ay = *(float *)y;

    if (ax == ay)
        return 0;
    if (ax > ay)
        return 1;
    return -1;
}

void print_all_int(LINKED_LIST list)
{
    LINKED_LIST_NODE n = list->head;
    while (n != NULL)
    {
        printf("%d ", (int *)n->data);
        n = n->next;
    }
}

int main()
{
    float float_array[] = {3.544, 5.544, 6.544, 7.544};
    LINKED_LIST list = linked_list_init();
    LINKED_LIST float_list = linked_list_init();
    LINKED_LIST str_list = linked_list_init();
    linked_list_insert(list, (int *)3, 0);
    linked_list_insert(list, (int *)1, 1);
    linked_list_insert(list, (int *)2, 2);
    linked_list_insert(list, (int *)35, 3);

    linked_list_insert(list, "asdasdddsa", 0);
    linked_list_insert(list, "deneme", 1);
    linked_list_insert(list, "asdasd3344", 2);
    linked_list_insert(list, "qeweqw", 3);
    bubble_sort(list, compare_str);
    bubble_sort(list, compare_int);

    return 0;
}
