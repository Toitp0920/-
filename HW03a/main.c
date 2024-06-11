#include <stdio.h>
int main()
{
    int numN[33]= {0} , numNP[33] ={0} ;       //用來裝數字的Array
    unsigned int N, Nplus;      //輸入的數字
    int i, j;
    int digits, carries;        //digits計算轉換後的二進位數有幾位數，carries計算N+1將會造成幾次進位

    scanf("%u", &N);        //用戶輸入int N，題目要我們算N+1
    Nplus = N+1;

    //先把數字N用二進制存成Array(順序顛倒)
    i = 0;
    while(N)
    {
        //printf("%d", N%2);
        numN[i]= N%2;
        i++;
        N = N/2;
    }
    //也把N+1後的數字用二進制存成Array(順序顛倒)
    j = 0;
        while(Nplus)
    {
        numNP[j]= Nplus%2;
        j++;
        Nplus = Nplus/2;
    }
    digits = j+1;       //順便計算這個二進位數有幾位數，為j+1次
//    printf("j=%d, digits=%d, Nplus=%d\n\n", j , digits, Nplus);       debug用

    //把N+1的Array，由後往前依序print，才會顯示正確順序的二進位
    while(j)
    {
        j--;
        printf("%d", numNP[j]);
    }

    //最後要計算進位幾次
    carries = 0;
    while(digits>=0)
    {
            while(numNP[digits]-numN[digits])       //如果N與N+1的同一位數相減，結果為1or-1的話，代表有進位過，此時carries++
        {
            carries++;
//            printf("\n\nnumNP[%d]=%d\nnumN[%d]=%d\ncarries=%d",digits,numNP[digits],digits,numN[digits],carries);     debug用
            digits--;       //每一位數都要相減過一次
        }
        digits--;
    }
    printf(" %d", carries-1);       //如果進位過兩次，則會有3個位數的0與1會不同，因此carries要-1
    return 0;
}
