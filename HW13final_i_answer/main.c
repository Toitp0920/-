//10901 - Pointer Integer Array
#include <stdio.h>
#include <stdlib.h>

int** malloc_ptr(int array_size)
{
    int **p;
    p = (int**) malloc(sizeof(int*) * array_size);
    return p;
}

void malloc_array(int **array, int array_size)
{
    *array =  (int*) malloc(sizeof(int) * array_size);
}

void pointer_ptr_to_array(int *array, int **ptr,int N)
{
    int i, j;
    i = j = 0;
    while (i<N) {
        ptr[i] = &array[j];
        i++;
        j = j + i;
    }
}

int main() {

        int *array;
        int **ptr;
        int N;

        int offset;
        scanf("%d %d",&N, &offset);

        malloc_array(&array, (1+N)*N/2);
        ptr = malloc_ptr(N);

        int i;

        for(i = 0; i < (1+N)*N/2; i++){
                array[i] = i;
        }

        pointer_ptr_to_array(array,ptr,N);
        for(i = 0; i < N; i++){
                printf("%d\n",*(ptr[i]+(offset)));
        }

        free(ptr);
        free(array);

        return 0;
}
