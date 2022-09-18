#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int i, j, n1 = 0, n2 = 0, sum;
    struct ListNode *temp1, *temp2;
    temp1 = l1;
    temp2 = l2;
    for (i = 0, j = 1; i < 100; i++, j = j * 10)
    {
        n1 += temp1->val * j;
        printf("%d ", n1);
        n2 += temp2->val * j;
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == NULL || temp2 == NULL)
        {
            break;
        }
    }

    sum = n1 + n2;

    struct ListNode *sumArr = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cursor = sumArr;

    while (sum != 0)
    {
        struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
        a->val = sum % 10;
        printf("%d ", a->val);
        sum = sum / 10;
        cursor->next = a;
        cursor = cursor->next;
    }
    return sumArr->next;
}

int main()
{
    struct ListNode *q2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    q2->val = 3;
    q2->next = NULL;
    struct ListNode *q1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    q1->val = 4;
    q1->next = q2;
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    q->val = 2;
    q->next = q1;

    struct ListNode *r2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    r2->val = 4;
    r2->next = NULL;
    struct ListNode *r1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    r1->val = 6;
    r1->next = r2;
    struct ListNode *r = (struct ListNode *)malloc(sizeof(struct ListNode));
    r->val = 5;
    r->next = r1;

    struct ListNode *arr = addTwoNumbers(q, r);
    printf("%d", arr->val);
    printf("%d", arr->next->val);
    printf("%d", arr->next->next->val);
    return 0;
}