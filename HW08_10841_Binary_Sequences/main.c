#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main()
{
    int n;
    scanf("%d", &n);
    list(n, n, 0, 2*n);
    return 0;
}
