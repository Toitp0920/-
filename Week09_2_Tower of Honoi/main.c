/*
Tower of Honoi
�e����Ѫk
�]���T�W�lA�BB�BC
�H��N�Ӷ�L
�D�Ѫk
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
