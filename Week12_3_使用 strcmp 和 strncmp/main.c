#include <stdio.h>
#include <string.h>

int main(void)
{
char str1[30];
char str2[30];
int n;

scanf("%29s", str1);
scanf("%29s", str2);

printf("strcmp(%s, %s) = %d\n", str1, str2, strcmp(str1, str2));
/*strcmp(str1, str2)也就是「str C compare」
比較字串的大小，透過前面減後面(str1-str2)，因此0代表一樣大
一般來說回傳的數值因為無法確定確切代表什麼，
因此只有正負號有意義，也就是只能用來確定前面大還是後面大
譬如排序姓名
*/n = 3;
printf("strncmp(%s, %s, n) = %d\n", str1, str2, strncmp(str1, str2, n));
//strncmp(str1, str2, n)則是只比較前n個字元是否一樣



return 0;
}
