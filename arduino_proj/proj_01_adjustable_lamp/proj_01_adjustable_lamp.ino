/*
参考：https://oshwhub.com/song2001/ke-diao-tai-deng
注：代码不全
*/
#include <Wire.h>
#include <SoftwareSerial.h>     // 无需下载库文件
#include <LiquidCrystal_I2C.h>  // 搜索库LiquidCrystal I2C
#include "bh1750.h"
#include "led_array.h"
#include "power_measure.h"
#include "softserial.h"

SoftwareSerial myserial(10, 11);
LiquidCrystal_I2C lcd(0x20, 16, 2);

// GY-30
// BH1750FVI
// in ADDR 'L' mode 7bit addr
//#define ADDR 0b0100011
// addr 'H' mode
#define ADDR 0b1011100
#define FILTER_A 1

int timess;
int trise = 255;    // 没有使用
int lights = 0;
int lights_secound;
int jobss = 1;
int Filter_Value;   // 没有使用
int count = 0;      // 没有使用
int num = 0;        // 没有使用
int i = 0;

void setup1() {
    Serial.begin(9600);
    myserial.begin(9600);
    // 四路灯板D3/5/6/9
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    lcd.init();     //初始化LCD
    lcd.backlight();//背光打开// put your setup code here, to run once:
    // key D8
    pinMode(8, INPUT);
}

void loop1() {
//  lights = analogRead(A1);
  //Serial.println(lights);
//  lights_secound = map(lights, 0, 1024, 0, 255);
//  analogWrite(3, 210);//1
//    analogWrite(5, 210);//2
//    analogWrite(6, 210);//
//    analogWrite(9, 210);
//  lcd.setCursor(2, 1);
//  lcd.print(lights_secound);
// if(button(7)){
// Serial.println("1111"); 
// }
// 
  // Serial.println(secound_int);
    if (button(8)) {
        jobss++;
        delay(5);
    }

    if (jobss == 1) {
        work1();
    }

    if (jobss == 2) {
        lcd.setCursor(0, 1);
        lcd.print("L=");
        lcd.setCursor(3,1);
        lcd.print("    ");
        lcd.setCursor(6,1);
        lcd.print("R");
        lcd.setCursor(0, 0);
        lcd.print("V=8.71");
        lcd.setCursor(6, 0);
        lcd.print("v");
        lcd.setCursor(9, 0);
        lcd.print("A=0.01");
        lcd.setCursor(15, 0);
        lcd.print("a");
        lcd.setCursor(9, 1);
        lcd.print("p=0.01");
        lcd.setCursor(15, 1);
        lcd.print("w");
    }

    if (jobss == 3) {
        work2();
    }

    if (jobss == 4) {
        jobss = 1;
    }
}

void work1() {
    lights = analogRead(A2);
    //Serial.println(lights);
    lights_secound = map(lights, 0, 1023, 0, 127);
    Serial.println(lights_secound*2); // 串口输出
    analogWrite(3, lights_secound*2);//1
    analogWrite(5, lights_secound*2);//2
    analogWrite(6, lights_secound*2);//
    analogWrite(9, lights_secound*2);
    // lcd打印功率测量:V-A-L(light)-P
    POWERMEASURE_Show(lights_secound);
    //
    SOFTSERIAL_Readmsg();
//  Serial.print("xxx");
}

// 有连接灯板吗?
void work2() {
    int val = SOFTSERIAL_Readmsg();
    Serial.println(val);
    LEDARRAY_Set(val);
}

// 按键消抖
bool button(int pin)
{
    if (digitalRead(pin)) {
        delay(20);
        //    if(digitalRead(pin))
        while (digitalRead(pin));
        return 1;
    }
    return 0;
}