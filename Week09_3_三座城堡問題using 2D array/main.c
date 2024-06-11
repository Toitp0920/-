/*
用遞迴求三座城堡問題：
在 3x3 的棋盤上擺三個城堡
城堡走直線
所以每個 row 只能擺一個城堡
修改底下的程式碼
使得最後只輸出滿足互不衝突的擺法
*/
//使用2D(two dimension) array
#include <stdio.h>

int a[10][10]= {0};
void display(void);
void place(int n);
//int valid(int i, int j);
//因為這個函數是只給place函數用的，main裡面不需要看到valid所以不用寫prototype在前面
int count;
int main()
{
        //int n;
        //scanf("%d", &n);
        place(1);
        printf("共有%d個解", count);
        return 0;
}

void display(void)
{
        int i, j;
        count++;
        //printf("\n");
        for(i=1; i<=8; i++)
        {
                for(j=1; j<=8; j++)
                        printf(" %d", a[i][j]);
                printf("\n");
        }
        printf("\n");
}
int valid(int row, int col)
{
        int i;
        for(i=1; i<row; i++)
            if(a[i][col]==1) return 0;
        return 1;
}
void place(int n)
{
        int j;
        if(n>8)
                display();
        else
                for(j=1; j<=8; j++)
                {
                        if(valid(n, j))
                        {
                                a[n][j]=1;
                                place(n+1);
                                a[n][j]=0;
                        }
                }
}
