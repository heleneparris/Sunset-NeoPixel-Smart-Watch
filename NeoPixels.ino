void initNeopixels() {            //function to initialize the neopixels
  strip.begin(); strip.clear(); strip.show(); strip.setBrightness(10);
}
uint32_t Wheel(byte WheelPos) {   //function that assigns a color based on the 0-255 color wheel
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void flashlight(int b) {          //function that lights up all neopixels at a set brightness
  strip.setPixelColor(12, 0, 0, 0);
  for (int i = 0; i < strip.numPixels() - 1; i++) {
    strip.setBrightness(b);                                  // sets to extra bright for the flashlight
    strip.setPixelColor(i, 255, 255, 255);
    strip.show();
  }
  strip.setBrightness(15);                                   //resets to default brightness after the flashlight event
}
