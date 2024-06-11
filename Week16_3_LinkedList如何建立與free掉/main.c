#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int x;
    struct _node *next;
} Node;
/*

head|x|next|
        |
        V
        |x|next|
             |
             V
        np-> |x|next|

              */
int main(void)
{
    Node head;
    Node *np, *nq;
    int i;

    head.x = 0;
    head.next = (Node *) malloc(sizeof(Node));
    np = head.next;
    i = 1;
    while (i < 10)
    {
        np->x = i;
        np->next = (Node *) malloc(sizeof(Node));
        np = np->next;
        i++;
    }
    np->x = i;
    np->next = NULL;
//顯示linked list 每個節點(node)的內容內容
    np = head.next; //回到第一層
    while (np!=NULL)
    {
        printf("%d\n", np->x);
        np = np->next;
    }
//free linked list 中的每個node
    np = head.next; //回到第一層
    while (np!=NULL)
    {
        nq = np;
        np = np->next;
        free(nq);
        /*
        基本的原則就是：
        1.不要亂free
        2.free完的東西不要使用
        */
    }
    /*
    這是把struct串在一起基本的方法
    稱為linked list
    */

    np = head.next; //回到第一層
    while (np!=NULL)
    {
        printf("%d\n", np->x);
        np = np->next;
    }
    return 0;
}
