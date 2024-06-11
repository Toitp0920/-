
#include <stdio.h>
#define MAX_SIZE 50
#define LOWER_LIMIT 0
#define UPPER_LIMIT 1000000
int main( void )
{
    int data[MAX_SIZE];
    int i, j, size;
    int maxval = LOWER_LIMIT, minval = UPPER_LIMIT;

    freopen("test.txt", "r", stdin);  //�Ʋ�Ū����ƪ��g�k
    for ( size = 0; size < MAX_SIZE; size++ )
    {
        if ( scanf( "%d", data+size ) != 1 )  //�Ʋߤ��e�ǹL���Ϊk�A�i�H�g��&data[size]
            break;
    }
    for ( i = 0, j = size - 1; i <= j; i++, j-- )
    {
        if (data[i]>=maxval)
            maxval=data[i];
        else if (data[i]<minval)
            minval=data[i];
    }
    printf( "%d %d\n", minval, maxval );

    return 0;
}
