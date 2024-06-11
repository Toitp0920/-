/* E10_15.c
�ڳ�ʽ�������g�ńӑBȡ��ӛ���w���g
����һ�_ʼ����ʹ�ö���ӛ���w
1.ʹ�á�malloc(��Ҫ���ق�byte�Ŀ��g)�� �@��function
2.�@function��������<stdlib.h>�e��� (Standard library)
3.�@������ȡ�õ�ӛ���w�K�]�б����и��Ҳ����ϵ�y��֪����Ҫ���@Щӛ���w�e���ʲ�N�̈́e���Y��
4.Ҫ��ǰ���ṩ�̈́e����
5.�K����һ��ָ��variable��ȡ���@��array���_�^��ַ
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double *ptd; //���@��ָ��variable��ӛסȡ�õ�array���_�^��ַ
    int array_size, i;

    printf("How many doubles do you want? ");
    scanf("%d", &array_size);  //���O�҂�ݔ���҂���Ҫ10000��double���g
    ptd = (double *) malloc(array_size * sizeof(double));
    //                           10000 * sizeof (double) = 8 byte
    //(double *) (Ҫ��ĳ���̈́e�ķ�ʽ����@һ��K���g���и�)
    if (ptd == NULL) //NULL�䌍����0�������˷����˽��������x���Ԍ�NULL��Ҳ����Ҫ����ӛ���w
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);//�@����ֱ�ӽY����ʽ��������main���������return��0
    }

    for (i = 0; i < array_size; i++)
    {
        ptd[i] = (double) rand() / RAND_MAX;
        //rand()ÿ�κ����@�������r���a��һ��0~32767�āy�������׺����Ҳ���Ҏ�t�ģ���ֻ�Ǻ��y��Ҏ�ɣ�����ʽ����߀�Ǜ]���������x�āy����
    }   //RAND_MAX��32767
    for (i = 0; i < array_size; i++)
    {
        if (*(ptd+i) > 0.5)
            printf("%d: %f\n", i, ptd[i]);
    }

    free(ptd);
    //���@�����gጷŵ�����������Єe�ĳ�ʽ�a���������e�����飬�����^�m����Ҫ�r��Ҫӛ���w

    return 0;
}
