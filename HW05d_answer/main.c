//10772 - The number of occurrences
//這是老師的寫法

#include <stdio.h>
#include <string.h>
int main(void)
{
	char A[5];
	char B[10];
	int i, k, n;
	int found, count, maxcount;
	scanf("%s", A);
	scanf("%d", &n);

	maxcount = 0;

	while (n>0) {
		scanf("%s", B);
		count = 0;
		for (i=0; i<=strlen(B)-strlen(A); i++) {
			found = 1;
			for (k=0; k<strlen(A); k++) {
				if (A[k] != B[i+k]) {
					found = 0;
					break;
				}
			}
			if (found) count++;
		}

		if (maxcount < count) maxcount = count;

		n--;
	}
	printf("%d", maxcount);
	return 0;
}
