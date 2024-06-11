#include <stdio.h>
int func1(int );
int func2(int );

int func1(int x)
{
    int w;
    printf("in func1, before func2\n");
    w = func2(x);
    printf("in func1, after func2\n");
    return w;
}
int func2(int y)
{
    printf("in func2, before printf\n");
    printf("Hello world!\n");
    printf("%d\n", y);
    printf("in func2, after printf\n");
    return y*y;
}


int main(void)
{
    int z;
    printf("in main, before func1\n");
    z = func1(5);
    printf ("%d\n", z);
    printf("in main, after func1\n");
    return 0;

}


