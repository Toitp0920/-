#include <stdio.h>
#include <string.h>
int main()
{
        char A[5];
        unsigned int n;
        char str[10];
        unsigned int result[10]= {0};
        int i, j, k;
        int biggest;

        char temp[10];

        scanf("%s %u", A, &n);

        unsigned int la, ls;
        la=strlen(A);


        for(k=0; k<n; k++)
        {
                scanf("%c", str);
                ls=strlen(str);

                while(i+la <=11)
                {
                        for(i=0; i<=10; i++)
                        {
                                temp[i]=str[i];
                        }
                        temp[i+la]=0;
                        if(A==str)
                        {
                                result[k]++;
                        }
                        temp[i]=0;
                }

        }
        biggest = result[1];
        for(i=1; i<=10; i++)
        {
                if(result[i]>result[1])
                        biggest =result[i];
        }
        printf("%d", biggest);
        return 0;
}
