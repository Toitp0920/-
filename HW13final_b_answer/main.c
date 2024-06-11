//10889 - Dictionary subsearch
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char A[1000][101];
char B[10];
int cmp(char str1[], char str2[], int len1, int len2)
{
    int i, j;
    if (len1<len2) return 0;
    else {
        for (i=0; i+len2<=len1; i++) {
            for (j=0; j<len2; j++) {
                if (tolower(str1[i+j])!=tolower(str2[j])) {
                    break;
                }
            }
            if (j==len2) return 1;
        }
        return 0;
    }
}
int main(void)
{
    int n, i;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%s", A[i]);
    }

    scanf("%s", B);

    for (i=0; i<n; i++) {
        if (cmp(A[i], B, strlen(A[i]), strlen(B))) {
            printf("%s\n", A[i]);
        }
    }

    return 0;
}
