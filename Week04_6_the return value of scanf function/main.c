/* 範例 E06_01.c */
#include <stdio.h>
int main(void)
{
    int num;
    int sum = 0;
    int status;

    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    status = scanf("%d", &num); /* %ld for long */
    //當scanf輸入成功，其實會回傳一個1值，將此回傳值存入status
    printf("status: %d\n", status);
    while (status == 1)          /* == means "is equal to" */
    {       //如果只寫一個=，則代表「status = 1; 」，此迴圈將不會停止
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%d", &num);
        /* printf("status: %d\n", status); */
    }
    printf("Those integers sum to %d.\n", sum);

    return 0;
}
