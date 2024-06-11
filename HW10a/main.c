#include <stdio.h>
int bac_divides(int w);
int main()
{
    int i, weeks;
    scanf("%d", &weeks);
    printf("%d\n", bac_divides(weeks));


    return 0;
}

bac_divides(int w)
{
    int ans;
    if(w==1) return 1;

    if (w <= 3) ans = 2 * bac_divides(w-1);
    else ans = (bac_divides(w-1)-w+3) * 2;

    return ans;
}
