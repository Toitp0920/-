/*�g�X�@�ӨD�}����ڪ�function
�H�U�O�t��k�G
�DA
A*A=x
���ɦ���z*z>x
�h x / z �@�w>A
�o�� z > A > x/z
�N��N�OA����z��x/z����(�o��Ӫ�������)
���ɴN�i�H�ηs��z���s�G��@��
�Oz=( z + x/z )/2
���j
*/

#include <stdio.h>
double sqrt0(double x, double z);
int main()
{
        printf("%.12f\n",  sqrt0(3, 1.5));
        return 0;
}
double abs0(double y)
{
        return (y>0) ? y : -y;
        //�ǰ_�ӡI �u? y : -y�v�o�Ӽg�k���N��O
        //if(y>0) �hreturn y
        //else return -y
}

double sqrt0(double x, double z)
{
        if(abs0(z*z-x)<0.000001) return z;
        else
                return sqrt0(x, 0.5*(z+x/z));
}
//�o��return�ۤv���g�k(Ĵ�p����۰��k�]�O)
//�s��tail recursion
//�o��recursion�i�H�Qcompiler���̨Τ�
//�]�N�O���A�O�d�̪쪺�ѼơA�u�O�d�s���ѼơA�]�����׬ۦP
