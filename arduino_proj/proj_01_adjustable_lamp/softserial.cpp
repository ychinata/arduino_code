#include <SoftwareSerial.h>     // 无需下载库文件
#include "softserial.h"

String teststring = "";
//char s;/
String first = "";
String secound = "";
//char d[10];
int first_int = 0;
int secound_int = 0;
//int first_int_begin=0;
//int secound_int_begin=0;

extern SoftwareSerial myserial;
// 读取软串口消息, 哪里发送消息呢？
//此处修改为了 int  void
int SOFTSERIAL_Readmsg(void) {
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
