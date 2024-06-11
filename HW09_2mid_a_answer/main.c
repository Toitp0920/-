#include <stdio.h>

int main(void)
{
	int H, W, T;
	int row = 3, col = 1;
	int dr=-1, dc=1;
	int stop = 0;
	scanf("%d%d", &H, &W);
	scanf("%d%d", &row, &col);
	scanf("%d", &T);
	while (!stop && T>1) {
		row = row + dr;
		col = col + dc;
		if ( (row==1&&col==1) ||
			 (row==1&&col==W) ||
			 (row==H&&col==1) ||
			 (row==H&&col==W)) stop = 1;
		else if (row==1 || row==H) { dr = -dr; T--; }
		else if (col==1 || col==W) { dc = -dc; T--; }

	}

    printf("(%d,%d)", row, col);
	return 0;
}
