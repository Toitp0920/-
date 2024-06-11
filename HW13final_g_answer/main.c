//10899 - Find/Revision
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct{
    char Name[15];
    char Height[15];
    char Weight[15];
} Info;

Info *sorted[100];

int cmp(const void * a, const void *b)
{
    Info *u, *v;
    u = *(Info**)a;
    v = *(Info**)b;
    return strcmp(u->Name, v->Name);
}

void Find_Revise(Info* list, int num , char instr , int* isEnd )
{
    int i, n, jj, repeated;
    char name[20], h[20], w[20], key[20];
    if (instr=='F') {
        scanf("%s", key);
        jj = 0;
        for (i=0; i<num; i++) {
            if (strstr(list[i].Height, key)!=NULL ||
                strstr(list[i].Weight, key)!=NULL ||
                strstr(list[i].Name, key)!=NULL) {
                sorted[jj] = &list[i];
                jj++;
            }
        }
        if (jj==0) {
            printf("NOT FOUND\n");
        } else {
            qsort(sorted, jj, sizeof(Info*), cmp);
            for (i=0; i<jj; i++)
            printf("%-10s%-8s%-8s\n", sorted[i]->Name, sorted[i]->Height, sorted[i]->Weight);
        }

    } else if (instr=='R'){
        scanf("%d%s%s%s", &n, name, h, w);
        repeated = 0;
        for (i=0; i<num; i++) {
            if (strcmp(list[i].Name, name)==0) {
                strcpy(list[i].Name, "");
                strcpy(list[i].Height, "");
                strcpy(list[i].Weight, "");
                repeated = 1;
            }
        }
        if (n>0 && n<=num) {
        if (!repeated) {
            strcpy(list[n-1].Name, name);
            strcpy(list[n-1].Height, h);
            strcpy(list[n-1].Weight, w);
        } else {
            strcpy(list[n-1].Name, "");
            strcpy(list[n-1].Height, "");
            strcpy(list[n-1].Weight, "");
        }
        }
    } else {
        *isEnd = 1;
    }
}



int main()
{
    int num, i;
    char instr;
    int isEnd=0;
    Info List[SIZE];

    scanf("%d", &num);
    for(i=0;i<num;i++){
        scanf("%s%s%s", List[i].Name, List[i].Height, List[i].Weight);
    }

    while(!isEnd){
        getchar();
        scanf("%c", &instr);
        Find_Revise(List, num, instr, &isEnd);
    }

    return 0;
}
