#include <stdio.h>
#include <stdlib.h> /* 要使用 srand 和 rand 來產生亂數 */
#include <time.h>   /* 要使用 time 來產生 srand 所需的 seed */
#include "console_draw.h"  /* 在 DOS command window 畫圖 */
#include "kb_input.h"

#define WIDTH     12
#define SIZE      (WIDTH*WIDTH)  /* 地圖的大小 */
#define NUM_MINES 10
#define OFFSET_X  10
#define OFFSET_Y  5

int main(void)
{
    int a[SIZE] = {' '};
    int i;
    int target;
    int hold;
    int ch, prev=0;
    int px[SIZE] = {0}, py[SIZE] = {0};
    int curdir[SIZE] = {0};
    int length = 1;
    int move_count = 0;

    /* 把 NUM_MINES 個地雷放在 array 的最前面  但是要把 i = 0 的位置空下來放 Jack */
    for (i = 1; i <= NUM_MINES; i++) {
        a[i] = '@';
    }

    for (i = NUM_MINES+1; i < SIZE; i++) {
        a[i] = ' ';
    }

    /* 用 shuffle 方式把 array 弄亂 來產生隨機的地圖 */
    srand(time(NULL));
    for (i = 1; i < SIZE; i++) {
        target = rand() % (SIZE-i) + i;   /* 隨機產生落在 i ~ SIZE-1 的整數 */
        hold = a[i];
        a[i] = a[target];
        a[target] = hold;
    }

    initializeKeyInput(); /* 啟動鍵盤控制 */

    while (1) { /* 無窮迴圈 */


        for (i = 0; i < SIZE; i++) {
            if (a[i]=='@') {
                putASCII((i%WIDTH)*2 + OFFSET_X, (i/WIDTH) + OFFSET_Y, 0xA1 , 1);
                putASCII((i%WIDTH)*2 + 1 + OFFSET_X, (i/WIDTH) + OFFSET_Y, 0xEA , 1);
            } else {
                putASCII((i%WIDTH)*2 + OFFSET_X, i/WIDTH + OFFSET_Y, ' ' , 1);
                putASCII((i%WIDTH)*2 + 1 + OFFSET_X, i/WIDTH + OFFSET_Y, ' ' , 1);
            }
        }

        for (i=0; i<length; i++) {
            putASCII(px[i]*2 + OFFSET_X, py[i] + OFFSET_Y, 0xA2, 2);
            putASCII(px[i]*2+1 + OFFSET_X, py[i] + OFFSET_Y, 0x4F, 2);
        }

        /* 把填好的螢幕內容顯示出來 */
        drawCmdWindow();


        for (i=0; i<length; i++) {
            if (a[px[i] + py[i]*WIDTH] == '@') {
                a[px[i] + py[i]*WIDTH] = ' ';
                px[length] = px[length-1];
                py[length] = py[length-1];
                curdir[length] = curdir[length-1];

                switch (curdir[length]) {
                case 0: px[length]--; break;
                case 1: py[length]--; break;
                case 2: px[length]++; break;
                case 3: py[length]++; break;
                }
                length++;
            }
        }

        move_count++;
        if (move_count%5==0) {
            for (i=0; i<length; i++) {
                switch (curdir[i]) {
                case 0: px[i]++; break;
                case 1: py[i]++; break;
                case 2: px[i]--; break;
                case 3: py[i]--; break;
                }
            }

            for (i=0; i<length; i++) {
                if (py[i] < 0) py[i] = WIDTH-1;
                if (py[i] > WIDTH-1) py[i] = 0;
                if (px[i] < 0) px[i] = WIDTH-1;
                if (px[i] > WIDTH-1) px[i] = 0;
            }

            for (i=length-1; i>0; i--) {
                curdir[i] = curdir[i-1];
            }
        }

        if(waitForKeyDown(0.05)) {
            ch=getKeyEventASCII(); /* 讀取輸入的字元 */
            if (prev!=ch) {
                switch(ch) {
                case 'e': return 0;
                case 'i': curdir[0]=3; break;
                case 'k': curdir[0]=1; break;
                case 'j': curdir[0]=2; break;
                case 'l': curdir[0]=0; break;
                }
                prev = ch;
            }
        }


    } /* while (1) 無窮迴圈 */

    return 0;
}
