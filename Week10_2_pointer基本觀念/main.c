#include <stdio.h>
#include <stdlib.h>

int main()
{
      //����variable�n�̷ӭ쥻variable��type�ӫŧi
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
      //%p�Oprintf����(pointer)�ɱM�Ϊ������O
      printf("sizeof(a): %u sizeof(b): %u\n", sizeof(a), sizeof(b));
      //�b�o�x�q���W�A�Ҧ����O���骺�u���Сv���O�@�ӡu64�줸�j�p(8byte)����ơv
      printf("sizeof(*a): %u sizeof(*b): %u\n", sizeof(*a), sizeof(*b));
      //�����ǫ��ЩҥN���Ŷ��j�p�h�̷Ӹ�variable��type���Ҥ��P
      return 0;
}
