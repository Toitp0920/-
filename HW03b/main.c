#include <stdio.h>
int main()
{
        unsigned int x, y;
        unsigned int xarray[32]= {0}, yarray[32]= {0} ;
        int i;
        freopen("10097_sampleIn.txt", "r", stdin);
        freopen("answer.txt", "w", stdout);

        scanf("%u %u", &x, &y);

        i = 0;
        while(x)
        {
                xarray[i] = x%3;
                x=x/3;
                i++;
        }

        while(y)
        {
                y--;
                printf("%d", xarray[y]);
        }
        printf("\n");
        return 0;
}
