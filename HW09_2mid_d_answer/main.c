#include <stdio.h>

char map[100][100];

void fillmap(int R, int C)
{
    int i, j;
    for (i=0; i<R; i++) {
        for (j=0; j<C; j++) {
            map[i][j] = '-';
        }
    }
}
void showmap(int R, int C)
{
    int i, j;
    for (i=0; i<R; i++) {
        for (j=0; j<C; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}
void drawT(int rot, int sz, int row, int col)
{
    int i, j, k;
    if (rot==0) {
        for (i=row,k=0; k<sz; k++, i--) {
            for (j=col-k; j<=col+k; j++) {
                map[i][j] = 'T';
            }
        }
    } else if (rot==90) {
        for (j=col,k=0; k<sz; k++, j++) {
            for (i=row-k; i<=row+k; i++) {
                map[i][j] = 'T';
            }
        }
    }
    else if (rot==180) {
        for (i=row,k=0; k<sz; k++, i++) {
            for (j=col-k; j<=col+k; j++) {
                map[i][j] = 'T';
            }
        }
    }
    else {
        for (j=col,k=0; k<sz; k++, j--) {
            for (i=row-k; i<=row+k; i++) {
                map[i][j] = 'T';
            }
        }
    }
    map[row][col] = 't';
}

void drawQ(int rot, int sz, int row, int col)
{
    int i, j, inir, inic;
    if (rot==0) {
        inir = row-sz+1;
        inic = col-sz+1;
    } else if (rot==90) {
        inir = row-sz+1;
        inic = col;
    } else if (rot==180) {
        inir = row;
        inic = col;
    } else {
        inir = row;
        inic = col-sz+1;
    }
    for (i=inir; i<inir+sz ;i++) {
        for (j=inic; j<inic+sz; j++) {
            map[i][j] = 'Q';
        }
    }
    map[row][col] = 'q';
}


int main(void)
{
    freopen("10849_sampleIn.txt", "r", stdin);
    int h, w;
    int ch;
    int rot, sz,row, col;
    scanf("%d%d", &h, &w);
    fillmap(h, w);
    while (getchar()!='\n');
    while ((ch = getchar())!='x') {
        scanf("%d%d%d%d", &rot, &sz, &row, &col);
        if (ch=='T') {
            drawT(rot, sz, row, col);
        } else {
            drawQ(rot, sz, row, col);
        }
        while (getchar()!='\n');
    }
    showmap(h,w);
    return 0;
}
