// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// 通过256级亮度的变化来实现呼吸灯效果，使用的是库函数，而不是直接实现PWM
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            9

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1000; // ms

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    roundLed(); // 逐一亮灯
    closeLed();//关灯

    roundLedOneByOne();

    colorLed();//彩灯
    closeLed();

    breathLed();//呼吸灯
}

// 逐一亮灯,亮完不灭
void roundLed() {
    int bright = 255;
    for (int i=0; i < NUMPIXELS; i++) {
        if (i >= 4) {
            bright = 10;
        }
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,bright,0)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).
    }  
}

// 逐一亮灯,亮完即灭
void roundLedOneByOne() {
    for (int i=0; i < NUMPIXELS; i++) {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).
        closeOneLed(i);
    }  
}

// 关指定的灯
void closeOneLed(int i) {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show(); 
    delay(delayval); 
}

// 全部关灯
void closeLed() {
    for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    pixels.show(); 
    delay(delayval); 
}

// 随机彩灯
void colorLed() {
    for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(random(255),random(255),random(255)));
    }
    pixels.show(); 
    delay(delayval);
}

// 呼吸灯
void breathLed() {
    for(int i=0;i<NUMPIXELS;i++){
        for(int a=0;a<=255;a++){
            pixels.setPixelColor(i, pixels.Color(0,a,0));
            pixels.show(); 
            delay(8);
        }
        for(int a=255;a>=0;a--){
            pixels.setPixelColor(i, pixels.Color(0,a,0));
            pixels.show(); 
            delay(8);
        }
        // 最后是灭灯
    }
    delay(delayval);
}
