#include <stdio.h>
#include <stdlib.h>
//a++與++a的差別？
int main()
{
    int a = 1, b=1;
    int aplus, plusb;

    aplus = a++;
    /*這句等同以下兩句：
    aplus = a;
    a++;
    */
    plusb = ++b;
    /*這句等於以下兩句：
    ++b;
    plusb = b;
    */
    printf("a:%d b:%d\na++:%d ++b:%d", a , b, aplus , plusb);
    return 0;
}
