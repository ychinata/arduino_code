/********************************************
 *@File: 基于Arduino Nano的LED调光灯 
 *@Author: xxy
 *@Date: 2024.2.14
 *********************************************/
#include <Wire.h>
#include <DHT.h>  // 安装DHT sensor library和Adafruit Unified Sensor两个库
#include "bh1750.h"
#include "led_array.h"
#include "oled_i2c_adafruit.h"
#include "power_measure.h"
#include "rotary_encoder.h"

//定义针脚
#define DHTPIN 8 
//定义类型，DHT11或者其它
#define DHTTYPE DHT11
//进行初始设置 
DHT dht(DHTPIN, DHTTYPE);

// IO config
#define LED_PIN 5   // D5
//

void setup() {
    // 初始化
    Serial.begin(9600);
    BH1750_Init();                  //初始化BH1750
    OLED_I2C_Adafruit_Init();  
    ROTARYENCODER_Init();  
    dht.begin(); //DHT开始工作

    // 一路灯板D4
    pinMode(LED_PIN, OUTPUT);
    // key D8
    pinMode(8, INPUT);
}

void loop() {
    //Serial.println(lights);
    double brightValue = 0.0;
    int ledPwmValue = 0;
    int lux = 0;
    float humidity = 0.0;
    float temp = 0.0; 
    
    brightValue = 100;
    //brightValue = ROTARYENCODER_GetData();          // 获取编码器设定的亮度值
    ledPwmValue = map(brightValue, 0, 360, 0, 255); // 将编码器原始值0-360映射到pwm值0-255,超出0-360的范围会重新映射
    LED_SetPinPwm(LED_PIN, ledPwmValue);            // 调光
    ROTARYENCODER_Show();                           // 调光值维测
    //Serial.println(ledPwmValue);
    lux = BH1750_GetData();                         // 获取光照强度数据
    DHT11_Getdata(&humidity, &temp);                // 获取温度和温度
    OLED_ShowBright(brightValue, ledPwmValue, lux, humidity, temp);
    //DHT11_Showdata();
    delay(2000);
}

/* 获取DHT11的温度和湿度
 * 结果为两位小数：Humidity: 52.00, Temperature: 30.40
 */
void DHT11_Getdata(float* humidity, float* temp) {
    if (humidity == nullptr || temp == nullptr) {
        Serial.print("DHT11_Getdata error! Nullptr.");
        return;
    }
    // 两次检测之间，要等几秒钟，这个传感器有点慢。
    //delay(2000);
    // 读温度或湿度要用250毫秒
    *humidity = dht.readHumidity();//读湿度
    *temp = dht.readTemperature();//读温度，默认为摄氏度
}

void DHT11_Showdata() {
    float humidity = 0.0;
    float temp = 0.0;

    DHT11_Getdata(&humidity, &temp);
    Serial.print("Humidity: ");//湿度
    Serial.println(humidity);
    Serial.print("Temperature: ");//温度
    Serial.print(temp);
    Serial.println(" ℃ ");
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
