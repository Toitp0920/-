/*
四~八個皇后的問題
皇后可以走垂直水平
也可以走斜對角
如何在 4x4~8x8 的棋盤上擺放四~八個皇后
使得她們不會互相衝突
*/
//using 1D array
#include <stdio.h>
#define MaxN 8
int a[MaxN];
int count;
//這個可以計算總共有多少解

void display(void);
void place(int n);

int main()
{
        place(0);
        printf("共有 %d 個解", count);
        return 0;
}

void display(void)
{
        int i, j;
        count++;
        //每次這個display()被呼叫的時候，都記錄一次解多一個
        for(i=0; i<MaxN; i++)
        {
                for(j=0; j<MaxN; j++)
                {
                        if(j==a[i]) printf("㊣");
                        else printf("⊙");
                }
                printf("\n");
        }
        printf("\n");
}
int valid(int row, int col)
{
        int i;
        for(i=0; i<row; i++)
        {
                if(a[i]==col || row-i == col-a[i] || row - i == a[i]-col)
                return 0;
        }
        return 1;
}

void place(int row)
{
        int j;
        if (row==MaxN)
                display();
        else
        {
                for(j=0; j<MaxN; j++)
                {
                        if(valid(row, j))
                        {
                                a[row]=j;
                                place(row+1);
                        }
                }
        }
}
/*
a=2  3  1  0

i\j=0  1 2  3
0    0  0  x  0
1    0  0  0  x
2    0  x  0  0
3    x  0  0  0
*/
