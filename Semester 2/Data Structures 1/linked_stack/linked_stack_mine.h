#include <stdlib.h>

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;

typedef struct LINKED_STACK_NODE_s
{
    LINKED_STACK_NODE next;
    void *data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s
{
    LINKED_STACK_NODE head;
}LINKED_STACK_t[1], *LINKED_STACK;



LINKED_STACK linked_stack_init();
int linked_stack_push(LINKED_STACK stack, void* data);
void* linked_stack_pop(LINKED_STACK stack);
void linked_stack_free(LINKED_STACK stack);

