#include <stdio.h>
//计が传猭
void dispBits(unsigned char val)
{
    int i;
    unsigned char mask = 1 << 7;
    for (i=0; i<8; i++)
    {
        if ((mask & val) != 0) printf("1");
        else printf("0");
        mask = mask >> 1;
    }
    printf("\n");
}
int main()
{
    unsigned char a, b, x, y;
    a = 4;
    b = 6;
    printf("a: ");
    dispBits(a);
    printf("b: ");
    dispBits(b);
    printf("a=%d, b=%d\n", a, b);

    a = a ^ b;
/*
    a: 100
    b: 110
    a: 010 a=a^b
*/
    b = a ^ b;
/*
    a: 010 a=a^b
    b: 110
    b: 100 b=(a^b)^b = a
*/
    a = a ^ b;
/*
    a: 010 a=a^b
    b: 100
    a: 110 a = [(a^b)^b] ^ (a^b) = [a] ^ (a^b) = b
*/
    //硓筁硂︽笷Θabが传
    printf("\na: ");
    dispBits(a);
    printf("b: ");
    dispBits(b);
    printf("a=%d, b=%d\n", a, b);
    /*
    a: 100
    b: 110
    a: 010
    */

    //ヴ计常Θ
    x = 123;
    y = 84;
    printf("x: ");
    dispBits(x);
    printf("y: ");
    dispBits(y);
    printf("x=%d, y=%d\n", x, y);
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("x: ");
    dispBits(x);
    printf("y: ");
    dispBits(y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
