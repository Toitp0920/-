#include <stdio.h>
int HIT[10000];
int main()
{
    int N;  //�ж��ٹP�Y��Ҫݔ��
    int i, j, num;
    char tmp;
    char str[5];
    //ݔ����Y����string�ķ�ʽ�탦��(����}Ŀ���ܴ���"0012"֮ľ�̖)
    scanf("%d", &N);
    while (N>0)
    {
        scanf("%s", str);
        for (i=4; i>0; i--)
        {
            //��ݔ����Y����С��������
            for (j=1; j<i; j++)
            {
                if (str[j-1] > str[j])
                {
                    tmp = str[j];
                    str[j] = str[j-1];
                    str[j-1] = tmp;
                }
            }
        }
        //֮�ጢÿ��string�Y���D�Q�ɔ�ֵ�Y��
        //str"1234" => 1234 num
        num = 0;
        for (i=0; i<4; i++)
        {
            num = num*10 + str[i]-'0';   //�@���^����1����*10���Σ�2�ɴ�...����׃��1234
        }

        HIT[num]++; //���һ�����ֳ��Fһ�Σ��t�ǂ����ֵĸ��Ӿ͏�0�_ʼ+1�������@������������F�״�
        N--;
    }

    for (i=0; i<10000; i++)
    {
        if (HIT[i]>1)
        {
            printf("%04d\n", i);    //0����ӡ����λ�����������ǰ���a0
        }
    }

    return 0;
}
