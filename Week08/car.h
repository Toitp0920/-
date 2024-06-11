#include <stdio.h>
#define MAP_SIZE 12

#define CAR_SIZE 3

/* #define ONLINE_JUDGE */

int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);

void map_show(void);

int blocks[MAP_SIZE][MAP_SIZE];

void blocks_read(void);

void blocks_put_on_map(void);

int jewels[MAP_SIZE][MAP_SIZE];

void jewels_read(void);

void jewels_put_on_map(void);

int car[CAR_SIZE][CAR_SIZE] = {{'O', 'O', '@'}, {'O', 'O', 'O'}, {'O', 'O', '@'}};

int car_row = 3, car_col = 4;

int car_direction;

int car_earnings;

void car_rotate90(void);

void car_put_on_map(void);

void car_move(void);