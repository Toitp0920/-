#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30];
    char str2[30];
    char str3[60];


    scanf("%29s", str1);
    scanf("%29s", str2);

    /*
    strcpy(str3, str1); //��str1�}�u�浽str3
    strcat(str3, str2); //��str2�ӵ�str3����
    //ͨ�^�����@���У��Y�����飺st1+st2����һ��
    printf("%s\n", str3);
    */

    //Ҳ����ָ�}�u����һ��
    strcpy(str3, str1); //�@��׌str3=str1
        //printf("%s\n", str3);
    strncpy(str3, str2, 2); //��str2��str3��ǰ2����Ԫ�w����Ҳ����׌str3 = str2��ǰ�ɂ��ֶ���
        //printf("%s\n", str3);
    strcat(str3, str2); //Ȼ�����������str2һ��
    printf("%s\n", str3);




    return 0;
}
