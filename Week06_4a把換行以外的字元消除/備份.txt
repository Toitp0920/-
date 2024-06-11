#include <stdio.h>
//讓電腦猜數字
int main(void)
{
   int guess = 1;

   printf("Pick an integer from 1 to 100. I will try to guess it.\n");
   printf("Respond with a y if my guess is right and with an n if it is wrong.\n");
   printf("Uh...is your number %d?\n", guess);
   while (getchar() != 'y')
   {
           printf("Well, then, is it %d?\n", ++guess);
           while(getchar()!='\n');
           //如果沒有這個while，則printf("Well, then, is it %d?\n", ++guess);就會被執行多少次
           //這樣當我們輸入任何換行以外的字元，這個while都會幫我們「不做任何事」
           //直到輸入了換行，程式才會離開這個while繼續執行
   }


   printf("I knew I could do it!\n");

   return 0;
}
