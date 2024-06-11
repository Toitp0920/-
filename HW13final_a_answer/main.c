//10389 - Text Editor
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 502

char content[MAX_SIZE];
char input[MAX_SIZE];

int main(void)
{

    int i, j, k;
    fgets(input, MAX_SIZE+1, stdin);

    i = j = 0;
    while (i<strlen(input)) {
        if (input[i] == '/') {
            if (input[i+1] == 'b') {
                if (j>0) {
                    --j;
                    for (k=j; k<strlen(content); k++)
                        content[k] = content[k+1];
                }
                i = i + 10;
            } else if (input[i+1] == 'n') {
                for (k=strlen(content); k>j; k--)
                    content[k] = content[k-1];
                content[j] = '\n';
                ++j;
                i = i + 8;
            } else if (input[i+1] == 'l') {
                if (j>0) {
                    --j;
                }
                i = i + 5;
            } else {
                if (j<strlen(content))  // boring
                    ++j;
                i = i + 6;
            }
        } else if (input[i]!='\n'){
            for (k=strlen(content); k>j; k--)
                content[k] = content[k-1];
            content[j] = input[i];
            ++j;
            ++i;
        } else {
            ++i;
        }
    }


    printf("%s", content);

    return 0;
}
