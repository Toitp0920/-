#include <stdio.h>
int main()
{
    double data[101];
    double* p[101];
    int i, a, b, n;
    double x;
    freopen("input.txt", "r", stdin);

    for (i=0; i<101; i++)
        p[i] = &data[i];

    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        p[a]=p[b];
    }

    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d%lf", &a, &x);
        *p[a] = x;
    }
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        printf("%.2f\n", *p[a]);
    }


    return 0;
}
