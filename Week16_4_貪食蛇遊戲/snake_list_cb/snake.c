#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
/* 音效記得要加入這個 */
#include "audio.h"
/* 另外還有底下的設定 */
/* For sound effect: In [Project Options]->[Parameters]->[Linker] add the parameter -lwinmm */

#include "console_draw2.h"
#include "kb_input2.h"

/*
putASCII2()  最後兩個參數分別是字元前景和背景的顏色
可以參考下面的顏色值對照表來設定你想要的顏色
   0: 黑     1: 暗藍   2: 暗綠   3: 暗青
   4: 暗紅   5: 暗紫   6: 暗黃   7: 淺灰
   8: 暗灰   9: 亮藍  10: 亮綠  11: 亮青
  12: 亮紅  13: 亮紫  14: 亮黃  15: 白
*/

#define WIDTH     30
#define HEIGHT    20
#define OFFSET_X  2
#define OFFSET_Y  2

#define REFRESH_DURATION 5

struct t_SnakeNode {
   int x;
   int y;
   int color;
   int direction;
   int duration;
   int tick;
   struct t_SnakeNode *next; /* 用指標變數記住下一個 node 在哪裡 */
};
typedef struct t_SnakeNode SnakeNode;

struct t_FoodNode {
   int x;
   int y;
   int color;
   int duration;
   int tick;
};
typedef struct t_FoodNode FoodNode;

/* utility functions*/
void putString(int x, int y, char *p, int fg_color, int bg_color);

/* food */
void genFood(FoodNode *fp);
void showFood(FoodNode *fp);
void moveFood(FoodNode *fp);

/* snake */
SnakeNode* genSnakeHead(void);
void showSnake(SnakeNode *sp);
void growSnake(SnakeNode *sp);

/* 底下這幾個 functions 尚未完成 */
void boundaryCheck(SnakeNode *sp);
void moveSnake(SnakeNode *sp);
SnakeNode* extractLastNode(SnakeNode *sp);

int eat(SnakeNode *sp, FoodNode *fp);

int main(void)
{
    int IsEnding = 0;
    char logo[] = "SAMPLE PROGRAM PROVIDED BY I2P";
    int i;

    SnakeNode *snake;
    FoodNode food[10];

    /* 用來計時 */
    clock_t startc;
    int game_tick = 0;

    /* 變數 vk 用來記錄使用者按下的鍵 */
    int vk;

	/* 變數 au1 用來記錄要播放的音效*/
    Audio au1;
    openAudioFile("chimes.wav", &au1);



	/* 啟動鍵盤控制 */
    initializeKeyInput();

	/* 產生蛇的頭 */
    snake = genSnakeHead();
    /* 呼叫五次 growSnake 長出蛇的身體 */
    for (i=0; i<5; i++) {
	    growSnake(snake);
	}

    genFood(food);

    startc = clock();
    while (!IsEnding) { /* game loop */

        if ((double)(clock()-startc) > 0.01*CLOCKS_PER_SEC) {
            game_tick++;
            startc = clock();
        }


        if (game_tick > REFRESH_DURATION) {
            game_tick = 0;
            clearScreen();

            showSnake(snake);

            if (eat(snake, food)) {
                growSnake(snake);
                playAudio(&au1);
                genFood(food);
            }
            showFood(food);

            putString(OFFSET_X, OFFSET_Y-1, logo, 14, 3);

            drawCmdWindow();  /* update window immediately */
        }


        moveFood(food);
        moveSnake(snake);

        if(waitForKeyDown(0.01)) {
            vk=getKeyEventVirtual();	/* read a virtual key */

            switch(vk) {
                case VK_ESCAPE:  /* 按下 ESC 鍵 就結束 */
                    IsEnding = 1;
                    break;
                case VK_LEFT:
                case VK_J:
                    snake->direction = 2;
                    break;
                case VK_RIGHT:
                case VK_L:
                    snake->direction = 0;
                    break;
                case VK_DOWN:
                case VK_K:
                    snake->direction = 1;
                    break;
                case VK_UP:
                case VK_I:
                    snake->direction = 3;
                    break;

            }
        }

    } /* while (IsEnding) */


    return 0;
}



void putString(int x, int y, char *p, int fg_color, int bg_color)
{
    int i;
    for(i=0; i<strlen(p); i++) {
        putASCII2(x+i, y, p[i], fg_color, bg_color);
    }
}


/************************************************************************/

void genFood(FoodNode *fp)
{
    fp[0].x = rand() % WIDTH;
    fp[0].y = rand() % HEIGHT;
    fp[0].color = 8+rand()%6;
    fp[0].duration = 50;
    fp[0].tick = 0;
}

void showFood(FoodNode *fp)
{
    putASCII2((fp[0].x)*2  + OFFSET_X,
               fp[0].y + OFFSET_Y, 0xa1, fp[0].color, 0);
    putASCII2((fp[0].x)*2+1  + OFFSET_X,
               fp[0].y +  OFFSET_Y, 0xc0, fp[0].color, 0);
}

