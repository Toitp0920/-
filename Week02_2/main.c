#include <stdio.h>

double square(double y)
{
    return y*y;
}

int main()
{
    /*
    float x;
    scanf("%f", &x);
    printf("%f\n" , square(x));
    */
   // char ch = 65;
   // printf("%c\n", ch);
    char ch[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int i;
    scanf ("%d", &i);
    printf ("%c%c%c\n",ch[i/100], ch[(i/10)%10], ch[i%10 ]);





    return 0;
}
