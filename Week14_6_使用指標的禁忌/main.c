//ʹ��ָ�˵Ľ���
#include <stdio.h>
#include <stdlib.h>
// 1.function�e���ָ�˶�ֻ��function���Еr����(�ֲ�׃��)���Y����ӛ���w���g����ʧ��
int* f(void)
{
    int a = 5;
    return &a; //��f�Y���r��&a�͛]�����x��
}
// 2.��Ȼ���r��array�_�^��ַҲ����
int* g(void)
{
    int b[3] = {0, 0, 0};
    return b;
}
// 3.�������function�e����mallocȡ�õĿ��g��������һֱʹ�ã�ֱ����ጷ�
int* h(void)
{
    int* c;
    c = (int*) malloc(10*sizeof(int));
    return c;
}
int*
int main()
{
    //1. �����@�ǲ��еģ�
    int *pa, *pb, *pc;
    pa = f();
    //2. �@Ҳ�ǲ��еģ�
    pb = g();

    //3. �@�����ǿ��Եģ�ֱ��free�����ǿ��Ե�
    pc = h();
    return 0;
}
