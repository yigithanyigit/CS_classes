typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;

typedef struct LINKED_LIST_NODE_s
{
    LINKED_LIST_NODE next;
    void *data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s
{
    LINKED_LIST_NODE head;
} LINKED_LIST_t[1];

LINKED_LIST linked_list_init();
void linked_list_free(LINKED_LIST list);
void linked_list_prepend(LINKED_LIST list, void *data);
void linked_list_append(LINKED_LIST list, void *data);
void linked_list_insert(LINKED_LIST list, void *data, int idx);
void linked_list_set(LINKED_LIST list, void *data, int idx);
void *linked_list_get(LINKED_LIST list, int idx);
void *linked_list_remove(LINKED_LIST list, int idx);
void linked_list_removeall(LINKED_LIST list);
void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2);
struct LINKED_LIST_NODE_s* linked_list_slice ( LINKED_LIST list , int start , int end );
void linked_list_insert_piece ( LINKED_LIST list , LINKED_LIST piece , int index );
void linked_list_trim ( LINKED_LIST list , int left , int right );
void linked_list_print_all_int(LINKED_LIST list);
void linked_list_insert_piece(LINKED_LIST list, LINKED_LIST piece, int index);
void linked_list_trim(LINKED_LIST list, int left, int right);
