/*
如何透過檔案來輸入輸出(File IO)：
freopen跟fopen的差別
freopen是將標準輸入stdin改成用某檔案輸入
因此檔案來源只能有一個檔案(就是拿那個檔案來取代stdin的意思)
但如果已經確定輸入的方式是透過檔案了
此時fscanf可以自訂要從哪個甚至多個不同的檔案輸入資料
*/
#include <stdio.h>
int data[100000];
int main (void)
{
    FILE *fin, *fout; //先定義兩個指標variable，他們可以把檔案的記憶體位置存起來
    int i, j, tmp;
    int num_data;

    //fin是個指標variable，這裡用fopen拿到該檔案的pointer存到fin
    fin = fopen ("D:\\programming\\C\\Week12_2_File IO(透過檔案來輸入輸出)\\data_50000.txt", "r");
    //用兩條反斜線的原因是：在雙引號內使用反斜線後，下一條反斜線才是反斜線的意思(去除\n的可能性)

    //這裡選擇要從哪個地址取得輸入的資料，輸入了什麼，輸入存到哪裡
    fscanf (fin, "%d", &num_data);

    for (i = 0; i < num_data; i++)
    {
        fscanf (fin, "%d", &data[i]); //繼續把50000筆資料都輸入
    }
    //開始insertion sort
    for (i = 1; i < num_data; i++)
    {
        j = i;
        tmp = data[j];

        while (j > 0 && data[j - 1] > tmp)
        {
            data[j] = data[j - 1];
            j--;
        }

        data[j] = tmp;
    }


    fout = fopen ("data_50000_sorted.txt", "w");
    fprintf (fout, "%d\n", num_data);

    for (i = 0; i < num_data; i++)
    {
        fprintf (fout, "%d ", data[i]);
    }

    return 0;
}
