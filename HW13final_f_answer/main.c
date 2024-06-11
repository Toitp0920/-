//10898 - Enemy at the gates
#include <stdio.h>
int A[52][52];
int main(void)
{
    int N, i, j;
    int B, count;
    scanf("%d", &N);
    for (i=1; i<=N; i++) {
        for (j=1; j<=N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d", &B);
    while (B>0) {
        scanf("%d%d", &i, &j);
        A[i][j] = 0;
        B--;
    }
    for (i=1; i<=N; i++) {
        count = 0;
        for (j=1; j<=N; j++) {
            if (A[i][j]==1) count++;
            if (A[j][i]==1) count++;
        }
        if (count==0) printf("%d\n", i);
    }
    return 0;
}
