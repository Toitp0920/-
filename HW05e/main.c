#include <stdio.h>
int move[10000]={0};
char AorB[1000]={0};
int AafterA(int k, int A, int B);
int BafterA(int k, int A, int B);
int AafterB(int k, int A, int B);
int BafterB(int k, int A, int B);
int main()
{
        unsigned int A, B, k;
        int i;
        int ra, rb;

        scanf("%u %u %u", &A, &B, &k);
//       printf("A%u B%u k%u\n", A, B, k);

        for(i=1; i<=k; i++)
        {
                if(getchar()!='\n');
                AorB[i]=getchar();
                scanf("%d", &move[i]);

        }

        for(i=1; i<=k; i++)
         {
                printf("character = %c, move = %d, i=%d\n", AorB[i], move[i], i);
         }



        for(i=1; i<=k; i++)
        {
                if (AorB[i]=='A')
                {
                        A=AafterA(i, A, B);
                        B=BafterA(i, A, B);
                }
                else if(AorB[i]=='B')
                {
                        A=AafterB(i, A, B);
                        B=BafterB(i, A, B);
                }
        }

        printf("%d %d", A, B);


        return 0;
}

AafterA(int k, int A, int B)
{
        A=A*1.08 - move[k];
        return A;
}
BafterA(int k, int A, int B)
{
        B=B*1.08 + move[k];
        return B;
}

AafterB(int k, int A, int B)
{
        A=A*1.08 + move[k];
        return A;
}
BafterB(int k, int A, int B)
{
        B=B*1.08 - move[k];
        return B;
}
