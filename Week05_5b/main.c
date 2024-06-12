#include <stdio.h>
#include <ctype.h>
//大小寫互換
int main()
{
        char ch ;

        while( (ch = getchar() ) !='\n')
        {
                if (isupper(ch))
                {
                        putchar(tolower(ch));
                }else if (islower(ch))
                        {
                                putchar(toupper(ch));
                        }
                else
                {
                putchar(ch);
                }
        }
        putchar (ch);
        return 0;
}
