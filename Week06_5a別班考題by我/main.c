#include <stdio.h>
/*
Description
Convert a decimal integer into its binary representation.
For each bit in the binary representation, flip it if its left bit is 1 and keep it unchanged if its left bit is 0.
The leftmost bit should refer to the rightmost bit and uses the same rule to decide if it needs to flip.

Example:

11 -> 1011

1011 -> 0110

Input
The input consists of an integer N (2 <= N <= 1024)

Output
The binary representation of N and the result of flipping. Note that you do not need to print ‘\n’ at the end of the output.

Sample Input
11
Sample Output
1011 0110
*/
//這是我的寫法：
int main()
{
        int a[12]={0};
        int n;
        int i, d, a0;

        scanf("%d", &n);

        i=0;
        d=0;
        while(n>0)
        {
                a[i]=n%2;
                n=n/2;
                i++;
                d++;
        }
        for(i=d-1; i>=0; i--)
                printf("%d", a[i]);
        a0=a[0];
        for(i=0; i<d; i++)
        {
                if(a[i+1])
                {
                        if(a[i])
                                a[i]=0;
                        else
                                a[i]=1;
                }
                //printf("a[d-1]=%d", a[d-1]);
        }
        if(a0)
                {
                        if(a[d-1])
                                a[d-1]=0;
                        else
                                a[d-1]=1;
                }
        printf(" ");
        for(i=d-1; i>=0; i--)
                printf("%d", a[i]);

        return 0;
}

