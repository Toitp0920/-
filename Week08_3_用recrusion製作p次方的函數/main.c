/*
���q [�m�� W09_05]�A�ŧi double power(double n, int p); �A�M��ϥΤU�����覡�Ӱ����j:
(0) ���ˬd p �O�_���� 0�A�O���ܴN�Ǧ^���� 1; �Y p ������ 0 �h����X ans = power(n, p/2);
(1) �p�G p �O���ơA�h return ans*ans;
(2) �p�G p �O�_�ơA�h return n*ans*ans;
�o�̦��ϥΨ��ư��k�L����˥h���S�ʡC
*/
#include <stdio.h>
double power(double n, int p);

int main()
{
        double n;
        int p;
        scanf("%lf%d", &n, &p);
    printf("%lf\n", power(n, p));
    return 0;
}

double power(double n, int p)
{
        double ans;

        if(p==0) return 1;
        else ans = power(n, p/2);

        if(p%2==0) return ans*ans;
        else return n*ans*ans;
}
