#include <stdio.h>
#include <string.h>

//判斷輸入的字串是否對稱
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
                        //如果對稱，則不會被break，則i>j(偶數個字)or i=j(奇數個字)
        }
        if (i<j)
                printf("Not a palindrome.\n");
        else
                printf("Palindrome!\n");

        return 0;
}
