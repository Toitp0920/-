#include <stdio.h>
#include <stdlib.h>
//a++�P++a���t�O�H
int main()
{
    int a = 1, b=1;
    int aplus, plusb;

    aplus = a++;
    /*�o�y���P�H�U��y�G
    aplus = a;
    a++;
    */
    plusb = ++b;
    /*�o�y����H�U��y�G
    ++b;
    plusb = b;
    */
    printf("a:%d b:%d\na++:%d ++b:%d", a , b, aplus , plusb);
    return 0;
}
