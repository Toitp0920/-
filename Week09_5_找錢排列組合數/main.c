/*
Make Change
��J���P���Ȫ��ɪO
�M���J�@�Ӫ��B
�N�����i�઺��s�覡�C�X
Ĵ�p�� 1 ���B5���B10���ɪO
�n��X 17 ��
�p�G�N�i�઺�զX��ܦ� "(1���Ӽ�,5���Ӽ�,10���Ӽ�)"
�`�@�|���U�C�X�ؤ�k
(2,1,1)
(2,3,0)
(7,0,1)
(7,2,0)
(12,1,0)
(17,0,0)
*/
#include <stdio.h>
#define MaxCN 5         //Max coin number
int coin[MaxCN];        //={1, 5, 10, 50, 100}����������
int cn[MaxCN];          //={2, 1, 1, 0, 0} �������w���ƶq�զX��
void display(int n);
void change(int Money, int seq, int n);

int main()
{
        int n, i, money;
        scanf("%d", &n);

        if(n>MaxCN || n<1) return 0;

        for(i=0; i<n; i++)
                scanf("%d", &coin[i]);
        scanf("%d", &money);
        change(money, 0, n);
        return 0;
}

void display(int n)
{
        int i;
        printf("(%d", cn[0]);
        for(i=1; i<n; i++)
                printf(", %d", cn[i]);
        printf(")");
}
void change(int Money, int seq, int n)
{
        if(seq<n)       //�פ����O�ѤF�I
        {
                if(Money==0)
                        display(n);
                else if(Money>0)
                {
                        cn[seq]++;
                        change(Money-coin[seq], seq, n);
                        cn[seq]--;
                        change(Money, seq+1, n);
                }
        }
}
