long sleepTimer = 0;
long sleepInterval = 1000;
long minInterval = 2000;

void initButtons() {  //for loop to initialize all the buttons at once
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}
void fallAsleep() {   //function to put the watch to sleep for defined amount of time
  if (millis() - sleepTimer > sleepInterval) {
    strip.clear(); strip.show();                            // Clear out NeoPixel Display
    snore(3000);                                            // Go to Sleep for 5 Seconds
    sleepTimer = millis();
  }
}
