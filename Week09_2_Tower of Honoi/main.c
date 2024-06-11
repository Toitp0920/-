/*
Tower of Honoi
河內塔解法
設有三柱子A、B、C
以及N個圓盤
求解法
*/
#include <stdio.h>
void honoi(int n, char from, char to, char buf);
int count;

int main()
{
        int n;
        scanf("%d", &n);
        honoi(n, 'A', 'C', 'B');
        printf("%d", count);
        return 0;
}

void honoi(int n, char from, char to, char buf)
{
        if(n==0) return;
        else
        {
                honoi(n-1, from, buf, to);
                printf("%d : %c -> %c\n", n, from, to);
                honoi(n-1, buf, to, from);
                count++;
        }
}
