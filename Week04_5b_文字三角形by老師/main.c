#include <stdio.h>
#include <string.h>
//這是老師寫的文字三角形，利用%*.*s的寫法，只需一個迴圈
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
