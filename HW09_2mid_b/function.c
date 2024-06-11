#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void findNPC(int num)
{
    int j;
    if (num == 1)
        printf("%d\n", num);


    for (j=0; j<10; j++)
    {
        if (NPClist[num][j]!=0)
        {
            printf("%d\n", NPClist[num][j]);
            findNPC(NPClist[num][j]);
        }
    }
}
