#include <stdio.h>
int length_greater_than_one(char c, int length, int n)
{
        int i, j, t;
        for(t=1; t<=n; t++)
        {
                for(i=1; i<=length; i++)
                {
                        for(j=1; j<=i; j++)
                                printf("%c", c);
                        printf("\n");
                }
                for(i=length-1; i>=2; i--)
                {
                        for(j=1; j<=i; j++)
                                printf("%c", c);
                        printf("\n");
                }
        }





        return 0;
}
