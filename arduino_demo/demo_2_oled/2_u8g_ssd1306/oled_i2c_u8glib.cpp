#include "U8glib.h"
#include "oled_i2c_u8glib.h"
/*I2C协议*/
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE); 

//https://blog.csdn.net/malcolm_110/article/details/101448336

void OLED_I2C_U8glib_Init(void) {
    if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
        u8g.setColorIndex(255);     // white
    } else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
        u8g.setColorIndex(3);         // max intensity    
    } else if ( u8g.getMode() == U8G_MODE_BW ) {
        u8g.setColorIndex(1);         // pixel on
    }
    // u8g.setFont(u8g_font_unifont);

    u8g.setFont(u8g_font_osb18);   /*设置字体大小*/
    u8g.setFontRefHeightExtendedText();
    u8g.setDefaultForegroundColor();
    u8g.setFontPosTop();
}

void OLED_I2C_U8glib_Test(void) {
    u8g.firstPage();  
    do {
        u8g.drawStr(0,0,"hello world!");
        u8g.drawStr(0,20,"U8glib!");
        u8g.drawStr(10,40,"well done!");  /*设置起始位置*/
    } while(u8g.nextPage());
    delay(500);    
}
