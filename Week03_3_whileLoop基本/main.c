#include <stdio.h>
int main()
{
    int n, x;
    int i, sum;

    int a[50];
    printf("how many numbers ?(n<50) :");
    scanf("%d", &n);

    i = 0;
    while(i<n)
    {
        printf("enter a[%d] :", i);
        scanf("%d", &x);
        a[i] = x;
        i++;
    }
    i = 0;
    sum = 0;
    printf("summation is : ");
    while(i<n)
    {
            printf("%d + ", a[i]);
            sum = sum + a[i];
            i++;
    }
    printf("\b\b= %d", sum);


    return 0;
}
