#include "game.h"
#include "config/config.h"

int snakeX[MAX_SNAKE_LEN];
int snakeY[MAX_SNAKE_LEN];
int snakeLength;

int foodX, foodY;
bool gameOver;
static int direction = 4;

void gameReset() {
  snakeLength = 1;
  snakeX[0] = GRID_W / 2;
  snakeY[0] = GRID_H / 2;
  direction = 4;
  gameOver = false;

  foodX = random(0, GRID_W);
  foodY = random(0, GRID_H);
}

void gameInit() {
  gameReset();
}

void gameUpdate() {
  if (gameOver) return;

  for (int i = snakeLength - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  if (direction == 1) snakeY[0]--;
  if (direction == 2) snakeY[0]++;
  if (direction == 3) snakeX[0]--;
  if (direction == 4) snakeX[0]++;

  // Wrap around
  if (snakeX[0] < 0) snakeX[0] = GRID_W - 1;
  if (snakeX[0] >= GRID_W) snakeX[0] = 0;
  if (snakeY[0] < 0) snakeY[0] = GRID_H - 1;
  if (snakeY[0] >= GRID_H) snakeY[0] = 0;

  // Self collision
  for (int i = 1; i < snakeLength; i++) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      gameOver = true;
    }
  }

  // Food eaten
  if (snakeX[0] == foodX && snakeY[0] == foodY) {
    if (snakeLength < MAX_SNAKE_LEN) snakeLength++;
    foodX = random(0, GRID_W);
    foodY = random(0, GRID_H);
  }
}

void gameSetDirection(int dir) {
  direction = dir;
}
