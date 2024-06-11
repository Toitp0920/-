#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30];
    char str2[30];
    char str3[60];


    scanf("%29s", str1);
    scanf("%29s", str2);

    /*
    strcpy(str3, str1); //把str1複製存到str3
    strcat(str3, str2); //把str2接到str3後面
    //通過以上這兩行，結果即為：st1+st2合在一起
    printf("%s\n", str3);
    */

    //也可以指複製其中一段
    strcpy(str3, str1); //這是讓str3=str1
        //printf("%s\n", str3);
    strncpy(str3, str2, 2); //用str2把str3的前2個字元蓋掉，也就是讓str3 = str2的前兩個字而已
        //printf("%s\n", str3);
    strcat(str3, str2); //然後在後面接上str2一次
    printf("%s\n", str3);




    return 0;
}
