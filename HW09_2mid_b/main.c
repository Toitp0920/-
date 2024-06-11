#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main()
{
    freopen("10846_sampleIn.txt", "r", stdin);
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 0; ; j++)
        {
            scanf("%d", &NPClist[i][j]);
            if (NPClist[i][j] == 0) break;
        }
    }
    /*
    for (i = 1; i <= n; i++)
    {
        for (j = 0;j<10 ; j++)
        {
            printf(" %d", NPClist[i][j]);
        }
        printf("\n\n");
    }
    */
    findNPC(1);
    return 0;
}
