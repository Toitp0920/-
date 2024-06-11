#include <stdio.h>

int main()
{
    int i, j;
    int m[4][5];
    int ( *p )[5];
    for ( i = 0; i < 4; i++ )
    {
        for ( j = 0; j < 5; j++ )
            m[i][j] = i * j;
    }
    p = m;
    printf( "m[3][2]: %d\n\n", m[3][2] );

    printf( "pm[3][2]: %d\n", p[3][2] ); //p = m
    printf( "*(pm[3]+2)): %d\n", *(p[3]+2) ); //把後面的中括號換成另一種表示法可以
    printf( "*(*(pm+3)+2): %d\n", *(*(p+3)+2) );//再把p[3]的寫法也改成pointer的寫法
    printf( "*(pm+3)[2]: %d\n", *(p+3)[2] ); //把前面的換掉這個是不行的

    //pm+3代表pm開始往後5+5+5棟房子，[2]代表那裏面的第2棟

//另外比較以下兩個內容
    int* pA[5];
    int (*pB)[5];
    /*
    上面的表示一個pointer array pA[5]
    pA[0]~pA[4]裡面裝的東西都是一個地址
    下面的表示一個pointer variable pB
    pB裡面的資料大小都是5個int 為一個單位 裡面裝的也是int 而非地址
    */
}
