/********************************************
 *@File: 0.91/0.96寸OLED滚动显示(使用Adafruit库)
        需要安装三个库：Adafruit_BusIO、Adafruit_GFX_Library、Adafruit_SSD1306
 *@Author: Cseexy
 *@Date: 2024.2.11
 *@Description: SDA<->A4
                SCL<->A5
 *********************************************/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// On an arduino UNO/NANO:   A4(SDA), A5(SCL)
// On an arduino MEGA 2560:  20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // 0.96寸64, 0.91寸32
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // See datasheet for Address:3C/3D

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    Serial.begin(9600);
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    // 显示开机Adafruit画面(在初始buffer里)
    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds
    // Clear the buffer
    display.clearDisplay();
    // 显示开机Adafruit画面end

    display.setTextColor(WHITE);    //开像素点发光
    display.clearDisplay();         //清屏
    display.setTextSize(2); //设置字体大小
    display.setCursor(0, 8);//设置显示位置
    display.println("TonyCode");
    display.display(); // 开显示
}

void loop() {
    // 向右滚屏
    display.startscrollright(0x00, 0x0F);
    delay(5000);
    display.stopscroll();
    // 向左滚屏
    display.startscrollleft(0x00, 0x0F);
    delay(1000);
    display.stopscroll();
}
