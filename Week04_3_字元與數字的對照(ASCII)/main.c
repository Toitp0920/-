/* E05_07.c */
#include <stdio.h>
//�r���P�Ʀr�����(ASCII)
int main(void)
{
   char i , j ;
    scanf("%c %c", &i,&j );
    /*���%c�����@�w�n���Ů�A
    �N��%c�P%c�����A�i�H��J�L���h�ӪŮ泣�|�Q����
    �Ӥ��|�Q��@�O�@��char�u�ťզr���v
    */
   while (i <=j) {
      printf("  %c", i);
      i++;
   }
   return 0;
}
