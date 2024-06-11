#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void sortArray(int R, int (*array)[COLUMN])
{
    int tmp, i, j, k;
    for (k=0; k<COLUMN; k++)
    {
        for (i=0; i<R; i++)
        {
            j = i;
            tmp = array[j][k];
            while (j>0 && tmp<array[j-1][k])
            {
                array[j][k] = array[j-1][k];
                j--;
            }
            array[j][k] = tmp;
        }
    }
}

