/* E05_07.c */
#include <stdio.h>
//字元與數字的對照(ASCII)
int main(void)
{
   char i , j ;
    scanf("%c %c", &i,&j );
    /*兩個%c中間一定要有空格，
    代表%c與%c中間，可以輸入無限多個空格都會被忽視
    而不會被當作是一個char「空白字元」
    */
   while (i <=j) {
      printf("  %c", i);
      i++;
   }
   return 0;
}
