#include <stdio.h>
int HIT[10000];
int main()
{
    int N;  //有多少筆資料要輸入
    int i, j, num;
    char tmp;
    char str[5];
    //輸入的資料用string的方式來儲存(因為題目可能存在"0012"之類的編號)
    scanf("%d", &N);
    while (N>0)
    {
        scanf("%s", str);
        for (i=4; i>0; i--)
        {
            //將輸入的資料由小到大排序
            for (j=1; j<i; j++)
            {
                if (str[j-1] > str[j])
                {
                    tmp = str[j];
                    str[j] = str[j-1];
                    str[j-1] = tmp;
                }
            }
        }
        //之後將每個string資料轉換成數值資料
        //str"1234" => 1234 num
        num = 0;
        for (i=0; i<4; i++)
        {
            num = num*10 + str[i]-'0';   //這個過程中1會被*10三次，2兩次...最後變成1234
        }

        HIT[num]++; //如果一個數字出現一次，則那個數字的格子就從0開始+1，看看這個數字最後出現幾次
        N--;
    }

    for (i=0; i<10000; i++)
    {
        if (HIT[i]>1)
        {
            printf("%04d\n", i);    //0代表印出四位數，如果不夠，前面補0
        }
    }

    return 0;
}
