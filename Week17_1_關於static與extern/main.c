/*
���� static �P extern

static

�u��ơv�e���p�G�[ static
��ܳo�Ө�Ƥ��|�Q linker �ݨ�
�]�����|�M��L�ɮ׳s��(���|��O���ɮצP�W��fuction�Ĩ�)

�u�ܼơv�e���p�G�[ static
��ܳo���ܼƱq�{���}�l����N�|�s�b
����{�������~�|����

extern

�u�b�@�ӭ�l�X�ɮפ��w�q
int x = 0;
��L��l�X�ɮצp�G�ϥ� x�A���ӫŧi��
extern int x;
*/
#include <stdio.h>

int f(void)
{
    int b = 0;
    b = b + 1;
    return b;
}
int g(void)
{
    static int a = 0;
    a = a + 1;
}
int main()
{
    printf("int b:\n%d\n",f());
    printf("%d\n",f());
    printf("%d\n",f());
    printf("%d\n\n",f());

    printf("static int a:\n%d\n",g());
    printf("%d\n",g());
    printf("%d\n",g());
    printf("%d\n",g());
    return 0;
}
