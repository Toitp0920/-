#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10840_sampleIn.txt", "r", stdin);
#endif
    char str[5000];
    while (EOF != scanf ("%s", str))
    {
        char *start = str;
        char *end = start + strlen (str) - 1;
        if (isPalindrome (start, end))
        {
            printf ("Yes\n");
        }
        else
        {
            printf ("No\n");
        }
    }
}
