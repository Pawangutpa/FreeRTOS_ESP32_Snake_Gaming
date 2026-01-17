#include <Arduino.h>
#include "rtos.h"
#include "input/input.h"
#include "display/display.h"
#include "game/game.h"

void gameTask(void *pvParameters) {
  while (1) {
    gameUpdate();
    vTaskDelay(pdMS_TO_TICKS(250));
  }
}

void rtosInit() {
  xTaskCreatePinnedToCore(inputTask, "Input", 2048, NULL, 3, NULL, 0);
  xTaskCreatePinnedToCore(gameTask, "Game", 4096, NULL, 2, NULL, 1);
  xTaskCreatePinnedToCore(displayTask, "Display", 4096, NULL, 1, NULL, 1);
}
