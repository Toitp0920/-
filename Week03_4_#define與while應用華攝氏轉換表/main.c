#include <stdio.h>
#include <string.h>
#define lower 0
#define upper 200
#define step 20
int main()
{
        int fahr, lineLen;
        double cels;
        fahr = lower;
        //lineLen = strlen("--------------------------");

        printf("fahrenheit         celsius\n");
        printf("--------------------------\n");
        //printf("%u", strlen("--------------------------"));

        while(fahr <= upper)
        {
                cels = (fahr-32)*5/9;
                printf("%5d%23.lf\n", fahr , cels);
                fahr = fahr+step;
        }
        printf("--------------------------");

        return 0;
}
