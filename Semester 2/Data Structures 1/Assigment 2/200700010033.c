#include <stdio.h>
#include "linkedstack.h"

int main()
{
    char *text = "while(c[ i ]==pow( a , b  )) { i ++;}";
    int i;
    LINKED_STACK stack = linked_stack_init();
    for (i = 0; *(text + i) != '\0'; i++)
    {
        if (*(text + i) == '(' || *(text + i) == '[' || *(text + i) == '{')
        {
            linked_stack_push(stack, text + i);
            // printf("%c", *(text + i));
        }
        else if (*(text + i) == ')' || *(text + i) == ']' || *(text + i) == '}')
        {
            char *ch = NULL;
            ch = (char *)linked_stack_pop(stack);
            if (ch == NULL)
            {
                printf("%d ", 0);
                return 0;
            }
            else if (*(text + i) == ')' && *ch == '(')
            {
                // printf("%c", *(text + i));
            }
            else if (*(text + i) == ']' && *ch == '[')
            {
                // printf("%c", *(text + i));
            }
            else if (*(text + i) == '}' && *ch == '{')
            {
                // printf("%c", *(text + i));
            }
        }
    }
    if (stack->head == NULL)
    {
        printf("%d ", 1);
        return 1;
    }
    printf("%d ", 0);
    return 0;
}