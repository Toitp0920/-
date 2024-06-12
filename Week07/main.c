/*
10767 - Find the maximum/minimum values

Description
In this problem, you are asked to implement a program which can find the maximum element M and minimum element m of a two-dimensional array. You need to print the location difference and value difference of M and m. For example, if M is at iM-th row and jM-th column and of value rM, and m is at im-th row and jm-th column and of value rm, then the location difference and value difference of the two elements are (|iM - im| + |jM - jm|) and (|rM - rm|), respectively.

Note that in a given array, no two elements will have the same value.

HINT: You can use C library function:  int abs(int x) ,which returns the absolute value of int x.
Before using abs(), you may need to add the following code at first : #include <stdlib.h>


Input
The first line of the input contains two integer numbers R (2<=R<=10) and C (2<=C<=10).

Each of the next R lines contains C integers, specifying the elements of the two-dimensional array. All of the integers in the same line are separated by a space.


Output
The output contains two integers:  the location difference and the value difference of the maximum and minimum elements, separated by a space.

Note that you do not need to print ‘\n’ at the end of line.


Sample Input
3 3
1 3 2
4 6 5
7 9 8

Sample Output
3 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define BIG 10000000
/*     j=0     1      2      3
i=0   0     1      2      3
i=1   4     5      6      7
i=2   8     9     10    11
*/
//這是我自己寫的
int main()
{
        int i, m, n, x;
        int min=BIG, max=0;
        int minlocation, maxlocation;
        scanf("%d%d", &m, &n);
        for(i=0; i<m*n; i++)
        {
                scanf("%d", &x);
                if(x>max)
                {
                        max=x;
                        maxlocation=i/n+i%n;
                }
                if(x < min)
                {
                        min = x;
                        minlocation=i/n+i%n;
                }
        }
        printf("max=%d, min=%d\nMlocat=%d, mlocat=%d\n", max, min, maxlocation, minlocation);
        printf("%d %d", abs(minlocation-maxlocation), max-min);
        return 0;
}
