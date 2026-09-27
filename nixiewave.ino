#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN       6
#define NUMPIXELS 8



Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.setBrightness(32);
  pixels.begin();
}

void loop() {
    for(int i=1; i<NUMPIXELS; i++) {
      int DELAYVAL;
      DELAYVAL = 10+ pow(18-sq(i-3),4)/762;
      //DELAYVAL = 500;
      unsigned long longdelay = (unsigned long) DELAYVAL;
      pixels.setPixelColor(i, pixels.Color(224, 42, 0));
      pixels.setPixelColor(i-1, pixels.Color(192, 32, 0));
      pixels.setPixelColor(i-2, pixels.Color(160, 24, 0));
      pixels.setPixelColor(i-3, pixels.Color(128, 16, 0));
      pixels.setPixelColor(i-4, pixels.Color(96, 8, 0));
      pixels.show();
      delay(longdelay);
    }

    for(int i=NUMPIXELS; i>0; i--) {
      int DELAYVAL;
      DELAYVAL = 10+ pow(18-sq(i-3),4)/762;
      //DELAYVAL = 500;
      unsigned long longdelay = (unsigned long) DELAYVAL;
      pixels.setPixelColor(i, pixels.Color(224, 42, 0));
      pixels.setPixelColor(i+1, pixels.Color(192, 32, 0));
      pixels.setPixelColor(i+2, pixels.Color(160, 24, 0));
      pixels.setPixelColor(i+3, pixels.Color(128, 16, 0));
      pixels.setPixelColor(i+4, pixels.Color(96, 8, 0));

      pixels.show();
      delay(longdelay);
    }
}