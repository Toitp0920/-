//10769 - Two-dimensional array rotation
//這是老師的寫法
#include <stdio.h>

int main(void)
{
	int A[20][20];
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (i=0; i<n; i++) {
	    printf("%d", A[i][0]);
		for (j=1; j<=i; j++) {
			printf(" %d", A[i-j][j]);
		}
		printf("\n");
	}

	for (i=n-2; i>=0; i--) {
	    printf("%d", A[n-1][n-1-i]);
		for (j=1; j<=i; j++) {
			printf(" %d", A[n-1-j][n-1-(i-j)]);
		}
		printf("\n");
	}

	return 0;
}
