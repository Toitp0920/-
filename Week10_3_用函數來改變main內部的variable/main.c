//main�̭�variable����ƥ洫
#include <stdio.h>
void swap( int a, int b );

int main()
{
    int x, y;

    scanf( "%d%d", &x, &y );
    printf( "False method:\n" );
    printf( "x; %d, y:%d\n", x, y );
    swap( x, y );
    printf( "x; %d, y:%d\n", x, y );
    /*
    �p����Ƥ���a, b���M���洫�A
    ��main�̪�x, y�èS���A�۷�󰵥դu
    */

    printf( "\nCorrect method:\n" );
    printf( "x; %d, y:%d\n", x, y );
    swaptrue( &x, &y );
    printf( "x; %d, y:%d\n", x, y );
    return 0;
}

void swap( int a, int b )
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void swaptrue( int* a, int* b )
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
