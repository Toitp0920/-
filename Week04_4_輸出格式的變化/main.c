#include <stdio.h>
#include <string.h>
#define STAR "**********"
int main()
{
    int i = 1 , j = 0;
    while ( i <= strlen(STAR) )
    {
        printf("%.*s\n", i++, STAR);
        j = 0;
        while(j< 500000000) j++;
    }
    return 0;
}
