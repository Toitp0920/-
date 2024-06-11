#include <stdio.h>
int main(void)
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (b-a == c-b && d-c == c-b) {
		printf("%d %d", d + d-c, d-c);
	}	else {
		printf("%d %d", d * d/c, d/c);
	}
	return 0;
}
