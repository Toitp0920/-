/*
W07_03
定義一個 function (取名為 check)
檢驗下面的 expression
根據 expression 的值
輸出對應的資訊 "True" 或 "False"
*/
#include <stdio.h>
void check(int x)
{
        if(x)
                printf("true\n");       //因為只做一件事情，所以不用大括號
        else
                printf("false\n");      //因為只做一件事情，所以不用大括號
//        printf("%d\n\n", x);
}
int main(void)
{
        int x = 5;
        int y = 3;

        check(x > 2 && y == 3); // T
        check( !(x < 2 || y == 3) );    //F
        check(x != 0 && y);             // T。因為y是一個非0數值，即True。0&&true=0，所以x(true)!=0為true
        check(x == 0 || !y);            //F。因為 !y為False，0||False=false，因此x==false為false
        check(x != y && (20/x) < y); // True && False = false
        check( !(y>5 || y<2) && !(x%5) ); //true && true=true
        check( !x && x );         //false && true = false

        return 0;
}
