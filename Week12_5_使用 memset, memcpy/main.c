#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(void)
{
int a[SIZE];
int b[SIZE];
int i;

memset(a, 0, SIZE*sizeof(int));
/*�@��memset function�ǰ�ĳarray�e����Y��ȫ�����ĳ���ݣ�Ʃ��0
memset(Ҫ���array, ���ʲ�N����, �@��array�Ĵ�С�Ўׂ�byte)
��������ֱ����sizeof(int)����SIZEֱ�ӎ�����
�@�ӾͲ��Ì�ޒȦ���������
��ע�⣡����ĳ�1���t����ÿ��byte����1��
Ҳ����array�e��ÿ1����"1111"
���int ��4��byte
����һ�㶼���Á�ĳ�0���char array�������x
*/
for (i=0; i<SIZE; i++) {
printf("%d ", a[i]);
if ((i+1)%10 == 0) printf("\n");
}

for (i=0; i<SIZE; i++) {
a[i] = i*i;
}

memcpy(b, a, SIZE*sizeof(int)); //��b = a��Ҳ���ǰ�a�}�u��b
for (i=0; i<SIZE; i++) {
printf("%5d", b[i]);
if ((i+1)%10 == 0) printf("\n");
}

return 0;
}
