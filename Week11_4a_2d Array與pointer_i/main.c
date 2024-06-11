//看待2d array的思維與pointer
#include <stdio.h>
typedef int row_vector[5];
/*
意思是把「row_vectop」定義成一個新的type，我們可以用他來宣告一個variable或array
而這個type是由5個int構成的東西
*/
int main()
{
    /*
    以下row_vector M[4]就等於是一個
    int M[4][5]的2d array了
    因為row_vector M[0]的空間表示如下：
    M[0]={0, 1, 2, 3, 4}
    M[1]={0, 1, 2, 3, 4}
    M[2]={0, 1, 2, 3, 4}
    M[3]={0, 1, 2, 3, 4}
    */
    /*
    我們也應該比照這種思維看待2d array
    也就是說，當看到a[4][5]時
    正確的思維應該是：
    「有4棟[由5個整數構成]的房子」O
    而不是
    「有4x5=20棟房子」X
    */
    row_vector M[4];
    int a[10];

    row_vector* pM;
    int* pa;


    pM = M;
    pa = a;

    printf("pa: %p pa+1: %p\n", pa, pa+1);
    printf("pM: %p pM+1: %p\n\n", pM, pM+1);

    /*
    如果是要為m[4][5]這個2d array定義一個指標variable
    就應該用這樣的思維
    以下就是定義一個variable pm
    此時這個pm是「5個整數大小為單位的空間」
    注意宣告時的寫法！
    */
    int m[4] [5];
    int (*pm)[5];
    //之後就跟之前一樣可以把pm當作指標variable來用
    pm = m;
    printf("&m: %p m+1: %p\nsize of m: %d\n", m, &m+1, sizeof(m));
    printf("pm: %p pm+1: %p\nsize of pm: %d\n", pm, pm+1, sizeof(pm));
    return 0;
}
