#include <Time.h>                           //including relevant libraries
#include <TimeLib.h>
#include "tinysnore.h"  
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
unsigned long startTime = millis();
int mode = -1;                              //controls the state machine -1: Sleep || 0: Display Time || 1: Set Time || 2: Game|| 3: Flashlight

Adafruit_NeoPixel strip(13, 0, NEO_GRB + NEO_KHZ800);

int buttonPins[4] = {1, 2, 3, 4};           //button array to debounce all buttons
Bounce * buttons = new Bounce[4];

void setup() {
  initButtons();
  initNeopixels();
  setTime(11, 59, 55, 2, 8, 2017);          //setting initial time (hr,min,sec,day,mon,year)
}
void loop() {
  updateTime();
  updateButtons();

  switch (mode) {
    case -1: fallAsleep(); break;           //puts it in sleep mode
    case 0: displayTime(); break;           //shows the time
    case 1: setWatch(); break;              //allows movement of the hours and minutes pixel
    case 2: game(); break;                  //reflex game
    case 3: flashlight(50); break;          //lights all neopixels up 
  }
}
