#include <Arduino.h>
#include "input.h"
#include "config/config.h"
#include "game/game.h"

extern QueueHandle_t directionQueue;

void inputTask(void *pvParameters) {
  int dir;

  while (1) {
    if (!digitalRead(BTN_UP)) dir = 1;
    else if (!digitalRead(BTN_DOWN)) dir = 2;
    else if (!digitalRead(BTN_LEFT)) dir = 3;
    else if (!digitalRead(BTN_RIGHT)) dir = 4;
    else dir = 0;

    if (dir) gameSetDirection(dir);
    if (!digitalRead(BTN_RESET)) gameReset();

    vTaskDelay(pdMS_TO_TICKS(50));
  }
}
