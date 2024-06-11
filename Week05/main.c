#include <stdio.h>
//如何製作測資檔
/*
一般寫好一段程式後，我們要手動輸入一些資料讓他跑看看
那些每次都要輸入的測試資料簡稱測資，以下為範例
*/
/*
8
5 10 15 20 25 30 35 40
*/
int main()
{
        int i, n, sum;
        int a[50];
        freopen("D:\\Programming\\testla.txt", "r", stdin);
        //讀做：F re-open
        freopen("output.txt", "w", stdout);
        /*
        括號內分為：
        1."測資檔的檔名"，如果沒有指定路徑，譬如"D:\\Programming\\testla.txt"
                則預設為專案所在的資料夾內。
                (Notice that you should always use "double back slash" in the path)
        2."r"代表read，表示讀取，也就是原本的標準輸入(stdin)是綁定鍵盤的，
                現在改成由此檔案輸入
           "w"代表write，表示寫入，原本的標準輸出(stdout)是在螢幕上，
                現在改輸出到此檔案
        3.stdin means "Standard Input"(標準輸入)
           stdout means "Standard Output"(標準輸出)
        */

        scanf("%d", &n);

        for (i = 0; i<n; i++)
        {
                scanf("%d", &a[i]);
        }

        for (i = 0, sum = 0 ; i<n ; i++)
        {
                sum = sum+a[i];
        }

        printf("Total = %d", sum);

        return 0;
}
