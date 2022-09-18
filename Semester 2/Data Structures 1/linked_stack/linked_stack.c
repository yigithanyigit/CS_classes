#include <stdio.h>
#include "linked_stack_mine.h"

LINKED_STACK linked_stack_init()
{
    LINKED_STACK stack = NULL;
    stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_NODE_t));
    if (stack != NULL)
    {
        stack->head = NULL;
    }
    return stack;
}

int linked_stack_push(LINKED_STACK stack, void *data)
{
    LINKED_STACK_NODE node = NULL;
    node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
    if (node != NULL)
    {
        node->data = data;
        node->next = stack->head;
        stack->head = node;
        return 1;
    }
    return 0;
}

void *linked_stack_pop(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    void *res;

    if (stack->head != NULL)
    {
        node = stack->head;
        res = node->data;
        stack->head = node->next;
        free(node);
    }

    return res;
}

void linked_stack_free(LINKED_STACK stack)
{
    free(stack);
}

int main(int argc, char const *argv[])
{

    return 0;
}
