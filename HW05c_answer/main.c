#include <stdio.h>
//10770 - Coordinate Format
//�o�O�Ѯv���g�k
int main(void)
{
	int m, n, i, x;
	scanf("%d%d", &m, &n);
	for (i=0; i<m*n; i++) {
		scanf("%d", &x);
		if (x!=0) {
			printf("%d %d %d\n", i/n, i%n, x);
		}
	}
	return 0;
}
