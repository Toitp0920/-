#include <stdio.h>
#include <string.h>

//���ЗA���I?������?�i
int main()
{
        char str[1000];
        int i, j;
        int isPal = 0;

        scanf("%s", &str);
        i = 0;
        j = strlen(str) - 1 ;
        while (i < j)
        {
                if (str[i] == str[j])
                {
                        i++;
                        j--;
                }
                else
                        break;
                        //�@��?�i�C���s���break�C��i>j(���Ɍ�?)or i=j(��Ɍ�?)
        }
        if (i<j)
                printf("Not a palindrome.\n");
        else
                printf("Palindrome!\n");

        return 0;
}
