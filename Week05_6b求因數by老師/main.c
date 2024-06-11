/*
W07_02
輸入一個正整數
程式必須列出除了 1 和該正整數本身以外的全部因數
因數必須從小到大排列
如果無法因數分解
則成是必須顯示這個正整數是質數
*/
//反證法的技巧
#include <stdio.h>
int main(void)
{
        int num, div;
        int isPrime;

        printf("Please enter an integer (q to quit): \n");
//        scanf("%d", &num);

        while(scanf("%d", &num))
        {
                //用兩個for迴圈，讓數字由小到大排列
                for(div=2 , isPrime = 1 ; div*div<num ; div++)
                {               //先假設輸入的num是質數
                        if (num%div==0)
                        {
                                printf("%d, ", div);
                                isPrime = 0;    //當記錄到因數時，將原先的假設打破
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
