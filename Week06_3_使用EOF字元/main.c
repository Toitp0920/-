#include <stdio.h>
int main(void)
{
        char ch;

        //while ((ch = getchar()) != '@')
        //如果是上面這樣寫，則'@'這個字元會無法使用
        while ((ch = getchar()) != EOF)
        //EOF字元代表要按ctrl+z+enter才會退出

                putchar(ch);

        return 0;
}

/*當程式寫完，不用debug時，
要把上面compile旁邊的Debug，改成Release後
再compile一次，生成release檔
這樣檔案不包含debug功能，才會小很多
在cmd命令列上，可以使用D:\Programming\c\Week06_3_使用EOF字元\bin\Release > output.txt
把結果輸出到output.txt這個檔案裡
或者可以製作一個Input檔，用
D:\Programming\c\Week06_3_使用EOF字元\bin\Release < input.txt
來輸入檔案，當然也可以輸入跟輸出都不經過螢幕：
D:\Programming\c\Week06_3_使用EOF字元\bin\Release < input.txt>output.txt
