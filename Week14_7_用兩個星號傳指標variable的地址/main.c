#include <stdio.h>
#include <stdlib.h>

void malloc_float2( float * * p , unsigned int sz)
{
    *p = (float *) malloc(sz*sizeof(float));
    //���p=&ptr������*p = *&ptr = ptr (*��&�����Ä����ǻ�����N��)
    //�����@�e��ͬ�ptr = (float *) malloc(sz*sizeof(float));
}

int main(void)
{
    float * ptr = NULL; //һ������T�ȡ��ӵء�(��ʼ��)���@�������Ԍ����Д࣬����ptr�Л]�����ȡ��һ���Ϸ����õĿ��g��ַ
    int i;
    int n = 100;

    malloc_float2(&ptr, n);

    for (i=0; i<n; i++)
        ptr[i] = (float) rand()/RAND_MAX;

    free(ptr);

    return 0;
}
