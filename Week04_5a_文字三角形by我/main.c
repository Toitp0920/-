#include <stdio.h>
#include <string.h>
//�o�O�ڼg����r�T����
int main()
{
    int i , j;
    char word[30];
    int wordLen;
    scanf("%29s", word);

    wordLen = strlen(word);
//    printf("%d",wordLen);

    i = 1;
    while(i<=wordLen)
    {
        j = i;
        while(j<wordLen)
        {
            printf(" ");
            j++;
        }
        j = 1;
        while(j<=i)
        {
            printf("%c",word[j-1]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
