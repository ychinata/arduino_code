#include <LiquidCrystal_I2C.h>  // 搜索库LiquidCrystal I2C
#include "power_measure.h"

extern LiquidCrystal_I2C lcd;

float vvv=0;
float aaa;
float ppp;
float k = 1.146;    // 如何确定？

// lcd打印功率测量:V-A-L(light)-P
void POWERMEASURE_Show(int lights_secound) {
// 第1行？
    lcd.setCursor(0, 1);
    lcd.print("L=");
    lcd.setCursor(3,1);
    lcd.print(lights_secound*2);
    if ((lights_secound*2<100)&&(lights_secound*2>10)) {
        lcd.setCursor(5,1);
        lcd.print(" ");
        // delay(3);
    }
    if (lights_secound*2<10) {
        lcd.setCursor(4,1);
        lcd.print("  ");
        // delay(3);
    }
    lcd.setCursor(6,1);
    lcd.print("R");
    // 第0行？
    vvv=analogRead(MEASURE_VOLTAGE_PIN);     //电压大小
    float spsps=vvv/100;
    lcd.setCursor(0, 0);
    lcd.print("U=");
    lcd.setCursor(2, 0);
    lcd.print(spsps);
    lcd.setCursor(6, 0);
    lcd.print("V");
    aaa=(analogRead(MEASURE_CURRENT_PIN) - 147) * k;//电流大小
    // Serial.println(aaa);
    lcd.setCursor(9, 0);
    lcd.print("I=");
    lcd.setCursor(11, 0);
    lcd.print((aaa/1000)-0.019);
    lcd.setCursor(15, 0);
    lcd.print("A");
    // 第1行？
    ppp=((aaa-20)*spsps)/1000;//计算功率
    lcd.setCursor(9, 1);
    lcd.print("P=");
    lcd.print(ppp+0.05);
    lcd.setCursor(15, 1);
    lcd.print("W");    
}