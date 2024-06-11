//Transpose of A Matrix
#include <stdio.h>
#include <stdlib.h>

int** allocateMat(int m, int n)
{

    int **p;
    int i;
/*
    int *data;
    data = (int *)malloc(sizeof(int)*m*n);
    p = (int **) malloc(sizeof(int*)*m);
    for (i=0; i<m; i++) {
        p[i] = &data[i*n];
    }
*/

    p = (int **) malloc(sizeof(int*)*m);
    for (i=0; i<m; i++) {
        p[i] = (int*) malloc(sizeof(int)*n);
    }
    return p;
}
void readInput(int** p, int m, int n)
{
    int i, j;
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &p[i][j]);
        }
    }
}
void printResult(int** p, int m, int n)
{
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%d ", p[j][i]);
        }
        printf("\n");
    }
}


int main(void) {

  int **mat;
  int m, n;
  int i;

  scanf("%d %d", &m, &n);

  mat = allocateMat(m, n);
  readInput(mat, m, n);
  printResult(mat, m, n);

  // Be sure to release acquired memory space
  for(i=0; i<m; i++)
    free(mat[i]);
  free(mat);

  return 0;

}
