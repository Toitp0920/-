#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);

	char ch[9] = {'I' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H'};

	printf("%c%c%c",ch[x/100%9], ch[x/10%10%9] , ch[x%10%9]);
	//(x/100%9)�O��x���ʦ�Ʀr�A�����L������array���r���A�P�z(x/10%10%9)���Q��Ʀr�B(x%10%9)���Ӧ�Ʀr

	return 0;
}
