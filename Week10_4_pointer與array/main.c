#include <stdio.h>

int main()
{
    int a[10];
    //���ɡua�v�N�w�g�O�o��array������variable�F
    int i;
    for ( i = 0; i < 10; i++ )
        a[i] = i * i;
    printf( "%p\n\n", a );

    for ( i = 0; i < 10; i++ )
        printf( "&a[%d]: %p\n", i, &a[i] );
    /*
    �O����Ŷ��O��16�i��g���G0123 4567 89AB CDEF
    ������X�Ӫ��Ʀr���t4�O�H
    �]���L�Oint�����O�A�C�Ӹ�Ƴ��O4 byte
    */
    /*
    �������g�k
    a[i]  <--->  *(a+i)
    &a[i] <--->  (a+i)
    */
    printf("\n&a : %p\n", a);
    //a���O�����m��a[0]�@�ˡA
    //�]��a[3]����m�N�Oa+3���᪺�O����Ŷ�
    printf("&a[3]: %p\n", &a[3]);
    printf("%p\n", a+0);
    printf("%p\n\n", a+3);

    printf("a[3]: %d\n", a[3]);
    printf("%d\n", *(a+3));

    printf("\n*************\n");
    //�ҥH�o�˼g�O�������|��������I
    for ( i = 0; i < 10; i++ )
        i[a] = i * i;   //�`�N�o��
    /*
    �]��i[a]���q���ӻ��A
    �N = i+a �o�Ӧ�m�̭��˪���
    �]�N�O *(i+a)
    �� *(i+a)���N����*(a+i)��
    �]�����q���ӻ��Aa[i]��i[a]�������O�����m�����S���t�O
    ��M�̭��˪��Ʀr�����O�P�@�ӪF���o
    */
    printf("5[a]: %d\n", 5[a]);
    printf("a[5]: %d\n", a[5]);
    printf("*(a+5): %d\n", *(a+5));
    printf("*(5+a): %d\n", *(5+a));

    return 0;
}
