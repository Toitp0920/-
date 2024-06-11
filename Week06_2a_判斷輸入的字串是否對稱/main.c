#include <stdio.h>
#include <string.h>

//”»Ğ—A“ü“I?‹ø¥”Û?âi
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
                        //”@‰Ê?âiC‘¥•s˜ğ”íbreakC‘¥i>j(‹ôÉŒÂ?)or i=j(ŠïÉŒÂ?)
        }
        if (i<j)
                printf("Not a palindrome.\n");
        else
                printf("Palindrome!\n");

        return 0;
}
