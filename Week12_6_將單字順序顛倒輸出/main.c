/*
ݔ��һ��Ӣ�ľ����ִ�
��������Ӣ�Ć���
ÿ��Ӣ�Ć���֮�g�Æ΂��հ���Ԫ���_
�]���������c��̖
����
this is a book

Ո�ó�ʽ������ľ����Ԇ��֞��λ���D��ݔ��
book a is this

�K�Ҳ�ʹ���~���array���ŽY��
*/
#include <stdio.h>
void flip(char* a, int k, int l);
int main()
{
    int i, j;
    char a[100];
    fgets(a, 99, stdin);//��ʲ�N��ʹ��scanf?
    //���scanf�����հ׾�ͣ���ˣ����҂���횱����҂�ݔ��Ŀհ�
    a[strlen(a)-1] = ' ';
    //�@�Ǟ��˰��҂�ݔ���"this is a book\n"�ĳ�"this is a book \0"(����һ���հ�������)

    j = 0;
    for (i=0; a[i]!='\0'; i++)
    {
        if (a[i] == ' ') //����x���հף�����ǰ���҂��ѽ��x��һ��������
        {
            flip(a, j, i-1); //��ǂ������ִ�
            j=i+1; //Ҫ��j���£��Ա�̎����һ������
        }
    }
    printf("%s\n", a);//���Կ����҂������������
    //�F���ٰу�����ȫ��ͳɹ���
    flip(a, 0, strlen(a)-2);
    printf("%s\n", a);
    return 0;
}
void flip(char* a, int k, int l)
{
    int tmp;
     for (; k<l; k++, l--)
    {
        tmp = a[k];
        a[k] = a[l];
        a[l] = tmp;
    }
}
/*�Dһ
 j   i
 k   l
 this is a book
*/
