#include <Arduino.h>
#include "config/config.h"
#include "game/game.h"
#include "rtos/rtos.h"

void setup() {
  Serial.begin(115200);
  randomSeed(esp_random());

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);

  gameInit();
  rtosInit();
}

void loop() {
  // RTOS only
}