void moveFood(FoodNode *fp)
{
    if (fp[0].tick < fp[0].duration) {
        fp[0].tick++;
    } else {
        fp[0].x = fp[0].x + rand()%3-1;
        fp[0].y = fp[0].y + rand()%3-1;

        if (fp[0].x > WIDTH-1) fp[0].x = 0;
        if (fp[0].x < 0) fp[0].x = WIDTH-1;
        if (fp[0].y > HEIGHT-1) fp[0].y = 0;
        if (fp[0].y < 0) fp[0].y = HEIGHT-1;
        fp[0].tick = 0;
    }
}

/************************************************************************/

SnakeNode* genSnakeHead(void)
{
    /* 0: right, 1: down, 2: left, 3: up */
    SnakeNode *sp;

    sp = (SnakeNode*) malloc( sizeof(SnakeNode) );

    sp->x = 10;
    sp->y = 10;
    sp->direction = 2;
    sp->duration = 10;
    sp->tick = 0;
    sp->color = 14;

    /* 因為目前整個 linked list 只有一個 head node */
    sp->next = NULL;

    return sp;
}

void growSnake(SnakeNode *sp)
{
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    /* 0: right, 1: down, 2: left, 3: up */

    SnakeNode *np;
    np = (SnakeNode*) malloc( sizeof(SnakeNode) );


    np->direction = sp->direction;
    np->duration = sp->duration;
    np->tick = 0;
    np->color = 15;
    np->next = NULL; /* NULL */

    /* 加到 linked list 最後面 */
    /* 先移動到最後一個 node */
    while (sp->next != NULL) {
    	sp = sp->next;
    }
    np->x = sp->x - dx[sp->direction];
    np->y = sp->y - dy[sp->direction];

	/* 重要的步驟: 把新的 node 串起來 */
    sp->next = np;

    /* 檢查是否超出畫面邊界 */
    boundaryCheck(sp);
}

void showSnake(SnakeNode *sp)
{
	char c1, c2;
    if (sp != NULL)  {

    	if (sp->direction == 0 || sp->direction == 2) {
    		/* 水平 */
    		c1 = 0xA1;
    		c2 = 0xDB;
    	} else {
			/* 垂直 */
    		c1 = 0xA2;
    		c2 = 0xB7;
    	}

	    putASCII2((sp->x)*2  + OFFSET_X,
    	           sp->y + OFFSET_Y, c1, sp->color, 0);
        putASCII2((sp->x)*2+1  + OFFSET_X,
            	   sp->y +  OFFSET_Y, c2, sp->color, 0);

    	/* 重要的步驟   移動到下一個 node 否則迴圈會跑步完 */
        showSnake(sp->next);
    }
}

/******************************************************
	底下是還沒完成的 functions
******************************************************/

int eat(SnakeNode *sp, FoodNode *fp)
{
	/*
		檢查是否吃到 food
		蛇的頭或身體任何部分碰到 food 都算是吃到
		???
        return 1;
    */

    return 0;
}

SnakeNode* extractLastNode(SnakeNode *sp)
{
	SnakeNode *last = NULL;
	SnakeNode *last_prev;

	/*
		找到最後一個 node
		把最後一個 node 的位址傳回去
		並且要把原本倒數第二個  node 的 next 設為 NULL
		因為取出最後一個  node 之後
		原本倒數第二個 node 就變成了最後一個 node
	*/
	last = sp->next;
	last_prev = sp;
	if (last != NULL) {
        while (last->next != NULL) {
            last = last->next;
            last_prev = last_prev->next;
        }
        last_prev->next = NULL;
	}

	return last;
}

void boundaryCheck(SnakeNode *sp)
{
	/*
		檢查蛇的每個 node 是否超出了畫圖的邊界
		如果超過的話
		就從畫面的另外一邊出現
	*/
	if (sp != NULL) {
        if (sp->x < 0) sp->x = WIDTH - 1;
        if (sp->y < 0) sp->y = HEIGHT - 1;
        if (sp->x >= WIDTH) sp->x = 0;
        if (sp->y >= HEIGHT) sp->y = 0;
        boundaryCheck(sp->next);
	}

}
void moveSnake(SnakeNode *sp)
{
    /* 0: right, 1: down, 2: left, 3: up */
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

	SnakeNode *last;


    if (sp->tick < sp->duration) {
        sp->tick++;
    } else {

		/* 取出最後一個 node (呼叫 extractLastNode 傳回的 last 指標)  */
		last = extractLastNode(sp);

		if (last != NULL) {

			/*
			   呼叫 extractLastNode 傳回的 last 指標
			   記住了原本最後一個 node 的位址
			   把蛇的 head node 的 x y 座標 以及 direction 複製給 last 所指的那個 node
			   然後把 last 所指的 node 加到蛇的 head node 後面
			   也就是變成第二個 node
			   而原本的第二個 node 就變成了第三個 node

			   接著把 head node 的 x y 座標 往前推進一步
			   這樣就自然可以造成整條蛇往前進的效果

				???
			*/
			last->x = sp->x;
			last->y = sp->y;
			last->direction = sp->direction;

			last->next = sp->next;
			sp->next = last;

            sp->x = sp->x + dx[sp->direction];
            sp->y = sp->y + dy[sp->direction];
		}

		/* 檢查是否超出螢幕範圍  */
		boundaryCheck(sp);

		/* 歸零 */
        sp->tick = 0;
    }

}


