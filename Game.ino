int neoPos = 0;                  //stores the position of the moving pixel
int target = random (0, 12);     //stores a random value for the 'target' pixel
int gameInterval = 60;           
int gameStart = millis();
int gameEnd;

void game() {   //function that plays a reflex game
  strip.setPixelColor(12, 0, 0, 0); strip.show(); gameEnd = millis();
  for (int i = 0; i < strip.numPixels() - 1 ; i++) {
    if (i == neoPos) {                                              //set the moving pixel color
      strip.setPixelColor(neoPos, 255, 0, 0);
    }
      if (i == target) {                                            //set the target pixel color
        strip.setPixelColor(target, 255, 0, 0);
      }
    }
    if (gameEnd - gameStart >= gameInterval) {
    neoPos = neoPos + 1;                                            //moves the moving pixel after every timer event
    strip.show();
    for (int i = 0; i < strip.numPixels() - 1; i++) {               //for loop that sets all pixels that are not the target or moving pixel to be cyan
      if (i != neoPos) {
        if (i != target) {
          strip.setPixelColor(i, 0, 155, 155);
        }
      }
      if (neoPos > strip.numPixels() - 1) { 
        neoPos = 0;                                                 //resets the moving pixel after each completed rotation
      }
    }
    gameStart = millis();
  }
  strip.show();
}
void winner() {   //function that is called when you win the game
  strip.setPixelColor(12, 0, 0, 0);
  for (int i = 0; i < strip.numPixels() - 1; i++) {
    strip.setPixelColor(i, 0, 255, 0);                              //sets all pixels to green
    strip.show();
  }
  delay(1000);
  target = random(0, 12);                                           //resets the target to a new random pixel after a round
  mode = -1;                                                        //goes to sleep after a win
}
void loser() {    //function that is called when you lose the game
  strip.setPixelColor(12, 0, 0, 0);
  for (int i = 0; i < strip.numPixels() - 1; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
  delay(1000);
  target = random(0, 12);                                           //resets the target to a new random pixel after a round
}
