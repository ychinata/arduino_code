#include "oled_i2c_adafruit.h"

void setup() {
    Serial.begin(9600);
    OLED_I2C_Adafruit_Init();
    //test
    OLED_I2C_Adafruit_DrawStrShow(0, 8, "TonyCode", 1);
    //
    OLED_I2C_Adafruit_DrawStrSize2Test();
    

}

void loop() {
  OLED_I2C_Adafruit_ScrollTest();
}
