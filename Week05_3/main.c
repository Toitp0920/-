/*
W07_03
�w�q�@�� function (���W�� check)
����U���� expression
�ھ� expression ����
��X��������T "True" �� "False"
*/
#include <stdio.h>
void check(int x)
{
        if(x)
                printf("true\n");       //�]���u���@��Ʊ��A�ҥH���Τj�A��
        else
                printf("false\n");      //�]���u���@��Ʊ��A�ҥH���Τj�A��
//        printf("%d\n\n", x);
}
int main(void)
{
        int x = 5;
        int y = 3;

        check(x > 2 && y == 3); // T
        check( !(x < 2 || y == 3) );    //F
        check(x != 0 && y);             // T�C�]��y�O�@�ӫD0�ƭȡA�YTrue�C0&&true=0�A�ҥHx(true)!=0��true
        check(x == 0 || !y);            //F�C�]�� !y��False�A0||False=false�A�]��x==false��false
        check(x != y && (20/x) < y); // True && False = false
        check( !(y>5 || y<2) && !(x%5) ); //true && true=true
        check( !x && x );         //false && true = false

        return 0;
}
