#include <stdio.h>
#include"function.h"
void filling(int amount, int cur, int n)
{
        if(cur<n)
        {
                if(amount==0)
                {
                        int i;
                        printf("(%d", numbers[0]);
                        for(i=1; i<n; i++)
                                printf(",%d", numbers[i]);
                        printf(")\n");
                }
                else if(amount>0)
                {
                        numbers[cur]++;
                        filling(amount-liters[cur], cur, n);
                        numbers[cur]--;
                        filling(amount, cur+1, n);
                }
        }
}
