/*
�p��z�L�ɮרӿ�J��X(File IO)�G
freopen��fopen���t�O
freopen�O�N�зǿ�Jstdin�令�άY�ɮ׿�J
�]���ɮרӷ��u�঳�@���ɮ�(�N�O�������ɮרӨ��Nstdin���N��)
���p�G�w�g�T�w��J���覡�O�z�L�ɮפF
����fscanf�i�H�ۭq�n�q���ӬƦܦh�Ӥ��P���ɮ׿�J���
*/
#include <stdio.h>
int data[100000];
int main (void)
{
    FILE *fin, *fout; //���w�q��ӫ���variable�A�L�̥i�H���ɮת��O�����m�s�_��
    int i, j, tmp;
    int num_data;

    //fin�O�ӫ���variable�A�o�̥�fopen������ɮת�pointer�s��fin
    fin = fopen ("D:\\programming\\C\\Week12_2_File IO(�z�L�ɮרӿ�J��X)\\data_50000.txt", "r");
    //�Ψ���ϱ׽u����]�O�G�b���޸����ϥΤϱ׽u��A�U�@���ϱ׽u�~�O�ϱ׽u���N��(�h��\n���i���)

    //�o�̿�ܭn�q���Ӧa�}���o��J����ơA��J�F����A��J�s�����
    fscanf (fin, "%d", &num_data);

    for (i = 0; i < num_data; i++)
    {
        fscanf (fin, "%d", &data[i]); //�~���50000����Ƴ���J
    }
    //�}�linsertion sort
    for (i = 1; i < num_data; i++)
    {
        j = i;
        tmp = data[j];

        while (j > 0 && data[j - 1] > tmp)
        {
            data[j] = data[j - 1];
            j--;
        }

        data[j] = tmp;
    }


    fout = fopen ("data_50000_sorted.txt", "w");
    fprintf (fout, "%d\n", num_data);

    for (i = 0; i < num_data; i++)
    {
        fprintf (fout, "%d ", data[i]);
    }

    return 0;
}
