//理解為何這段程式會有那樣的output

#include <stdio.h>
int f(int x);
int main()
{
    printf("\n%d\n", f(5));
    return 0;
}

int f(int x)
{
        int ans;
        if(x==0) return 0;

        printf("(%d ", x);
        ans = f(x-1);
        printf("%d) ", x);

        return ans;
}
