/*
 Sunset - NeoPixel Based SmartWatch

 This project uses an ATTiny85 to display the time in an aesthetic and unique way. It is inspired
 by the colors of a sunset. For more information about the project visit https://www.behance.net/helenparris.

 There are 4 modes:
 1. Display Time
      Hours are displayed in the first sequential arc. The arc will end at the current hour position
      Minutes are displayed in the second arc. 
 2. Set Time
      Hours are represented by the red led and minutes are represented by the green led. 
      The two bottom buttons will adjust the hours and minutes. Pressing either of the top two buttons
      will exit the set time mode.
 3. Reflex Game
      Similar to an arcade game, there is a target that is represented by a stationary red led.
      Another red led will be rapidly moving around the neopixel ring. If you press the bottom 
      right button at the same time that the moving led is on top of the target led, you win, and all 
      the neopixels will light up green. If you don't hit the button at the right time, you lose, and 
      the neopixels light up red and reset the game for you to try again. 
 4. Flashlight
      The flashlight function will just light up all the neopixels to a bright white color. 
      Pressing any button will exit the mode.

 Hardware:
 - Custom designed PCB with 13 neopixels and 4 buttons
 - ATTiny85 processing chip
 - CR2032 lithium battery
 - AVRISP Programming Module (for programming the ATTiny 85)

 Software:
 - Arduino.ide
 - TimeLib.h library
 - Adafruit NeoPixel library
 - Bounce2.h library
 - tinysnore.h library
 - Zadig
 - ATTiny Core
 
 */
