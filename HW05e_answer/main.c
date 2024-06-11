#include <stdio.h>
int main(void)
{
	int A, B;
	int n;
	char move;
	int amount;
	scanf("%d%d", &A, &B);
	scanf("%d", &n);
	while(getchar()!='\n');

	while (n>0) {
		scanf("%c%d", &move, &amount);
		while(getchar()!='\n');

		if (move == 'A') {
			A = A*1.08 - amount;
			B = B*1.08 + amount;
		} else {
			A = A*1.08 + amount;
			B = B*1.08 - amount;
		}
		n--;
	}
	printf("%d %d\n", A, B);
	return 0;
}
