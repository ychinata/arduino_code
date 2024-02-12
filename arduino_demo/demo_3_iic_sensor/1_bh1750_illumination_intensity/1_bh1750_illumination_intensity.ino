/****************************************bh1750 part****************************************/
/*
  接线：
  3.3------VCC
  GND------GND
  SCL------SCL
  SDA------SDA
    https://blog.csdn.net/qq_55490300/article/details/130967259  
*/
#include <Wire.h>                                                   //调用库文件  
#include <math.h>                                                   //调用库文件  
 
int bh1750address = 0x23;                                           //设备IIC地址
 
byte buff[2];                                                       //定义数组
int bh1750Val = 0;
#define bh1750TimeInterval 1000                                     //检测一次的时间间隔 
unsigned long bh1750Times = 0;                                      //记录设备运行时间
 
void setup() {
    Serial.begin(9600);                                               //设置串口波特率为9600
    Wire.begin();                                                     //IIC通讯初始化
    BH1750_Init(bh1750address);                                       //初始化bh1750
    Serial.println("设备上线！");
}

void loop() {
    getBh1750Data();                                                  //获取数据
}

/* BH1750初始化地址 */
void BH1750_Init(int address) {
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.endTransmission();
}

/* BH1750读取数据 */
int BH1750_Read(int address) {
    int i = 0;
    Wire.beginTransmission(address);
    Wire.requestFrom(address, 2);   // 读取两字节
    while (Wire.available()) {
        buff[i] = Wire.read();                                          //接收一个字节
        i++;
    }
    Wire.endTransmission();
    return i;       // 修改为ok/nok, error=-1, ok=0
}

/* BH1750获取数据 */
void getBh1750Data() {
    if (millis() - bh1750Times >= bh1750TimeInterval) {              //一定时间执行一次
        bh1750Times = millis();
        if (2 == BH1750_Read(bh1750address)) {
            bh1750Val = ((buff[0] << 8) | buff[1]) / 1.2;
            Serial.print(bh1750Val);                                     //串口打印对应的值
            Serial.println("[lx]");                                      //串口打印对应的值
        }
    }
}
