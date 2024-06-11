#include <stdio.h>
int last (int , int , int);
int n_sum(int, int ,int);

int main(void)
{
    printf("%d %d",  last(3, 2, 9) , n_sum(3, 2, 9));
    return 0 ;
}

int last(int a, int n , int d)
{
    return a + (n-1)*d;
}
int n_sum(int a, int n ,int d)
{
    return (a + a+(n-1)*d)*n/2;
}
