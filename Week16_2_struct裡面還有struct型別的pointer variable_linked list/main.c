/*
當struct裡面還有自己型別的指標變數
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int x;
    struct _node *next;
} Node;

int main(void)
{
    Node head;

    head.x = 0;
    head.next = NULL;

    head.next = (Node *) malloc(sizeof(Node));

    (head.next)->x = 1;
    (head.next)->next = NULL;

    (head.next) -> next = (Node *) malloc(sizeof(Node));
    ((head.next)->next)->x = 30;
    ((head.next)->next)->next = NULL;
    printf("%d %d %d\n", head.x, (head.next)->x, ((head.next)->next)->x);

    free(head.next);

    return 0;
}
/*
           x = 0
Node head<        x = 1
           next <        x = 30
                  next <
                         NULL
*/
