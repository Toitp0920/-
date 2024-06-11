/*
用 recursive 方式，產生下面的輸出
Input: 10
Output: ((((1+2)*3+4)*5+6)*7+8)*9+10=4555
Input: 11
Output: (((((1+2)*3+4)*5+6)*7+8)*9+10)*11=50105
*/
#include <stdio.h>
int f(int x);

int main()
{
        int x;
        scanf("%d", &x);
        printf(" = %d\n", f(x));
        return 0;
}

int f(int x)
{
        int ans;
        if(x==1)
        {
                printf("%d", x);
                return 1;
        }
        if(x%2==0)
        {

                ans=x+f(x-1);
                printf("+%d", x);
                return ans;
        }
        else
        printf("(");
        ans=f(x-1)*x;
        printf(")*%d", x);
        return ans;
}
