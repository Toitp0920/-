/*insertion sort
���q�ɮ�Ū����ơA�s�J�}�C data ���C
���ۧQ�� insertion sort ����k�A�N��ƱƧǡA
�Ѥp��j�s��b data �}�C���C
*/
#include <stdio.h>

int data[100000];
int main()
{
    int count = 0;
    int i, j, tmp;
    int num_data;
    //��J���
    freopen("data_50000.txt", "r", stdin);
    freopen("data_50000_sorted.txt", "w", stdout);  //��Ƨ����s��o��
    scanf("%d", &num_data);
    for (i = 0; i < num_data; i++)
        scanf("%d", &data[i]);
    //�H�U�Oinsertion sort���ƦC�覡�G
    /*
    �o�Ӽg�k���n ���޿�O�o��
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

    //�i�H��i���o�ؼg�k�G
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
    //��X���G
    for (i = 0; i < num_data; i++)
        printf(" %d", data[i]);
    return 0;
}
