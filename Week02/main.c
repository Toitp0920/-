#include <stdio.h>
int main(void)
{
    int m, n;
    m = 1;
    n = 1;
    m = m + n;
    n = n + m;
    printf(" m = %d, n = %d.\n", m, n);

    return 0;
}
