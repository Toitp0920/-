#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
/* ���İO�o�n�[�J�o�� */
#include "audio.h"
/* �t�~�٦����U���]�w */
/* For sound effect: In [Project Options]->[Parameters]->[Linker] add the parameter -lwinmm */

#include "console_draw2.h"
#include "kb_input2.h"

/*
putASCII2()  �̫��ӰѼƤ��O�O�r���e���M�I�����C��
�i�H�ѦҤU�����C��ȹ�Ӫ�ӳ]�w�A�Q�n���C��
   0: ��     1: �t��   2: �t��   3: �t�C
   4: �t��   5: �t��   6: �t��   7: �L��
   8: �t��   9: �G��  10: �G��  11: �G�C
  12: �G��  13: �G��  14: �G��  15: ��
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
   struct t_SnakeNode *next; /* �Ϋ����ܼưO��U�@�� node �b���� */
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

/* ���U�o�X�� functions �|������ */
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

    /* �Ψӭp�� */
    clock_t startc;
    int game_tick = 0;

    /* �ܼ� vk �ΨӰO���ϥΪ̫��U���� */
    int vk;

	/* �ܼ� au1 �ΨӰO���n���񪺭���*/
    Audio au1;
    openAudioFile("chimes.wav", &au1);



	/* �Ұ���L���� */
    initializeKeyInput();

	/* ���ͳD���Y */
    snake = genSnakeHead();
    /* �I�s���� growSnake ���X�D������ */
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
                case VK_ESCAPE:  /* ���U ESC �� �N���� */
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

    /* �]���ثe��� linked list �u���@�� head node */
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

    /* �[�� linked list �̫᭱ */
    /* �����ʨ�̫�@�� node */
    while (sp->next != NULL) {
    	sp = sp->next;
    }
    np->x = sp->x - dx[sp->direction];
    np->y = sp->y - dy[sp->direction];

	/* ���n���B�J: ��s�� node ��_�� */
    sp->next = np;

    /* �ˬd�O�_�W�X�e����� */
    boundaryCheck(sp);
}

void showSnake(SnakeNode *sp)
{
	char c1, c2;
    if (sp != NULL)  {

    	if (sp->direction == 0 || sp->direction == 2) {
    		/* ���� */
    		c1 = 0xA1;
    		c2 = 0xDB;
    	} else {
			/* ���� */
    		c1 = 0xA2;
    		c2 = 0xB7;
    	}

	    putASCII2((sp->x)*2  + OFFSET_X,
    	           sp->y + OFFSET_Y, c1, sp->color, 0);
        putASCII2((sp->x)*2+1  + OFFSET_X,
            	   sp->y +  OFFSET_Y, c2, sp->color, 0);

    	/* ���n���B�J   ���ʨ�U�@�� node �_�h�j��|�]�B�� */
        showSnake(sp->next);
    }
}

/******************************************************
	���U�O�٨S������ functions
******************************************************/

int eat(SnakeNode *sp, FoodNode *fp)
{
	/*
		�ˬd�O�_�Y�� food
		�D���Y�Ψ�����󳡤��I�� food ����O�Y��
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
		���̫�@�� node
		��̫�@�� node ����}�Ǧ^�h
		�åB�n��쥻�˼ƲĤG��  node �� next �]�� NULL
		�]�����X�̫�@��  node ����
		�쥻�˼ƲĤG�� node �N�ܦ��F�̫�@�� node
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
		�ˬd�D���C�� node �O�_�W�X�F�e�Ϫ����
		�p�G�W�L����
		�N�q�e�����t�~�@��X�{
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

		/* ���X�̫�@�� node (�I�s extractLastNode �Ǧ^�� last ����)  */
		last = extractLastNode(sp);

		if (last != NULL) {

			/*
			   �I�s extractLastNode �Ǧ^�� last ����
			   �O��F�쥻�̫�@�� node ����}
			   ��D�� head node �� x y �y�� �H�� direction �ƻs�� last �ҫ������� node
			   �M��� last �ҫ��� node �[��D�� head node �᭱
			   �]�N�O�ܦ��ĤG�� node
			   �ӭ쥻���ĤG�� node �N�ܦ��F�ĤT�� node

			   ���ۧ� head node �� x y �y�� ���e���i�@�B
			   �o�˴N�۵M�i�H�y������D���e�i���ĪG

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

		/* �ˬd�O�_�W�X�ù��d��  */
		boundaryCheck(sp);

		/* �k�s */
        sp->tick = 0;
    }

}


