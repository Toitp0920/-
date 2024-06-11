/*
輸入一個英文句子字串
包含多個英文單字
每個英文單字之間用單個空白字元隔開
沒有其他標點符號
例如
this is a book

請用程式將上面的句子以單字為單位反轉後輸出
book a is this

並且不使用額外的array來存放結果
*/
#include <stdio.h>
void flip(char* a, int k, int l);
int main()
{
    int i, j;
    char a[100];
    fgets(a, 99, stdin);//為什麼不使用scanf?
    //因為scanf遇到空白就停下來了，而我們必須保存我們輸入的空白
    a[strlen(a)-1] = ' ';
    //這是為了把我們輸入的"this is a book\n"改成"this is a book \0"(有留一個空白在最後)

    j = 0;
    for (i=0; a[i]!='\0'; i++)
    {
        if (a[i] == ' ') //如果讀到空白，代表前面我們已經讀到一個單字了
        {
            flip(a, j, i-1); //顛倒那個單字字串
            j=i+1; //要把j更新，以便處理下一個單字
        }
    }
    printf("%s\n", a);//可以看到我們根據單字顛倒了
    //現在再把內容完全顛倒就成功了
    flip(a, 0, strlen(a)-2);
    printf("%s\n", a);
    return 0;
}
void flip(char* a, int k, int l)
{
    int tmp;
     for (; k<l; k++, l--)
    {
        tmp = a[k];
        a[k] = a[l];
        a[l] = tmp;
    }
}
/*圖一
 j   i
 k   l
 this is a book
*/
