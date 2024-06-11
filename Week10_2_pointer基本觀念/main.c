#include <stdio.h>
#include <stdlib.h>

int main()
{
      //指標variable要依照原本variable的type來宣告
      int x;
      int * a;

      double y;
      double * b;

      a = &x;
      *a = 100;

      b = &y;
      *b = 3.14;

      printf("x: %d\n", x);
      printf("y: %f\n\n", y);

      printf("a = &x: %p\nb = &y: %p\n\n", a, b);
      //%p是printf指標(pointer)時專用的的型別
      printf("sizeof(a): %u sizeof(b): %u\n", sizeof(a), sizeof(b));
      //在這台電腦上，所有的記憶體的「指標」都是一個「64位元大小(8byte)的資料」
      printf("sizeof(*a): %u sizeof(*b): %u\n", sizeof(*a), sizeof(*b));
      //但那些指標所代表的空間大小則依照該variable的type有所不同
      return 0;
}
