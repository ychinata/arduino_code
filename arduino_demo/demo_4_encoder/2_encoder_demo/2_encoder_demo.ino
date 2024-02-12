/*
   旋转编码器读取（带开关），不使用中断实现
   https://www.cnblogs.com/54programer/p/15806912.html
    注：效果不好，不如使用中断的方式

   Power LCD and Rotary encoder from the +5V pin of Arduino
   LCD RS -> pin 7
   LCD EN -> pin 6
   LCD D4 -> pin 5
   LCD D5 -> pin 4
   LCD D6 -> pin 3
   LCD D7 -> pin 2
   Encoder Switch -> pin 10
   Encoder Output A -> pin 9
   Encoder Output B -> pin 8   
*/
#include <LiquidCrystal.h>  //Default Arduino LCD Librarey is included

// 带开关的旋转编码器
int Encoder_OuputA  = 2;
int Encoder_OuputB  = 3;
int Encoder_Switch = 10;

int Previous_Output;
int Encoder_Count = 0;

// 常规针脚的LCD
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //Mention the pin number for LCD connection
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    Serial.begin(9600);

    lcd.begin(16, 2); //Initialise 16*2 LCD
    lcd.print(" Rotary Encoder "); //Intro Message line 1
    lcd.setCursor(0, 1);
    lcd.print("  With Arduino  "); //Intro Message line 2
    delay(2000);
    lcd.clear();

    //pin Mode declaration
    pinMode (Encoder_OuputA, INPUT);
    pinMode (Encoder_OuputB, INPUT);
    pinMode (Encoder_Switch, INPUT);
    Previous_Output = digitalRead(Encoder_OuputA); //Read the inital value of Output A
}

void loop() {
    //aVal = digitalRead(pinA);
    if (digitalRead(Encoder_OuputA) != Previous_Output) {
        if (digitalRead(Encoder_OuputB) != Previous_Output) {
            Encoder_Count ++;
            lcd.clear();
            lcd.print(Encoder_Count);            
            lcd.setCursor(0, 1);
            lcd.print("Clockwise");
        } else {
            Encoder_Count--;
            lcd.clear();
            lcd.print(Encoder_Count);
            lcd.setCursor(0, 1);
            lcd.print("Anti - Clockwise");
        }
        Serial.println(Encoder_Count);
    }

    Previous_Output = digitalRead(Encoder_OuputA);

    if (digitalRead(Encoder_Switch) == 0) {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Switch pressed");
    }
}