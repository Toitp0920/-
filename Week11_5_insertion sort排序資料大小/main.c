/*insertion sort
先從檔案讀取資料，存入陣列 data 中。
接著利用 insertion sort 的方法，將資料排序，
由小到大存放在 data 陣列中。
*/
#include <stdio.h>

int data[100000];
int main()
{
    int count = 0;
    int i, j, tmp;
    int num_data;
    //輸入資料
    freopen("data_50000.txt", "r", stdin);
    freopen("data_50000_sorted.txt", "w", stdout);  //把排完的存到這裡
    scanf("%d", &num_data);
    for (i = 0; i < num_data; i++)
        scanf("%d", &data[i]);
    //以下是insertion sort的排列方式：
    /*
    這個寫法不好 但邏輯是這樣
    for (i = 1; i < num_data; i++)
    {
        j = i;
        while (j > 0 && data[j-1] > data[j])
        {
            tmp = data[j];
            data[j] = data[j-1];
            data[j-1] = tmp;
            j--;
        }

    }
    */

    //可以改進成這種寫法：
    for (i=0; i<num_data; i++)
    {
        j = i;
        tmp = data[j];
        while (j>0 && tmp<data[j-1])
        {
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }
    //輸出結果
    for (i = 0; i < num_data; i++)
        printf(" %d", data[i]);
    return 0;
}
