#include <stdio.h>
/* 輸入三個變數：符號、數字、數字，
會跑出用那個符號填滿，長、寬依照輸入的長方形*/
void display(char cr, int lines, int width);
int main (void)
{
        int ch;
        int rows, cols;
        printf("Enter a character and two integers:\n");
        while ((ch = getchar()) != '\n')
        {
                if(scanf("%d%d", &rows, &cols)!=2)      //scanf兩個值要回傳兩個1
                        break;
                //如果沒有使用if來包覆那個scanf，
                //則當用戶輸入無效的資料時，
                //rows跟cols會按照記憶體裡面原本存在的值來跑，就不是我們要的

                display(ch, rows, cols);
                printf("Enter another character and two integers;\n");
                printf("Enter a newline to quit.\n");

                while(getchar() != '\n');
                        //多了這行，在輸入內容時的enter，將會打破這層空迴圈
                        //而不會讓初始的while就這樣被打破了

        }
        printf("Bye.\n");
        return 0;
}
void display(char cr, int lines, int width)
{
        int row, col;
        for(row = 1; row <=lines; row++)
        {
                for (col = 1; col <= width; col++)
                        putchar(cr);
                putchar('\n');
        }
}
