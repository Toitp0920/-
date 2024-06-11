#include <stdio.h>
int m[21][21]= {0};
int main()
{
        unsigned int n;
        int i, j, k;
        //freopen("output.txt", "r", stdin);
        //freopen("result.txt", "w", stdout);

        scanf("%u", &n);

        for(i=1 ; i<=n ; i++)
        {
                for(j=1 ; j<=n ; j++)
                        scanf("%d", &m[i][j]);
        }
        /*
        for(i=1 ; i<=n ; i++)
        {
                for(j=1 ; j<=n ; j++)
                        printf("%5d", m[i][j]);
                printf("\n");
        }
        */

        for(k=1; k<=2*n-1; k++)
        {
                if(k<=n)
                {
                        i=k;
                        j=1;
                        while(i>0 && j<=k)
                        {
                                if(i==k)
                                {
                                        printf("%d", m[i][j]);
                                        i--;
                                        j++;
                                }
                                else
                                {
                                        printf("% d", m[i][j]);
                                        // printf("   k=%d, i=%d, j=%d", k, i, j);
                                        i--;
                                        j++;
                                }
                        }
                }
                else
                {
                        i=n;
                        j=k-n+1;
                        while(j<=n)
                        {
                                if(i==n)
                                {
                                        printf("%d", m[i][j]);
                                        i--;
                                        j++;
                                }
                                else
                                {
                                        printf(" %d", m[i][j]);
                                        i--;
                                        j++;
                                }
                        }
                }
                printf("\n");
        }

        //printf("%d", m[1][1]);

        return 0;
}
