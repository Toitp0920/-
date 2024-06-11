#include <stdio.h>
int HIT[10000];
int main()
{
    char str[5];
    int N, num;
    int i, j, tmp;

    scanf("%d", &N);
    while (N>0)
    {
        scanf("%s", str);

        for (i=4; i>0; i--)
        {
            for (j=1; j<i; j++)
            {
                if (str[j-1] > str[j])
                {
                    tmp = str[j];
                    str[j] = str[j-1];
                    str[j-1] = tmp;
                }
            }
        }
        num = 0;

        for(i=0; i<4; i++)
        {
            num = num*10;
            num = num + str[i] - '0';
        }

        HIT[num]++;
        N--;
    }

    for(i=0; i<10000; i++)
    {
        if(HIT[i] > 1)
            printf("%04d\n", i);
    }

    return 0;
}
