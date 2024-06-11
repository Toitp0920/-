#include <stdio.h>
//¤T¨¤§Î1
int main(void)
{
    int i, j;

    i = 1;
    while (i<=9) {
        //printf("i=%d: ", i);
        j = 1;
        while (j<=i) {
            printf("%2d ", i*j);
            j++;
        }
        printf("\n");
        i++;
    }


    return 0;
}
