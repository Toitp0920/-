/* W06_03
�ϥΪ̿�J�Q�n��ܪ�����Ϊ����שM�e��
��X�@�ӥ� * �c���B�ŦX�ϥΪ̿�J���j�p�������
�i�H�ϥ��B�~���ܼ� k
�]�i�H�u�Ψ� i �M j (�Q�� % �Ÿ����D�l�ƪ��B��)
��U���{���X ??? ��J���T���B�⦡
���{���i�H�F��w�����ĪG
*/
#include <stdio.h>
int main(void)
{
    int i, j, k;
    scanf("%d%d", &i, &j);

    k=j;
    for(i; i>=1; i--)
    {
        j=k;
        for (j; j>= 1; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
