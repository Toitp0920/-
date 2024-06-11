//main裡面variable的兩數交換
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
    如此函數內的a, b雖然有交換，
    但main裡的x, y並沒有，相當於做白工
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
