/*
�����ܶq�n�@�_�ݫݮ�
*/
#include <stdio.h>
#include <stdlib.h>
//(x,y)���@���I
/*
    struct t_point
    {
        int x;
        int y;
    };
    typedef struct t_point Point; //�q������Point�N�O�@��type�F
*/
//�W�������e�i�H��²���G
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
    Point pt = {10, 5}; //�g�k���P��H�U
    Point * pp;
show(pt);
    pt.x = 15;
    pt.y = 20;

    show(pt); //�o��pt�����e���w�g�Q�ƻs��o��function���F

    pp = &pt;

    (*pp).x = 100;
    (*pp).y = 200;

    show(pt);

    //�i�H�γo�Ӽg�k��!�o�̤��Υ[�W�P���F
    pp->x = 150;
    pp->y = 250;
    show(pt);

    return 0;
}
