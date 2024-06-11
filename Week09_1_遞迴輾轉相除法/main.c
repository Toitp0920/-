/*
用遞迴(輾轉相除法)求最大公因數(GCD)
*/
#include <stdio.h>
int gcd(int a, int b);
int main()
{
        int x, y;
        scanf("%d%d", &x, &y);
        printf("gcd(%d, %d) = %d\n", x, y, gcd(x, y));
        return 0;
}

int gcd(int a, int b)
{
        if(b==0)
                return a;
        return gcd(b, a%b);
}
