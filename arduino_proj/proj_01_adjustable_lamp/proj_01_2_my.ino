/********************************************
 *@File: 基于Arduino Nano的LED调光灯 
 *@Author: xxy
 *@Date: 2024.2.14
 *********************************************/
#include <Wire.h>
#include "bh1750.h"
#include "led_array.h"
#include "oled_i2c_adafruit.h"
#include "power_measure.h"
#include "rotary_encoder.h"

// IO config
#define LED_PIN 5   // D5
//

void setup() {
    // 初始化
    Serial.begin(9600);
    OLED_I2C_Adafruit_Init();  
    ROTARYENCODER_Init();  

    // 一路灯板D4
    pinMode(LED_PIN, OUTPUT);
    // key D8
    pinMode(8, INPUT);
}

void loop() {
    //Serial.println(lights);
    double brightValue = 0.0;
    int ledPwmValue = 0;
    
    brightValue = ROTARYENCODER_GetData();          // 获取编码器设定的亮度值
    ledPwmValue = map(brightValue, 0, 360, 0, 255); // 将编码器原始值0-360映射到pwm值0-255,超出0-360的范围会重新映射
    LED_SetPinPwm(LED_PIN, ledPwmValue);            // 调光
    //LED_SetPinBlink(LED_PIN);
    ROTARYENCODER_Show();       // 调光值维测
    //Serial.println(ledPwmValue);
    OLED_ShowBright(brightValue, ledPwmValue);
}

void work3() {
    int lights = analogRead(A2);
    //Serial.println(lights);
    int lights_secound = map(lights, 0, 1023, 0, 127);
//  Serial.print("xxx");
}

// 有连接灯板吗?
void work4() {
    int val = 0;
    Serial.println(val);
    LEDARRAY_Set(val);
}
