#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;

    while ((ch = getchar())  !='\n')    //先輸入字母，並存入ch，再判斷是否!'\n'
    {

        if (isalpha(ch))
        {
            putchar(ch+1);
        }
        else
        {
            putchar(ch);
        }

    }

    return 0;
}
