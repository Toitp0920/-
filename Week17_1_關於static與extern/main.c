/*
關於 static 與 extern

static

「函數」前面如果加 static
表示這個函數不會被 linker 看到
因此不會和其他檔案連結(不會跟別的檔案同名的fuction衝到)

「變數」前面如果加 static
表示這個變數從程式開始執行就會存在
直到程式結束才會消失

extern

只在一個原始碼檔案中定義
int x = 0;
其他原始碼檔案如果使用 x，應該宣告成
extern int x;
*/
#include <stdio.h>

int f(void)
{
    int b = 0;
    b = b + 1;
    return b;
}
int g(void)
{
    static int a = 0;
    a = a + 1;
}
int main()
{
    printf("int b:\n%d\n",f());
    printf("%d\n",f());
    printf("%d\n",f());
    printf("%d\n\n",f());

    printf("static int a:\n%d\n",g());
    printf("%d\n",g());
    printf("%d\n",g());
    printf("%d\n",g());
    return 0;
}
