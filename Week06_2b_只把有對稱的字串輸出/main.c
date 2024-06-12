#include <stdio.h>
#include <string.h>
//找到最長的對稱字串輸出
int main()
{
    char str[1000];
    int i, j, m, n, k;
    int done;

    //a b c b a
    //0 1 2 3 4

    scanf("%s", str);
    for (n=strlen(str); n>0; n--) {
        done = 0;
        for (m=0; (unsigned int) m+n<=strlen(str); m++) {
            i = m;
            j = m+n-1;
            while (i < j) {
                if (str[i]==str[j]) {
                    i++;
                    j--;
                } else {
                    break;
                }
            }
            if ( i >= j ) {
                for (k=m; k<m+n; k++) printf("%c", str[k]);
                printf("\n");
                done = 1;
            }
        }
        if (done) break;
    }

    return 0;
}
