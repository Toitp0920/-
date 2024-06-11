/*用C struct 寫複數 ( 包含實部與虛部 )

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
    printf("%.2f%+.2fi\n", t.r, t.i); //複習%+f的意思與用法
}
int main(void)
{
    Complex x, y, z;
    set_complex(&x, 1, 2); //養成「模組化」的寫法，要更改、設定變量的內容時，也透過function來修改
    set_complex(&y, 2, -3);
    add(x, y, &z);
    show_complex(z); //這裡也是模組化寫法的表現

    return 0;
}
