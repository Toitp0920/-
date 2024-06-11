#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int y;
    y= x/100 + ((x/10)%10)*10 + (x%10)*100;     // (x/100)會得到x的百位數字，((x/10)%10)會得到x的十位數字，(x%10)會得到x的個位數字

    double z;       // 我發現好像不能直接用printf("%f", (x+y)/2); ，因為x , y都是int，但printf裡面我用%f，會出錯，所以新創了一個變數z
    z =x+y;
 //   printf("%d", z);
    printf("%.1lf", z/2);
    return 0;
}
