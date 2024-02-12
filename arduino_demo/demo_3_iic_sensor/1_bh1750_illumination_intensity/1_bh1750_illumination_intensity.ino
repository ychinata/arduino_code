#include "bh1750.h"
 
void setup() {
    Serial.begin(9600);             //设置串口波特率为9600    
    BH1750_Init();                  //初始化BH1750
    Serial.println("设备上线！");
}

void loop() {
    BH1750_GetData();               // 获取光照强度数据
}


