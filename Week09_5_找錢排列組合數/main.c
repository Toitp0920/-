/*
Make Change
輸入不同面值的銅板
然後輸入一個金額
將全部可能的找零方式列出
譬如有 1 元、5元、10元銅板
要湊出 17 元
如果將可能的組合表示成 "(1元個數,5元個數,10元個數)"
總共會有下列幾種方法
(2,1,1)
(2,3,0)
(7,0,1)
(7,2,0)
(12,1,0)
(17,0,0)
*/
#include <stdio.h>
#define MaxCN 5         //Max coin number
int coin[MaxCN];        //={1, 5, 10, 50, 100}之類的幣值
int cn[MaxCN];          //={2, 1, 1, 0, 0} 之類的硬幣數量組合數
void display(int n);
void change(int Money, int seq, int n);

int main()
{
        int n, i, money;
        scanf("%d", &n);

        if(n>MaxCN || n<1) return 0;

        for(i=0; i<n; i++)
                scanf("%d", &coin[i]);
        scanf("%d", &money);
        change(money, 0, n);
        return 0;
}

void display(int n)
{
        int i;
        printf("(%d", cn[0]);
        for(i=1; i<n; i++)
                printf(", %d", cn[i]);
        printf(")");
}
void change(int Money, int seq, int n)
{
        if(seq<n)       //終止條件別忘了！
        {
                if(Money==0)
                        display(n);
                else if(Money>0)
                {
                        cn[seq]++;
                        change(Money-coin[seq], seq, n);
                        cn[seq]--;
                        change(Money, seq+1, n);
                }
        }
}
