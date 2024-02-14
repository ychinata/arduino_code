/*
参考：https://oshwhub.com/song2001/ke-diao-tai-deng
注：代码不全
*/
#include <Wire.h>
#include "bh1750.h"
#include "led_array.h"
#include "power_measure.h"

#define LED_PIN 5   // D5

void setup() {
    Serial.begin(9600);
    // 一路灯板D4
    pinMode(LED_PIN, OUTPUT);
    // key D8
    pinMode(8, INPUT);
}

void loop() {
//  lights = analogRead(A1);
  //Serial.println(lights);
//  lights_secound = map(lights, 0, 1024, 0, 255);

    LED_SetPinBlink(LED_PIN);

// if(button(7)){
// Serial.println("1111"); 
// }
    //work3();
    //work4();
}

void work3() {
    int lights = analogRead(A2);
    //Serial.println(lights);
    int lights_secound = map(lights, 0, 1023, 0, 127);
    Serial.println(lights_secound*2); // 串口输出
    analogWrite(3, lights_secound*2);//1
    analogWrite(5, lights_secound*2);//2
    analogWrite(6, lights_secound*2);//
    analogWrite(9, lights_secound*2);
//  Serial.print("xxx");
}

// 有连接灯板吗?
void work4() {
    int val = 0;
    Serial.println(val);
    LEDARRAY_Set(val);
}
