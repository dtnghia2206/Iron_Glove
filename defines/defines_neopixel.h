#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/* Which pin on the Arduino is connected to the NeoPixels? */
#define PIN            6

/* How many NeoPixels are attached to the Arduino? */
#define NUMPIXELS      12

/* When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
/* Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
/* example for more information on possible values.
*/
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

/********************************************************************************************************************/
