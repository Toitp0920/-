/*
W07_02
��J�@�ӥ����
�{�������C�X���F 1 �M�ӥ���ƥ����H�~�������]��
�]�ƥ����q�p��j�ƦC
�p�G�L�k�]�Ƥ���
�h���O������ܳo�ӥ���ƬO���
*/
//���Ҫk���ޥ�
#include <stdio.h>
int main(void)
{
        int num, div;
        int isPrime;

        printf("Please enter an integer (q to quit): \n");
//        scanf("%d", &num);

        while(scanf("%d", &num))
        {
                //�Ψ��for�j��A���Ʀr�Ѥp��j�ƦC
                for(div=2 , isPrime = 1 ; div*div<num ; div++)
                {               //�����]��J��num�O���
                        if (num%div==0)
                        {
                                printf("%d, ", div);
                                isPrime = 0;    //��O����]�ƮɡA�N��������]���}
                        }
                }
                div--;
                for ( ; div>=2; div--)
                {
                        if (num%div ==0)
                        {
                                printf("%d, ", num/div);
                        }
                }
                if (isPrime)
                printf("%d is prime.\n", num);
        }
/*
        if (isPrime)
                printf("%d is prime.\n", num);

        else
                printf("\b\b are divisors of %d\n", num);
*/
        return 0;
}
