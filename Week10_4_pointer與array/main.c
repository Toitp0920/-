#include <stdio.h>

int main()
{
    int a[10];
    //此時「a」就已經是這個array的指標variable了
    int i;
    for ( i = 0; i < 10; i++ )
        a[i] = i * i;
    printf( "%p\n\n", a );

    for ( i = 0; i < 10; i++ )
        printf( "&a[%d]: %p\n", i, &a[i] );
    /*
    記憶體空間是用16進位寫的：0123 4567 89AB CDEF
    為什麼出來的數字都差4呢？
    因為他是int的型別，每個資料都是4 byte
    */
    /*
    等價的寫法
    a[i]  <--->  *(a+i)
    &a[i] <--->  (a+i)
    */
    printf("\n&a : %p\n", a);
    //a的記憶體位置跟a[0]一樣，
    //因此a[3]的位置就是a+3之後的記憶體空間
    printf("&a[3]: %p\n", &a[3]);
    printf("%p\n", a+0);
    printf("%p\n\n", a+3);

    printf("a[3]: %d\n", a[3]);
    printf("%d\n", *(a+3));

    printf("\n*************\n");
    //所以這樣寫是完全不會報錯的唷！
    for ( i = 0; i < 10; i++ )
        i[a] = i * i;   //注意這行
    /*
    因為i[a]對於電腦來說，
    就 = i+a 這個位置裡面裝的數
    也就是 *(i+a)
    而 *(i+a)不就等於*(a+i)嗎
    因此對於電腦來說，a[i]跟i[a]對應的記憶體位置完全沒有差別
    當然裡面裝的數字完全是同一個東西囉
    */
    printf("5[a]: %d\n", 5[a]);
    printf("a[5]: %d\n", a[5]);
    printf("*(a+5): %d\n", *(a+5));
    printf("*(5+a): %d\n", *(5+a));

    return 0;
}
