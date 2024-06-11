//10893 - Moving Cars(4 direction)
#include <stdio.h>

#define MAP_SIZE 9
#define MAX_CARS 10
#define SPACE '.'

char map[MAP_SIZE][MAP_SIZE];
int cars[MAX_CARS][4];
void list_moves(int);

int main(void)
{
    int i,j,k;
    int num_cars;

    scanf("%d",&num_cars);
    //reset map
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            map[i][j] = SPACE;
        }
    }
    //read coordinates of cars and put them on the map
    for (i=0; i<num_cars; i++) {
        scanf("%d%d%d%d", &cars[i][0], &cars[i][1], &cars[i][2], &cars[i][3]);
        for (j=cars[i][0]; j<=cars[i][2]; j++) {
            for (k=cars[i][1]; k<=cars[i][3]; k++) {
                map[j][k] = i+'0';
            }
        }
    }
    list_moves(num_cars);

    return 0;
}

void list_moves(int num_cars)
{
    int i, row, col, r, d, l, u, j, valid;
    for (i=0; i<num_cars; i++) {
        if (cars[i][0]==cars[i][2]) {
            row = cars[i][0];
            col = cars[i][3];
            r = 0;
            while (col+r+1<MAP_SIZE && map[row][col+r+1]=='.') {
                r++;
            }
            col = cars[i][1];
            l = 0;
            while (col-l-1>=0 && map[row][col-l-1]=='.') {
                l++;
            }
            u = 0;
            while (row-u-1>=0) {
                valid = 1;
                for (j=cars[i][1]; j<=cars[i][3]; j++) {
                    if (map[row-u-1][j]!='.') {
                        valid = 0;
                        break;
                    }
                }
                if (valid) u++;
                else break;
            }
            d = 0;
            while (row+d+1<MAP_SIZE) {
                valid = 1;
                for (j=cars[i][1]; j<=cars[i][3]; j++) {
                    if (map[row+d+1][j]!='.') {
                        valid = 0;
                        break;
                    }
                }
                if (valid) d++;
                else break;
            }
        } else {
            col = cars[i][1];
            row = cars[i][2];
            d = 0;
            while (row+d+1<MAP_SIZE && map[row+d+1][col]=='.') {
                d++;
            }
            row = cars[i][0];
            u = 0;
            while (row-u-1>=0 && map[row-u-1][col]=='.') {
                u++;
            }
            l = 0;
            while (col-l-1>=0) {
                valid = 1;
                for (j=cars[i][0]; j<=cars[i][2]; j++) {
                    if (map[j][col-l-1]!='.') {
                        valid = 0;
                        break;
                    }
                }
                if (valid) l++;
                else break;
            }
            r = 0;
            while (col+r+1<MAP_SIZE) {
                valid = 1;
                for (j=cars[i][0]; j<=cars[i][2]; j++) {
                    if (map[j][col+r+1]!='.') {
                        valid = 0;
                        break;
                    }
                }
                if (valid) r++;
                else break;
            }
        }
        printf("%d %d %d %d\n", r, d, l, u);
    }
}
