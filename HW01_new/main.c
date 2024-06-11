#include <stdio.h>
int Nth(int, int, int );
int Ans(int, int, int );

int main()
{
    int a, n, d ;
    scanf("%d %d %d", &a, &n, &d);

    Ans(a, n, d);

    return 0;
}

int Nth(int a, int n, int d)
{
    return a+(n-1)*d;
}

int Ans(int a, int n, int d)
{
    printf("%d %d", Nth(a, n, d), (a+Nth(a, n, d))*n/2);
    return 0;
}

