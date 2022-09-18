#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

int main(int argc, char const *argv[])
{
    LINKED_LIST list;
    list = linked_list_init();
    LINKED_LIST piece;
    piece = linked_list_init();
    if (list && piece != NULL)
    {
        int arr[] = {12, 99, 37, 52, 80, 23};
        // int arr1[] = {12, 52, 80, 23};
        // int arr2[] = {99, 37};
        size_t i;
        for (i = 0; i < sizeof(arr) / sizeof(int); i++)
        {

            // linked_list_append(list, arr[i]);
            linked_list_insert(list, arr[i], i);
        }
        /*
        for (i = 0; i < sizeof(arr2) / sizeof(int); i++)
        {

            // linked_list_append(list, arr[i]);
            linked_list_insert(piece, arr2[i], i);
        }
        */
        // linked_list_insert_piece(list, piece, 1);
        linked_list_trim(list, 1, 2);
        // list = linked_list_slice(list, 2, 4);
        //  linked_list_print_all_int(linked_list_slice(list, 2, 4));
        linked_list_print_all_int(list);
    }

    return 0;
}
