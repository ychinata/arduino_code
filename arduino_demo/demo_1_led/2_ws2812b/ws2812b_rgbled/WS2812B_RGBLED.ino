// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1000; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    for(int i=0; i < NUMPIXELS; i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).
    }
    closeLed();//关灯
    colorLed();//彩灯
    closeLed();
    breathLed();//呼吸灯
}

void closeLed() {
    for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    pixels.show(); 
    delay(delayval); 
}

void colorLed() {
    for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(random(255),random(255),random(255)));
    }
    pixels.show(); 
    delay(delayval);
}

void breathLed() {
    for(int i=0;i<NUMPIXELS;i++){
        for(int a=0;a<255;a++){
            pixels.setPixelColor(i, pixels.Color(0,a,0));
            pixels.show(); 
            delay(8);
        }
        for(int a=255;a>=0;a--){
            pixels.setPixelColor(i, pixels.Color(0,a,0));
            pixels.show(); 
            delay(8);
        }
    }
    delay(delayval);
}
