//10896 - Number Chains
#include <stdio.h>
#include <string.h>
int seen[2000];

int str2int(char str[])
{
	int i;
	int num = 0;
	for (i=0; i<strlen(str); i++) {
		num = num*10 + str[i]-'0';
	}
	return num;
}

void int2str(int n, char str[])
{
	int i = 0, j, tmp;
	while (n>0) {
		str[i] = n%10 + '0';
		n = n/10;
		i++;
	}
	str[i] = '\0';
	j = 0;
	i--;
	while (j<i) {
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
	}
}
void sortstr(char str[], int dir)
{
	int i, j;
	char tmp;
	int len = strlen(str);

	for (i=0; i<len-1; i++) {
		for (j=0; j<len-i-1; j++) {
			if (dir*str[j]<dir*(str[j+1])) {
				tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;
			}
		}
	}

}
int notseen(int n, int chainlen)
{
	int i;
	for (i=0; i<chainlen; i++) {
		if (n==seen[i]) return 0;
	}
	return 1;
}
int main(void)
{
	char str[10];
	int a, b, n;
	int chainlen;
	while (1) {
		scanf("%s", str);
		n = str2int(str);
		if (n==0) break;
		chainlen = 0;
		seen[chainlen] = n;
		chainlen++;
		while (1) {
			sortstr(str, 1);
			a = str2int(str);
			sortstr(str, -1);
			b = str2int(str);
			n = a-b;
			if (notseen(n, chainlen)) {
				seen[chainlen] = n;
				chainlen++;
				int2str(n, str);
			} else {
				break;
			}
		}
		printf("%d\n", chainlen);
	}

	return 0;
}
