#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;

    while ((ch = getchar())  !='\n')    //����J�r���A�æs�Jch�A�A�P�_�O�_!'\n'
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
