#include <stdio.h>
//�p��s�@������
/*
�@��g�n�@�q�{����A�ڭ̭n��ʿ�J�@�Ǹ�����L�]�ݬ�
���ǨC�����n��J�����ո��²�ٴ���A�H�U���d��
*/
/*
8
5 10 15 20 25 30 35 40
*/
int main()
{
        int i, n, sum;
        int a[50];
        freopen("D:\\Programming\\testla.txt", "r", stdin);
        //Ū���GF re-open
        freopen("output.txt", "w", stdout);
        /*
        �A���������G
        1."�����ɪ��ɦW"�A�p�G�S�����w���|�AĴ�p"D:\\Programming\\testla.txt"
                �h�w�]���M�שҦb����Ƨ����C
                (Notice that you should always use "double back slash" in the path)
        2."r"�N��read�A���Ū���A�]�N�O�쥻���зǿ�J(stdin)�O�j�w��L���A
                �{�b�令�Ѧ��ɮ׿�J
           "w"�N��write�A��ܼg�J�A�쥻���зǿ�X(stdout)�O�b�ù��W�A
                �{�b���X�즹�ɮ�
        3.stdin means "Standard Input"(�зǿ�J)
           stdout means "Standard Output"(�зǿ�X)
        */

        scanf("%d", &n);

        for (i = 0; i<n; i++)
        {
                scanf("%d", &a[i]);
        }

        for (i = 0, sum = 0 ; i<n ; i++)
        {
                sum = sum+a[i];
        }

        printf("Total = %d", sum);

        return 0;
}
