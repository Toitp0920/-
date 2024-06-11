#include <stdio.h>
void show_bits(int );
char bits[64];
int N;
int count;
int main(void)
{
        printf("Please enter the number of bits: ");
        scanf("%d", &N);

        bits[N] = '\0';
        show_bits(0);

        printf("total: %d", count);
        return 0;
}

void show_bits(int x)
{
        if (x==N)
        {
                printf("%s\n", bits);
                count++;
        }
        else
        {
                bits[x] = '0';
                show_bits(x+1);
                bits[x] = '1';
                show_bits(x+1);
                bits[x] = '2';
                show_bits(x+1);
                bits[x] = '3';
                show_bits(x+1);
        }
}
