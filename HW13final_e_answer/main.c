//10897 - Mouse Maze
#include <stdio.h>
char maze[505][505];
int minstep;

void visit(int r, int c, int step)
{
    if (maze[r][c]=='F') {
        if (step<minstep) minstep = step;
    } else if (maze[r][c]=='$') {
        maze[r][c] = '#';
        visit(r-1, c, step+1);
        visit(r+1, c, step+1);
        visit(r, c-1, step+1);
        visit(r, c+1, step+1);
        maze[r][c] = '$';
    } else {
    }
}
int main(void)
{
    int N;
    int R, C, i, j;
    int sr, sc;

    scanf("%d", &N);
    while (N>0) {
        scanf("%d%d", &R, &C);
        for (i=0; i<=R+1; i++) {
            for (j=0; j<=C+1; j++) {
                maze[i][j] = 0;
            }
        }
        for (i=1; i<=R; i++) {
            scanf("%s", maze[i]+1);
        }

        for (i=1; i<=R; i++) {
            for (j=1; j<=C; j++) {
                if (maze[i][j]=='S') {
                    sr = i;
                    sc = j;
                    maze[i][j] = '$';
                }
            }
        }

        minstep = R*C+1;
        visit(sr, sc, 0);
        if (minstep == R*C+1) printf("-1\n");
        else printf("%d\n", minstep);
        N--;
    }


    return 0;
}
