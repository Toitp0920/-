/*
當兩個變量要一起看待時
*/
#include <stdio.h>
#include <stdlib.h>
//(x,y)為一個點
/*
    struct t_point
    {
        int x;
        int y;
    };
    typedef struct t_point Point; //從此之後Point就是一種type了
*/
//上面的內容可以精簡成：
typedef struct
{
    int x;
    int y;
} Point;

void show(Point p)
{
    printf("(%d,%d)\n", p.x, p.y);
}
int main()
{
    Point pt = {10, 5}; //寫法等同於以下
    Point * pp;
show(pt);
    pt.x = 15;
    pt.y = 20;

    show(pt); //這時pt的內容物已經被複製到這個function中了

    pp = &pt;

    (*pp).x = 100;
    (*pp).y = 200;

    show(pt);

    //可以用這個寫法唷!這裡不用加上星號了
    pp->x = 150;
    pp->y = 250;
    show(pt);

    return 0;
}
