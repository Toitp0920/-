//�Ψ�ƨӧ���main������array
#include <stdio.h>
void f( int* p, int size );
int main()
{
    int a[10];
    int i;
    for ( i = 0; i < 10; i++ )
        a[i] = i * i;
    for ( i = 0; i < 10; i++ )
        printf( "%2d ", a[i] );
    printf( "\n" );
    f( a, 10 );
    for ( i = 0; i < 10; i++ )
        printf( "%2d ", a[i] );
    return 0;
}

void f( int* p, int size )
{
    int i;
    for ( i = 0; i < size; i++ )
        p[i]++;
    //�]�i�H�g++*(p+i);
    //��*(p+i)=*(p+i)+1;
}
