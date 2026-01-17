#include <Adafruit_SSD1306.h>
#include "display.h"
#include "config/config.h"
#include "game/game.h"

int foodSize = 4;
int offset = (CELL_SIZE - foodSize) / 2;

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void displayTask(void *pvParameters) {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  while (1) {
    display.clearDisplay();

    display.fillRect(foodX * CELL_SIZE + offset,foodY * CELL_SIZE + offset,foodSize,
  foodSize,
  WHITE
);

    for (int i = 0; i < snakeLength; i++) {
      display.fillRect(snakeX[i] * CELL_SIZE, snakeY[i] * CELL_SIZE,
                       CELL_SIZE, CELL_SIZE, WHITE);
    }

    if (gameOver) {
      display.setCursor(20, 28);
      display.setTextColor(WHITE);
      display.println("GAME OVER");
      display.println("Press RESET");
    }

    display.display();
    vTaskDelay(pdMS_TO_TICKS(60));
  }
}
