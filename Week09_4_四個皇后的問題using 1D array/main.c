/*
�|~�K�ӬӦZ�����D
�ӦZ�i�H����������
�]�i�H���׹﨤
�p��b 4x4~8x8 ���ѽL�W�\��|~�K�ӬӦZ
�ϱo�o�̤��|���۽Ĭ�
*/
//using 1D array
#include <stdio.h>
#define MaxN 8
int a[MaxN];
int count;
//�o�ӥi�H�p���`�@���h�ָ�

void display(void);
void place(int n);

int main()
{
        place(0);
        printf("�@�� %d �Ӹ�", count);
        return 0;
}

void display(void)
{
        int i, j;
        count++;
        //�C���o��display()�Q�I�s���ɭԡA���O���@���Ѧh�@��
        for(i=0; i<MaxN; i++)
        {
                for(j=0; j<MaxN; j++)
                {
                        if(j==a[i]) printf("��");
                        else printf("��");
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
