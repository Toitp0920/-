#include<stdio.h>
int numPrime(int start, int end)
{
        int i, j;
        int start_count=0 , end_count=0 ;
        short int isPrime[5001]={0};
        for(i=2; i<5001; i++)
                isPrime[i]=1;
        for(i=2; i*i<=5000; i++)
        {
                for(j=i*i; j<=5000; j=j+i)
                        isPrime[j]=0;
        }
        for(i=2; i<=start; i++)
        {
                if(isPrime[i])
                {
                        start_count++;
                }
        }
        for(i=2; i<=end; i++)
        {
                if(isPrime[i])
                {
                        end_count++;
                }
        }
/*
        for(i=0; i<5001; i++)
        {
                if(isPrime[i]==1)
                {
                        printf("%d, ", i);
                }
        }
*/
        if(isPrime[start]==1&&isPrime[end]==1&&start==end)
                return 1;
        return end_count-start_count;
}
