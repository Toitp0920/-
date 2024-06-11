#include <stdio.h>
#include <stdlib.h>
#include "function.h"
 findNPC(int num)
{
    int j;
    printf("%d\n", num);
    j = 0;
    while (NPClist[num][j]!=0) {
        findNPC(NPClist[num][j]);
        j++;
    }
}
