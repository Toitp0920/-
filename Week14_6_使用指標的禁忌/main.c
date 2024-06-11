//使用指標的禁忌
#include <stdio.h>
#include <stdlib.h>
// 1.function裡面的指標都只有function執行時有用(局部變數)，結束後記憶體空間就消失了
int* f(void)
{
    int a = 5;
    return &a; //當f結束時，&a就沒有意義了
}
// 2.當然暫時的array開頭地址也不行
int* g(void)
{
    int b[3] = {0, 0, 0};
    return b;
}
// 3.但如果是function裡面用malloc取得的空間，將可以一直使用，直到被釋放
int* h(void)
{
    int* c;
    c = (int*) malloc(10*sizeof(int));
    return c;
}
int*
int main()
{
    //1. 所以這是不行的！
    int *pa, *pb, *pc;
    pa = f();
    //2. 這也是不行的！
    pb = g();

    //3. 這個才是可以的，直到free掉都是可以的
    pc = h();
    return 0;
}
