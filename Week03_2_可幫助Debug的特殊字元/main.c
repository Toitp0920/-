#include <stdio.h>
#include <stdlib.h>

int main()
{
        //以下程式可幫助Debug
        printf("%s\n", __FILE__);   //此檔檔名
        printf("%d\n", __LINE__);   //此行程式在第幾行
        printf("%s\n", __func__);   //此行程式在哪個function內
        printf("%s\n", __DATE__);   //系統日期
        printf("%s\n", __TIME__);   //系統時間

        //因此盡量不要使用兩個底線+大寫當作varible的identifier
    return 0;
}
