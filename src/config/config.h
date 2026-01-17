#ifndef CONFIG_H
#define CONFIG_H

// Display
#define OLED_WIDTH   128
#define OLED_HEIGHT  64
#define CELL_SIZE    8

#define GRID_W (OLED_WIDTH / CELL_SIZE)
#define GRID_H (OLED_HEIGHT / CELL_SIZE)
#define MAX_SNAKE_LEN 64

// Buttons
#define BTN_UP     32
#define BTN_DOWN   33
#define BTN_LEFT   25
#define BTN_RIGHT  26
#define BTN_RESET  27

#endif
