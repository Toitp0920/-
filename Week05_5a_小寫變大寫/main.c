#include <stdio.h>
#include <ctype.h>
/*
isalpha 判斷是否為字母(>*<.,為字元而非字母)
isdigt 判斷是否為數字
toupper 小變大寫
tolower 大變小寫
isupper 判斷是否為大寫
islower 判斷是否為小寫
*/
//小寫變大寫
int main()
{
        char ch;

        while ( (ch = getchar()) !='\n')
        {
                putchar( toupper(ch) );     //這一行就等於以下的內容，即小變大寫
                /*
                if (ch>='a' && ch <='z')
                {
                        putchar( 'A'-'a'+ch );
                }else
                {
                        putchar(ch);
                }
                */
        }
        putchar(ch);


        return 0;
}
