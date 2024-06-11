#include <stdio.h>
#include <string.h>
char a[50][50];
void drawtan(char ch, int deg, int size, int r, int c);
int main()
{
    freopen("10849_sampleIn.txt", "r", stdin);
    int i, j;
    int H, W;
    char ch;
    int deg, size, r, c;
    memset(a, '-', 2500*sizeof(char));
    /*
        for(i=0; i<50; i++)
        {
            for(j=0; j<50; j++)
                printf("%c", a[i][j]);
            printf("\n");
        }
    */
    scanf("%d%d", &H, &W);
    while (ch!='x')
    {
        scanf("%c%d%d%d%d", &ch, &deg, &size, &r, &c);
        drawtan(ch, deg, size, r, c);
    }
    for (i=0; i<H; i++)
    {
        for (j=0; j<W; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    return 0;
}
void drawtan(char ch, int deg, int size, int r, int c)
{
    int i, j;
    int d = 'A'-'a';
    if (ch=='T')
    {
        a[r][c]='t';
        if (deg==0)
        {
            for (i=1; i<size; i++)
            {
                for (j=0; j<2*i+1; j++)
                    a[r-i][c-i+j] = 'T';
            }
        }
        else if (deg==180)
        {
            for (i=1; i<size; i++)
            {
                for (j=0; j<2*i+1; j++)
                    a[r+i][c-i+j] = 'T';
            }
        }
        else if (deg==90)
        {
            for (i=1; i<size; i++)
            {
                for (j=0; j<2*i+1; j++)
                    a[r-i+j][c+i] = 'T';
            }
        }
        else if (deg==270)
        {
            for (i=1; i<size; i++)
            {
                for (j=0; j<2*i+1; j++)
                    a[r-i+j][c-i] = 'T';
            }
        }
    }
    else if (ch=='Q')  //
    {
        if (deg==0)
        {
            for (i=0; i<size; i++)
            {
                for (j=0; j<size; j++)
                    a[r-i][c-j] = 'Q';
            }
        }
        else if (deg==90)
        {
            for (i=0; i<size; i++)
            {
                for (j=0; j<size; j++)
                    a[r-i][c+j] = 'Q';
            }
        }
        else if (deg==180)
        {
            for (i=0; i<size; i++)
            {
                for (j=0; j<size; j++)
                    a[r+i][c+j] = 'Q';
            }
        }
        else if (deg==270)
        {
            for (i=0; i<size; i++)
            {
                for (j=0; j<size; j++)
                    a[r+i][c-j] = 'Q';
            }
        }
        a[r][c]='q';
    }
}
/*
0   90
QQ  QQ
Qq  qQ
270 180
Qq  qQ
QQ  QQ
*/
