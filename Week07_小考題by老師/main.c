#include <stdio.h>
#include <stdlib.h>
//10767 - Find the maximum/minimum values
//�o�O�Ѯv�g��
int main(void)
{
	int maxval, maxi, maxj, minval, mini, minj;
	int i, m, n, x;
	scanf("%d%d", &m, &n);

	mini = minj = maxi = maxj = 0;

	scanf("%d", &x);
	maxval = minval = x;
	//��i=0 ���X�ӥ����Afor �q i=1�}�l�o�˥i�H��min�ȹw�]���Ĥ@�Ӽ�
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
