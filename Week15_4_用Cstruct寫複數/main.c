/*��C struct �g�Ƽ� ( �]�t�곡�P�곡 )

*/#include <stdio.h>
#include <stdlib.h>
typedef struct t_complex {
    double r;
    double i;
} Complex;
void add(Complex a, Complex b, Complex *t)
{
    t->r = a.r+b.r;
    t->i = a.i+b.i;
}
void set_complex(Complex *p, double r, double i)
{
    p->r = r;
    p->i = i;
}
void show_complex(Complex t)
{
    printf("%.2f%+.2fi\n", t.r, t.i); //�Ʋ�%+f���N��P�Ϊk
}
int main(void)
{
    Complex x, y, z;
    set_complex(&x, 1, 2); //�i���u�Ҳդơv���g�k�A�n���B�]�w�ܶq�����e�ɡA�]�z�Lfunction�ӭק�
    set_complex(&y, 2, -3);
    add(x, y, &z);
    show_complex(z); //�o�̤]�O�ҲդƼg�k����{

    return 0;
}
