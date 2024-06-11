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
//這是老師的寫法
int main(void)
{
        int i, n, ori_n, c;
        scanf("%d", &n);
        ori_n = n;

        i = 1;
        while (i<=n) i=i*2;
        i=i/2;
        while (i>0) {
                printf("%d", n/i);
                n = n%i;
                i = i/2;
        }
        printf(" ");

        n = ori_n;
        i = 1;
        c = n % 2;

        while (i<=n) i=i*2;
        i=i/2;

        while (i>0) {
                printf("%d", (c + n/i)%2 );
                c = n/i;
                n = n%i;
                i = i/2;
        }

        return 0;
}
