#include <stdio.h>
int main()
{
//        freopen("10759_sampleIn.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
        int i, j;
        int n, x;
        scanf("%u", &n);

        int m1[10][10]= {0};
        int m2[10][10]= {0};

        for(i = 1; i<=n; i++)
        {
                for (j = 1; j<= n; j++)
                {
                        scanf("%d", &m1[i][j]);
                }
        }
//    printf("%3d%3d%3d", m1[1][1], m1[1][2], m1[1][3]);
        /*    for(i = 1; i<=n; i++)
            {
                for (j = 1; j<= n; j++)
                {
                    printf("%d", m1[i][j] );
                }
                printf("\n");
            }
        */
        for(i = 1; i<=n; i++)
        {
                for (j = 1; j<= n; j++)
                {
                        scanf("%d", &x);
                        m2[i][j] = x;
                }
        }

        int m3[10][10] = {0};
        for(i=1;i<=n;i++)
        {
                for(j = 1; j <= n; j++)
                {
                        if(j==n)
                        {
                                m3[i][j]=m1[i][j]*(m1[i][j] <= m2[i][j]) + m2[i][j]*(m2[i][j] < m1[i][j]);
                                printf("%d", m3[i][j]);
                        }else{
                        m3[i][j]=m1[i][j]*(m1[i][j] <= m2[i][j]) + m2[i][j]*(m2[i][j] < m1[i][j]);
                        printf("%d ", m3[i][j]);
                        }
                }
                printf("\n");
        }
}
