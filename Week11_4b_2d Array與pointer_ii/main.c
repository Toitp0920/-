#include <stdio.h>

int main()
{
    int i, j;
    int m[4][5];
    int ( *p )[5];
    for ( i = 0; i < 4; i++ )
    {
        for ( j = 0; j < 5; j++ )
            m[i][j] = i * j;
    }
    p = m;
    printf( "m[3][2]: %d\n\n", m[3][2] );

    printf( "pm[3][2]: %d\n", p[3][2] ); //p = m
    printf( "*(pm[3]+2)): %d\n", *(p[3]+2) ); //��᭱�����A�������t�@�ت�ܪk�i�H
    printf( "*(*(pm+3)+2): %d\n", *(*(p+3)+2) );//�A��p[3]���g�k�]�令pointer���g�k
    printf( "*(pm+3)[2]: %d\n", *(p+3)[2] ); //��e���������o�ӬO���檺

    //pm+3�N��pm�}�l����5+5+5�ɩФl�A[2]�N���ح�����2��

//�t�~����H�U��Ӥ��e
    int* pA[5];
    int (*pB)[5];
    /*
    �W������ܤ@��pointer array pA[5]
    pA[0]~pA[4]�̭��˪��F�賣�O�@�Ӧa�}
    �U������ܤ@��pointer variable pB
    pB�̭�����Ƥj�p���O5��int ���@�ӳ�� �̭��˪��]�Oint �ӫD�a�}
    */
}
