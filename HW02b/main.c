#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);

	char ch[9] = {'I' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H'};

	printf("%c%c%c",ch[x/100%9], ch[x/10%10%9] , ch[x%10%9]);
	//(x/100%9)是取x的百位數字，並讓他對應到array的字母，同理(x/10%10%9)取十位數字、(x%10%9)取個位數字

	return 0;
}
