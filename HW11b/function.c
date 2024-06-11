#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int sort(const void *a, const void *b)
{
    Grade s = *(Grade*)a;
    Grade t = *(Grade*)b;
    if (s.total < t.total) return 1;
    else if (s.total > t.total) return -1;
    else
    {
        if (s.Chinese < t.Chinese) return 1;
        else if (s.Chinese > t.Chinese) return -1;
        else
        {
            if (s.English < t.English) return 1;
            else if (s.English > t.English) return -1;
            else
            {
                if (s.math < t.math) return 1;
                else if (s.math > t.math) return -1;
                else
                {
                    if (s.science < t.science) return 1;
                    else if (s.science < t.science) return -1;
                    else
                    {
                        if (s.ID < t.ID) return -1;
                        else if (s.ID > t.ID) return 1;
                    }
                }
            }
        }
    }

}

void sortGrade(Grade *gList, int n)
{
    int i;
    for(i=0; i<n; i++)
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    qsort(gList, n, sizeof(Grade), sort);
}
