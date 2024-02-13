/*
参考：https://oshwhub.com/song2001/ke-diao-tai-deng
*/
#include <Wire.h>
#include <SoftwareSerial.h>     // 无需下载库文件
#include <LiquidCrystal_I2C.h>  // 搜索库LiquidCrystal I2C
#include "bh1750.h"
#include "led_array.h"

SoftwareSerial myserial(10, 11);
LiquidCrystal_I2C lcd(0x20, 16, 2);

// GY-30
// BH1750FVI
// in ADDR 'L' mode 7bit addr
//#define ADDR 0b0100011
// addr 'H' mode
#define ADDR 0b1011100
#define FILTER_A 1

String teststring = "";
//char s;/

String first = "";
String secound = "";
//char d[10];
int first_int = 0;
int secound_int = 0;
//int first_int_begin=0;
//int secound_int_begin=0;
int timess;
int trise = 255;
int lights = 0;
int lights_secound;
int jobss = 1;
int Filter_Value;
int count = 0;
int num = 0;
int i = 0;
float vvv=0;
float aaa;
float ppp;
int Value;
float k = 1.146;

void setup() {
    Serial.begin(9600);
    myserial.begin(9600);
    // 四路灯板D3/5/6/9
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    lcd.init(); //初始化LCD
    lcd.backlight();//背光打开// put your setup code here, to run once:
    // key D8
    pinMode(8, INPUT);

  //Value=251;
}

void loop() {
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
//    lcd.clear();
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
//    work2();
    }

    if (jobss == 3) {
        //    lcd.clear();
        //lcd.setCursor(3,1);
        //  lcd.print("   ");
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
    lcd.setCursor(0, 1);
    lcd.print("L=");
    lcd.setCursor(3,1);

    lcd.print(lights_secound*2);
    if ((lights_secound*2<100)&&(lights_secound*2>10)) {
        lcd.setCursor(5,1);
        lcd.print(" ");
        //    delay(3);
    }

    if (lights_secound*2<10) {
        lcd.setCursor(4,1);
        lcd.print("  ");
    //    delay(3);
    }

    lcd.setCursor(6,1);
    lcd.print("R");
    vvv=analogRead(A1);
    float spsps=vvv/100;
    lcd.setCursor(0, 0);
    lcd.print("V=");
    lcd.setCursor(2, 0);
    lcd.print(spsps);
    lcd.setCursor(6, 0);
    lcd.print("v");
    aaa=(analogRead(A0) - 147) * k;//电流大小
    // Serial.println(aaa);
    lcd.setCursor(9, 0);
    lcd.print("A=");
    lcd.setCursor(11, 0);
    lcd.print((aaa/1000)-0.019);
    lcd.setCursor(15, 0);
    lcd.print("a");

    ppp=((aaa-20)*spsps)/1000;//计算功率
    lcd.setCursor(9, 1);
    lcd.print("p=");
    lcd.print(ppp+0.05);
    lcd.setCursor(15, 1);
    lcd.print("w");
    read_message();
//  Serial.print("xxx");
}

void work2() {
    read_message();
    Serial.println(secound_int);
    LEDARRAY_Set(secound_int);
}

//此处修改为了 int  void
void  read_message() {
    if (myserial.available() > 0) {
        char s = myserial.read();
        if (s == 'n') {
            // Serial.println(teststring);
            first = teststring;
            teststring = "";
        } else if (s == 'v') {
            // Serial.println(teststring);
            secound = teststring;
            teststring = "";
        } else {
            teststring += s;
            delay(15);
        }
    }
    first_int = first.toInt();
    secound_int = secound.toInt();
    if (first_int < 0) {
        first_int = first_int * -1;
    }
    if (secound_int < 0) {
        secound_int = secound_int * -1;
    }

    //Serial.println(secound_int);
    //此处返回值
    //Serial.println((secound_int*4)+ 100);
    //  return ((secound_int * 4) + 100);
    //Serial.println(secound_int);
    return secound_int;
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
