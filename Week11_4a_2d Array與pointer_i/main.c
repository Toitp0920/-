//�ݫ�2d array������Ppointer
#include <stdio.h>
typedef int row_vector[5];
/*
�N��O��urow_vectop�v�w�q���@�ӷs��type�A�ڭ̥i�H�ΥL�ӫŧi�@��variable��array
�ӳo��type�O��5��int�c�����F��
*/
int main()
{
    /*
    �H�Urow_vector M[4]�N����O�@��
    int M[4][5]��2d array�F
    �]��row_vector M[0]���Ŷ���ܦp�U�G
    M[0]={0, 1, 2, 3, 4}
    M[1]={0, 1, 2, 3, 4}
    M[2]={0, 1, 2, 3, 4}
    M[3]={0, 1, 2, 3, 4}
    */
    /*
    �ڭ̤]���Ӥ�ӳo�ث���ݫ�2d array
    �]�N�O���A��ݨ�a[4][5]��
    ���T��������ӬO�G
    �u��4��[��5�Ӿ�ƺc��]���Фl�vO
    �Ӥ��O
    �u��4x5=20�ɩФl�vX
    */
    row_vector M[4];
    int a[10];

    row_vector* pM;
    int* pa;


    pM = M;
    pa = a;

    printf("pa: %p pa+1: %p\n", pa, pa+1);
    printf("pM: %p pM+1: %p\n\n", pM, pM+1);

    /*
    �p�G�O�n��m[4][5]�o��2d array�w�q�@�ӫ���variable
    �N���ӥγo�˪����
    �H�U�N�O�w�q�@��variable pm
    ���ɳo��pm�O�u5�Ӿ�Ƥj�p����쪺�Ŷ��v
    �`�N�ŧi�ɪ��g�k�I
    */
    int m[4] [5];
    int (*pm)[5];
    //����N�򤧫e�@�˥i�H��pm��@����variable�ӥ�
    pm = m;
    printf("&m: %p m+1: %p\nsize of m: %d\n", m, &m+1, sizeof(m));
    printf("pm: %p pm+1: %p\nsize of pm: %d\n", pm, pm+1, sizeof(pm));
    return 0;
}
