#include <stdio.h>

int main(void)

{

    char *str1[] = {"piece", "of", "cake"}; //str1[] = str1[3]
    /*�@�ǵ�һ�N����
    �@�����ִ���ӛ���w��Ҋ�����B�m��
    ����錑char* ��˿����õ��@�����ֵĵ�ַ
    ��ÿ����ַ�Ĵ�С����8byte��Ҳ�����@Щ���� 8*3 = 24byte
    */
    char str2[][8] = {"piece", "of", "cake"}; //str2[][8] = str2[3][8]
    /*�@�ǵڶ��N����
    �@�����ִ���ӛ���w���B�m�� |piece\n--|of\n-----|cake\n---|
    ��ÿ���С�Ԟ�8*1byte�����񿂹�8*3 = 24byte
    */
    int i, j;

    //printf("str1: %u, str2: %u\n", sizeof(str1), sizeof(str2));
    /*    //��ʹ���Ͽ����������Ĳ�e��
        for(i=0; i<3; i++) printf("%s\n", str1[i]);
        for(j=0; j<3; j++) printf("%s\n", str2[j]);
    */

    //��һ��һ��ӡ����Ϳ�����ͬ��
    for (i=0; i<3; i++)
    {
        for (j=0; j<8; j++) //����ӡ��8����Ԫ
            printf("%c", str1[i][j]);
        printf("\n");
    }

    for (i=0; i<3; i++)
    {
        for (j=0; j<8; j++) //����ӡ��8����Ԫ
            printf("%c", str2[i][j]);
        printf("\n");
    }

    return 0;

}
