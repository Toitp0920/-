#include <stdio.h>
#include <ctype.h>
/*
isalpha �P�_�O�_���r��(>*<.,���r���ӫD�r��)
isdigt �P�_�O�_���Ʀr
toupper �p�ܤj�g
tolower �j�ܤp�g
isupper �P�_�O�_���j�g
islower �P�_�O�_���p�g
*/
//�p�g�ܤj�g
int main()
{
        char ch;

        while ( (ch = getchar()) !='\n')
        {
                putchar( toupper(ch) );     //�o�@��N����H�U�����e�A�Y�p�ܤj�g
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
