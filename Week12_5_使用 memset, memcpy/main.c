#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(void)
{
int a[SIZE];
int b[SIZE];
int i;

memset(a, 0, SIZE*sizeof(int));
/*這個memset function是把某array裡存的資料全部清成某內容，譬如0
memset(要清的array, 清成什麼內容, 這個array的大小有幾個byte)
可以如上直接用sizeof(int)乘上SIZE直接幫你算
這樣就不用寫迴圈來清內容了
但注意！如果改成1，則代表每個byte都是1，
也就是array裡面每1格都是"1111"
因為int 有4個byte
所以一般都是用來改成0或改char array才有意義
*/
for (i=0; i<SIZE; i++) {
printf("%d ", a[i]);
if ((i+1)%10 == 0) printf("\n");
}

for (i=0; i<SIZE; i++) {
a[i] = i*i;
}

memcpy(b, a, SIZE*sizeof(int)); //令b = a，也就是把a複製到b
for (i=0; i<SIZE; i++) {
printf("%5d", b[i]);
if ((i+1)%10 == 0) printf("\n");
}

return 0;
}
