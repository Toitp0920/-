/*
動態取得2d array空間
*/
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int *a, **b, i, j, rows, cols;
    /*
    上面這句跟以下一樣
    int *a;
        這裡a是一個儲存「int」的指標，即int a[0]= *(a+0)裡面存的是一個int
    int **b;   可以視為：int*  *b
        這裡b是一個儲存「地址」的指標，即int* b[0]= *(b+0)裡面存的是一串int記憶體的地址
    int i, j, rows, cols;
    */

    scanf("%d%d", &rows, &cols); //假設輸入rows=4, cols=5 即A[4][5]
    a = (int *) malloc(rows * cols * sizeof(int)); //int的大小 = 4byte
    //總共取得的大小共有4*5*(4byte)，並將這一大個空間，每4byte切一格，把第一格的位置存給a

    for (i = 0; i < rows*cols; i++)
        a[i] = i; //把這20塊記憶體填入0~19

    b = (int* *) malloc(rows * sizeof(int *)); //每一個地址的資料大小 = 8byte
    //總共取得的大小共有4*(8byte)，並將這一大個空間，每8byte切一格，把第一格的位置存給b
    //因為b裡面要儲存一個一個的地址，所以每一格都要有8byte

    for (i = 0 ; i < rows; i++) b[i] = &a[i*cols];
/*               a={      類似於把 a[20] 變成 p
b[0] = &a[0]    |  0 |  1 |  2 |  3 |  4 |    p[0~4]={ 0,  1,  2,  3,  4}
b[1] = &a[5]    |  5 |  6 |  7 |  8 |  9 |    p[0~4]={ 5,  6,  7,  8,  9}
b[2] = &a[10]   | 10 | 11 | 12 | 13 | 14 |    p[0~4]={10, 11, 12, 13, 14}
b[3] = &a[15]   | 15 | 16 | 17 | 18 | 19 | }  p[0~4]={15, 16, 17, 18, 19}

原本要取得Array[2][4]也就是13號的位置要用 2*cols + 4 「i*cols+j」
但透過b，現在只要用
b[2]+4就是第13號記憶體了「 b[i]+j 」
也就是原本要從a的第一個地址開始往後數i*cols+j
現在可以用b，從b[i] = &a[i*cols] = p 往後數j
就可以取得同樣一塊記憶體了

有點類似於把一大塊 a[20] 變成四個 p[5](見右上角圖)
*/


/*
現在開始翻譯一下：
所以
b[0][1]應該要被視為(b[0])[1]也就是 &a[0] [1] = p[1]
譬如b[2][4] = &a[10] [4] = *( &a[10] + 4 )= *(p+4) = p[4] = 13號
*/

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }

    /* memory leak
    如果這時候，忘了寫free(a)
    馬上就再寫一個 a = (int *) malloc(rows * cols * sizeof(int));
    這時原本上一個a的地址已經無法追究了
    也就無法free掉他
    那塊記憶體就無法被釋放，記憶體就會有越用越少的狀況
    也會有一堆記憶體沒人使用，也不能被找到並且使用
    */
    free(b);
    free(a);

    return 0;
}
