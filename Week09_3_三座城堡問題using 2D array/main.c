/*
�λ��j�D�T�y�������D�G
�b 3x3 ���ѽL�W�\�T�ӫ���
���������u
�ҥH�C�� row �u���\�@�ӫ���
�ק侀�U���{���X
�ϱo�̫�u��X���������Ĭ��\�k
*/
//�ϥ�2D(two dimension) array
#include <stdio.h>

int a[10][10]= {0};
void display(void);
void place(int n);
//int valid(int i, int j);
//�]���o�Ө�ƬO�u��place��ƥΪ��Amain�̭����ݭn�ݨ�valid�ҥH���μgprototype�b�e��
int count;
int main()
{
        //int n;
        //scanf("%d", &n);
        place(1);
        printf("�@��%d�Ӹ�", count);
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
