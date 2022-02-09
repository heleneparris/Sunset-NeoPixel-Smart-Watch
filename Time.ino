int minLed;             //stores the current minute
int hourLed;            //stores the current hour
int displayPos = 0;     //used to light up hour leds for the displayTime() function
int minDisplayPos = 0;  //used to light up minute leds for the displayTime() function
int c = 170;            //color vars used with the Wheel() function

int setWatch() {        //allows movement of the leds that represent hours and minutes
  strip.clear();
  strip.setPixelColor(minLed, 0, 255 , 0);
  strip.setPixelColor(hourLed, 255, 0, 0);
  strip.show();
  setCurTime();                                               //updates the current time to coordinate with the minLed and hourLed positions
}
void setCurTime() {     //updating the time to be the positions of the hourLed and minLed
  setTime(hourLed, minLed * 5, 0, 2, 8, 2017);
}
void updateTime() {     //function that keeps track of time
  time_t t = now();                                           //now() returns the current time and is stores in vars 't'
  hourLed = hour(t);                                          //sets hourLed to be equal to the current hour value
  minLed = ceil(minute(t) / 5);                               //sets minLed to be the current minute value (/5 to account for the fact that minutes display in 5 min increments)
  /*  hourLed = ceil((minute(t + 5) / 5)); //code to make time faster for demo
      minLed = ceil(second(t) / 5); */
  if (hour(t) > 11) {
    setTime(0, 0, 0, 2, 8, 2017);                             //resets the time to 0 once it goes to 12 to keep a 12 hour clock rotation
  }
}
void displayTime() {    //lights up neopixels sequentially in a clockwise rotation until they have reached the current time
  strip.clear(); strip.show();
  for (int i = 0; i < hourLed + 1; i++) {                     //first, display the hour by increasing the displayPos until it is equal to the current hour value
    if (i == displayPos) {
      strip.setPixelColor(displayPos, Wheel(c));
    }
    displayPos = displayPos + 1;
    c = c + 7;                                                //increasing color vars after each hour pixel lights up to make a gradient
    strip.show(); delay(100);
  }
  delay(1000); strip.clear(); strip.show(); delay(100);
  c = 225;                                                    //resetting color vars for the minute display so it starts at red for the minute display
    
  for (int i = 0; i < minLed + 1; i++) {                      //second, display the minutes by increasing the minDisplayPos until it is equal to the current minute value
    if (i == minDisplayPos) {
      strip.setPixelColor(minDisplayPos, Wheel(c));
    }
    minDisplayPos = minDisplayPos + 1;
    c = c + 7;                                                //increasing color vars after each minute pixel lights up to make a gradient
    strip.show(); delay(100);
  }
  delay(1000); strip.clear(); strip.show();
  displayPos = 0; minDisplayPos = 0; c = 170; mode = -1;      //setting values back to zero and putting the watch to sleep after each diplayTime() event
}
void updateButtons() {    //special switch case that gives new fucntions to buttons once they have entered a mode
  switch (mode) {
    case -1:                                                  //when the watch is alseep, udate all the buttons to coordinate with the modes again
      for (int i = 0; i < 4; i++)  {
        buttons[i].update();
        if (buttons[i].rose()) {
          mode = i;
        }
      }
      break;
    case 0:   //(display time)
      buttons[0].update();
      if (buttons[0].rose()) {
        mode = -1;
      }
      break;
    case 1:   //(set time)                                    //gives buttons 1 and 2 new functions to change the position of the hourLed and minLed
      buttons[1].update();
      if (buttons[1].rose()) {
        minLed = minLed + 1;
        if (minLed > 11) {                                    //resets the indicator pixel back to 0 after a full rotation around the watch face
          minLed = 0;
        }
      }
      buttons[2].update();
      if (buttons[2].rose()) {
        hourLed = hourLed + 1;
        if (hourLed > 11) {
          hourLed = 0;
        }
      }
      buttons[3].update();
      buttons[0].update();
      if (buttons[3].rose() || buttons[0].rose()) {           //buttons 3 and 0 are used as a quick escape to the sleep mode
        mode = -1;
      }
      break;
    case 2:   //(game)
      buttons[0].update();
      buttons[1].update();                                    //quick esacpe to the sleep mode
      buttons[3].update();
      if (buttons[0].rose() || buttons[1].rose() || buttons[3].rose()) { 
        mode = -1;
      }
      buttons[2].update();
      if (buttons[2].rose() && neoPos == target) {            //if the button is pressed at the same time that the moving led is on top of the target led, call the winner() function
        winner();
      } else if (buttons[2].rose() && neoPos != target) {     //otherwise, call the loser() function
        loser();
      }
      break;
    case 3:   //(flashlight)
      buttons[0].update();                                    //any button press will enter the sleep mode
      buttons[1].update();
      buttons[2].update();
      buttons[3].update();
      if (buttons[0].rose() || buttons[1].rose() || buttons[2].rose() || buttons[3].rose()) {   
        mode = -1;                                           
      }
      break;
  }
}
