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
    /*
    // 向右滚屏
    display.startscrollright(0x00, 0x0F);
    delay(5000);
    display.stopscroll();
    // 向左滚屏
    display.startscrollleft(0x00, 0x0F);
    delay(1000);
    display.stopscroll();
    */
}
