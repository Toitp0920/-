#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int y;
    y= x/100 + ((x/10)%10)*10 + (x%10)*100;     // (x/100)�|�o��x���ʦ�Ʀr�A((x/10)%10)�|�o��x���Q��Ʀr�A(x%10)�|�o��x���Ӧ�Ʀr

    double z;       // �ڵo�{�n�����ઽ����printf("%f", (x+y)/2); �A�]��x , y���Oint�A��printf�̭��ڥ�%f�A�|�X���A�ҥH�s�ФF�@���ܼ�z
    z =x+y;
 //   printf("%d", z);
    printf("%.1lf", z/2);
    return 0;
}
