#include <stdio.h>
#include <stdlib.h>

void malloc_float2( float * * p , unsigned int sz)
{
    *p = (float *) malloc(sz*sizeof(float));
    //因為p=&ptr，所以*p = *&ptr = ptr (*跟&的作用剛好是互相抵銷的)
    //所以這裡等同於ptr = (float *) malloc(sz*sizeof(float));
}

int main(void)
{
    float * ptr = NULL; //一般會習慣先「接地」(初始化)，這樣後來可以寫個判斷，看看ptr有沒有真的取得一個合法可用的空間地址
    int i;
    int n = 100;

    malloc_float2(&ptr, n);

    for (i=0; i<n; i++)
        ptr[i] = (float) rand()/RAND_MAX;

    free(ptr);

    return 0;
}
