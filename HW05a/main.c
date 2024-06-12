#include <stdio.h>
//10768 - wave
//這是我的寫法(2/4)
int main()
{
        char c;
        unsigned int l, n;
        int i, j, w;

        scanf("%c %u %u", &c, &l, &n);
        for(i=1; i<=n; i++)
        {
                if(i>1) w=2;
                else w=1;
                while(w<=2*l-1)
                {

                        if (w<=l)
                        {
                                for(j=1; j<=w; j++)
                                {
                                        printf("%c", c);
                                }
                                printf("\n");
                        }
                        else
                        {
                                for(j=1; j<=2*l-w; j++)
                                {
                                        printf("%c", c);
                                }
                                if(i==n&&w==2*l-1) break;
                                else printf("\n");
                        }
                        w++;
                }
        }





        return 0;
}
