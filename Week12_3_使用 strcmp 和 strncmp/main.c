#include <stdio.h>
#include <string.h>

int main(void)
{
char str1[30];
char str2[30];
int n;

scanf("%29s", str1);
scanf("%29s", str2);

printf("strcmp(%s, %s) = %d\n", str1, str2, strcmp(str1, str2));
/*strcmp(str1, str2)Ҳ���ǡ�str C compare��
���^�ִ��Ĵ�С��͸�^ǰ��p����(str1-str2)�����0����һ�Ӵ�
һ����f�؂��Ĕ�ֵ���o���_���_�д���ʲ�N��
���ֻ����̖ؓ�����x��Ҳ����ֻ���Á�_��ǰ���߀�������
Ʃ����������
*/n = 3;
printf("strncmp(%s, %s, n) = %d\n", str1, str2, strncmp(str1, str2, n));
//strncmp(str1, str2, n)�t��ֻ���^ǰn����Ԫ�Ƿ�һ��



return 0;
}
