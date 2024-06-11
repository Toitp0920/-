/* E10_15.c
在程式執行期間才動態取得記憶體空間
而非一開始宣告使用多少記憶體
1.使用「malloc(需要多少個byte的空間)」 這個function
2.這function是宣告在<stdlib.h>裡面的 (Standard library)
3.這個函數取得的記憶體並沒有被「切割」，也就是系統不知道你要在這些記憶體裡面放什麼型別的資料
4.要在前面提供型別內容
5.並且用一個指標variable來取得這個array的開頭地址
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double *ptd; //用這個指標variable來記住取得的array的開頭地址
    int array_size, i;

    printf("How many doubles do you want? ");
    scanf("%d", &array_size);  //假設我們輸入我們需要10000個double空間
    ptd = (double *) malloc(array_size * sizeof(double));
    //                           10000 * sizeof (double) = 8 byte
    //(double *) (要用某個型別的方式來把這一大塊空間做切割)
    if (ptd == NULL) //NULL其實就是0，但為了方便了解他的意義所以寫NULL，也就是要不到記憶體
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);//這代表直接結束程式，不跑完main函數，因此return非0
    }

    for (i = 0; i < array_size; i++)
    {
        ptd[i] = (double) rand() / RAND_MAX;
        //rand()每次呼叫這個函數時會產生一個0~32767的亂整數，幾乎是找不到規則的，但只是很難找規律，但程式本身還是沒有真正意義的亂數的
    }   //RAND_MAX即32767
    for (i = 0; i < array_size; i++)
    {
        if (*(ptd+i) > 0.5)
            printf("%d: %f\n", i, ptd[i]);
    }

    free(ptd);
    //把這個空間釋放掉，後面如果有別的程式碼，可以做別的事情，或者繼續當需要時才要記憶體

    return 0;
}
