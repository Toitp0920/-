/*
W07_02
��J�@�ӥ����
�{�������C�X���F 1 �M�ӥ���ƥ����H�~�������]��
�]�ƥ����q�p��j�ƦC
�p�G�L�k�]�Ƥ���
�h���O������ܳo�ӥ���ƬO���
*/
#include <stdio.h>
int main(void)
{
        int num, div;
        int isPrime;

        printf("Please enter an integer (q to quit): \n");
        scanf("%d", &num);

        int i;
        for(i=num-1 ; i>1 ; i--)
        {
                if(num%i==0)
                {
                        printf("%d is the divisor of %d\n", i,  num);
                        isPrime++;
                }
        }

        if (isPrime==0)
                printf("%d is prime.\n", num);
/*
        else
                printf("\b\b are divisors of %d\n", num);
*/
        return 0;
}
