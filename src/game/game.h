#ifndef GAME_H
#define GAME_H

#include <Arduino.h>

extern int snakeX[];
extern int snakeY[];
extern int snakeLength;
extern int foodX, foodY;
extern bool gameOver;

void gameInit();
void gameUpdate();
void gameReset();


void gameSetDirection(int dir);

#endif
