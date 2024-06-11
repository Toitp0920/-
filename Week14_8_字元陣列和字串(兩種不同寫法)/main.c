#include <stdio.h>

int main(void)

{

    char *str1[] = {"piece", "of", "cake"}; //str1[] = str1[3]
    /*這是第一種寫法
    這三個字串的記憶體不見得是連續的
    但因為寫char* 因此可以拿到這三個字的地址
    而每個地址的大小都是8byte，也就是這些總共 8*3 = 24byte
    */
    char str2[][8] = {"piece", "of", "cake"}; //str2[][8] = str2[3][8]
    /*這是第二種寫法
    這三個字串的記憶體是連續的 |piece\n--|of\n-----|cake\n---|
    而每格大小皆為8*1byte，三格總共8*3 = 24byte
    */
    int i, j;

    //printf("str1: %u, str2: %u\n", sizeof(str1), sizeof(str2));
    /*    //光使用上看不出真正的差別：
        for(i=0; i<3; i++) printf("%s\n", str1[i]);
        for(j=0; j<3; j++) printf("%s\n", str2[j]);
    */

    //但一個一個印出來就看出不同了
    for (i=0; i<3; i++)
    {
        for (j=0; j<8; j++) //強迫印出8個字元
            printf("%c", str1[i][j]);
        printf("\n");
    }

    for (i=0; i<3; i++)
    {
        for (j=0; j<8; j++) //強迫印出8個字元
            printf("%c", str2[i][j]);
        printf("\n");
    }

    return 0;

}
