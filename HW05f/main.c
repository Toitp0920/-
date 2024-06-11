#include <stdio.h>
int main()
{
        long int inputs[5]={0};
        int isArith=0;
        int isGeo=0;
        int i, d, r;
        long int a5;

        for(i=1; i<5; i++)
                scanf("%ld", &inputs[i]);
        for(i=1; i<=2; i++)
        {
                if((inputs[i+1]-inputs[i])==(inputs[i+2]-inputs[i+1]))
                        isArith++;
                else if((inputs[i+1]/inputs[i])==(inputs[i+2]/inputs[i+1]))
                        isGeo++;
                else break;
        }
        if(isArith==2)
        {
                d=inputs[2]-inputs[1];
                a5=inputs[1]+4*d;
                printf("%d %d", a5, d);
        }
        else if(isGeo==2)
        {
                r=inputs[2]/inputs[1];
                a5=inputs[1]*r*r*r*r;
                printf("%d %d", a5, r);
        }



        return 0;
}
