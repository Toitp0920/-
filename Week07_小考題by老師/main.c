#include <stdio.h>
#include <stdlib.h>
//10767 - Find the maximum/minimum values
//這是老師寫的
int main(void)
{
	int maxval, maxi, maxj, minval, mini, minj;
	int i, m, n, x;
	scanf("%d%d", &m, &n);

	mini = minj = maxi = maxj = 0;

	scanf("%d", &x);
	maxval = minval = x;
	//把i=0 拿出來先做，for 從 i=1開始這樣可以把min值預設為第一個數
	for (i=1; i<m*n; i++) {
		scanf("%d", &x);
		if (x<minval) {
			minval = x;
			mini = i/n;
			minj = i%n;
		} else if (x>maxval) {
			maxval = x;
			maxi = i/n;
			maxj = i%n;
		} else {}
	}

	printf("%d %d", abs(mini-maxi) + abs(minj-maxj), maxval-minval);

	return 0;
}
