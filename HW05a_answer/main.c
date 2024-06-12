#include <stdio.h>
//10768 - wave
//這是老師的寫法
void triangle(char ch, int L)
{
        int i, j;
        for (i=1; i<=L; i++)
        {
                for (j=1; j<=i; j++)
                {
                        printf("%c", ch);
                }
                printf("\n");
        }
        for (i=L-1; i>=2; i--)
        {
                for (j=1; j<=i; j++)
                {
                        printf("%c", ch);
                }
                printf("\n");
        }
}

int main(void)
{
        char ch;
        int L, n, i;
        scanf("%c%d%d", &ch, &L, &n);
        if (L==1)
        {
                for (i=0; i<n-1; i++) printf("%c\n", ch);
                printf("%c", ch);
        }
        else
        {
                for (i=0; i<n; i++)
                        triangle(ch, L);
                if (L>0 && n>0)
                        printf("%c", ch);
        }

        return 0;
}
