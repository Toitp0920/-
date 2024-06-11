#include <stdio.h>
int main()
{
    int i,j;
    int x, y;
    unsigned int n;
    scanf("%u %d %d", &n, &x, &y);

    int N[8][8]= {0};

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            N[i][j]=(i-x)*(((i-x)>=0)-((i-x)<=0))
                    +(j-y)*(((j-y)>=0)-((j-y)<=0));
            printf("%3d", N[i][j]);
        }
        printf("\n");
    }

    return 0;
}
