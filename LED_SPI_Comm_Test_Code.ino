#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8  // 2 boards × 4 modules = 8 displays

#define DATA_PIN  12
#define CLK_PIN   11
#define CS_PIN    10

MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  display.begin();
  display.setIntensity(10);         // Brightness: 0 (dim) to 15 (bright)
  display.displayClear();
  display.displayScroll("GAME OVER", PA_LEFT, PA_SCROLL_LEFT, 100);
}

void loop() {
 // if (display.displayAnimate()) {
    // When scroll is done, start it again
  //  display.displayScroll("GAME OVER", PA_RIGHT, PA_SCROLL_RIGHT, 100);
 // }
}
