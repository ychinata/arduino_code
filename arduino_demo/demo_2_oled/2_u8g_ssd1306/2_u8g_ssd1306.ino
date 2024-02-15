#include "oled_i2c_u8glib.h"

void setup() {
    Serial.begin(9600);
    OLED_I2C_U8glib_Init();
    OLED_I2C_U8glib_Test();
}

void loop() {

}