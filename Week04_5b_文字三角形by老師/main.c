#include <stdio.h>
#include <string.h>
//�o�O�Ѯv�g����r�T���ΡA�Q��%*.*s���g�k�A�u�ݤ@�Ӱj��
int main()
{
    int i, j;
    char word[30];
    scanf("%29s", word);
    i = 1;
    while(i<=strlen(word))
    {
        printf("%*.*s\n", strlen(word), i, word);
        i++;
    }


    return 0;
}
