#include <stdio.h>
reflect(int h, int w, int* p, int n, int dir);
int main(void)
{
    int height, width;
    int a[3] = {0};
    int* p = a;
    int n;



    scanf("%d%d", &height, &width);
    scanf("%d%d", &a[1], &a[2]);
    scanf("%d", &n);

    reflect(height, width, p, n, 9);





    return 0;
}
show(int* p)
{
    printf("(%d,%d)", p[1], p[2]);
    return;
}
reflect(int h, int w, int* p, int n, int dir)
{
    int c=0;
    while (c<n-1)
    {
        if (dir==9)
        {
            //printf("dir:%d, (%d,%d)\n", dir, p[1], p[2]);
            if (p[1]-1 > w-p[2])
            {
                p[1] = p[1]- (w-p[2]);
                p[2] = w;
                dir = 7;
                c++;
            }
            else if (p[1]-1 < w-p[2])
            {
                p[2] = p[1]-1+p[2];
                p[1] = 1;
                dir = 3;
                c++;
            }
            else
            {
                p[1]=1;
                p[2]=w;
                show(p);
                return;
            }
        }
        else if (dir==3)
        {
            //printf("dir:%d, (%d,%d)\n", dir, p[1], p[2]);
            if (h-p[1]>w-p[2])
            {
                p[1]=p[1]+w-p[2];
                p[2]=w;
                dir=1;
                c++;
            }
            else if (h-p[1]<w-p[2])
            {
                p[2]=h-p[1]+p[2];
                p[1]=h;
                dir=9;
                c++;
            }
            else
            {
                p[1]=h;
                p[2]=w;
                show(p);
                return;
            }
        }
        else if (dir==1)
        {
            //printf("dir:%d, (%d,%d)\n", dir, p[1], p[2]);
            if (h-p[1]<p[2]-1)
            {
                p[2]=p[2]- (h-p[1]);
                p[1]=h;
                dir=7;
                c++;
            }
            else if (h-p[1]>p[2]-1)
            {
                p[1]=p[1]+p[2]-1;
                p[2]=1;
                dir=3;
                c++;
            }
            else
            {
                p[1]=h;
                p[2]=1;
                show(p);
                return;
            }
        }
        else if (dir==7)
        {
            //printf("dir:%d, (%d,%d)\n", dir, p[1], p[2]);
            if (p[1]-1<p[2]-1)
            {
                p[2]=p[2]- (p[1]-1);
                p[1]=1;
                dir=1;
                c++;
            }
            else if (p[1]-1>p[2]-1)
            {
                p[1]=p[1]- (p[2]-1);
                p[2]=1;
                dir=9;
                c++;
            }
            else
            {
                p[1]=1;
                p[2]=1;
                show(p);
                return;
            }
        }
    }
    show(p);
}
