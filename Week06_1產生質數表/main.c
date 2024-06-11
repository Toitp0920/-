/*
把這個網址
https://zh.wikipedia.org/wiki/埃拉托斯特尼筛法
寫成程式
*/


//[ 0, 1, 2, 3, 4, 5, 6...........100]
//[         1, 1, 0, 1, 0............0    ]


#include <stdio.h>
#define N 1000000
char A[N+1];            //
int main()
{
        int i, j;

        for(i = 0; i<=N ; i++) A[i]= 1;         //

        for(i=2; i*i<=N;i++)
        {
                if (A[i])     //=1
                {
                        for (j=i*i ; j<=N; j = j+i)     // j<=sqrt(N)
                        {
                                A[j]= 0;        //
                        }
                }
        }
        //1~N


/*
        for(i=100; i<=1000; i++)
        {
                if( A[i])printf("%d ", i);
        }
*/


        return 0;
}
