# 🐍 ESP32 Snake Game using FreeRTOS & OLED (SSD1306)

This project implements a **real-time Snake Game** on an **ESP32** using **FreeRTOS**.  
The game is displayed on a **0.96" OLED (SSD1306)** and controlled via **push buttons**.  
The code follows a **clean, modular, industry-style architecture** suitable for professional embedded development.

---

## 📌 Overview

Unlike traditional Arduino `loop()`-based games, this project uses **FreeRTOS multitasking** to separate:
- Input handling
- Game logic
- Display rendering

Each part runs as an **independent real-time task**, ensuring responsiveness and scalability.

---

## 🧩 Hardware Used

- ESP32 Development Board
- 0.96" OLED Display (SSD1306, I2C)
- 5 Push Buttons
  - UP
  - DOWN
  - LEFT
  - RIGHT
  - RESET
- Breadboard & jumper wires

---

## 🔌 Pin Configuration

All pin definitions are centralized in `config/config.h`.

### 🎮 Button Pins

| Function | GPIO |
|--------|------|
| UP     | 32 |
| DOWN   | 33 |
| LEFT   | 25 |
| RIGHT  | 26 |
| RESET  | 27 |

Buttons use **INPUT_PULLUP** mode (active LOW).

---

### 🖥 OLED I2C Pins

| OLED Pin | ESP32 Pin |
|--------|----------|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| VCC | 3.3V |
| GND | GND |

OLED I2C Address: `0x3C`

---

## 📐 Display Grid System

- OLED Resolution: **128 × 64**
- Cell Size: **8 × 8 pixels**
- Game Grid: **16 × 8 cells**

Each snake segment and food occupies **one grid cell**.

---

## 📁 Project Structure

- snake_freertos_esp32/
- │
- ├── README.md
- ├── .gitignore
- ├── platformio.ini          ← Used by PlatformIO ONLY
- │
- ├── src/                    ← PlatformIO entry
- │   └── main.cpp
- │
- ├── include/                ← Arduino-compatible headers
- │   ├── config/
- │   │   └── config.h
- │   │
- │   ├── game/
- │   │   └── game.h
- │   │
- │   ├── input/
- │   │   └── input.h
- │   │
- │   ├── display/
- │   │   └── display.h
- │   │
- │   └── rtos/
- │       └── rtos.h
- │
- ├── lib/                    ← Shared implementation (KEY PART)
- │   ├── game/
- │   │   └── game.cpp
- │   │
- │   ├── input/
- │   │   └── input.cpp
- │   │
- │   ├── display/
- │   │   └── display.cpp
- │   │
- │   └── rtos/
- │       └── rtos.cpp
- │
- └── arduino/
-     └── snake_freertos_esp32.ino   ← Arduino entry point
