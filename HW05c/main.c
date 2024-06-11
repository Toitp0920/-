#include <stdio.h>
int main()
{
        unsigned int m, n;
        int i, j;
        int M[101][101]={0};

        scanf("%u %u", &m, &n);

        for(i=0; i<m; i++)
        {
                for(j=0; j<n; j++)
                        scanf("%d", &M[i][j]);
        }

        for(i=0; i<m; i++)
        {
                for(j=0; j<n; j++)
                {
                        if(M[i][j]!=0)
                        {
                                printf("%d %d %d\n", i, j, M[i][j]);
                        }
                }
        }


        return 0;
}
