/*!
 * @file Language.ino
 * @brief Display multiple languages in U8G2
 * @n Demonstrate "hello world!" in Chinese, English, Korean and Japanese
 * @n U8G2 font GitHub link: https://github.com/olikraus/u8g2/wiki/fntlistall
 * 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ajax](Ajax.zhong@dfrobot.com)
 * @version  V1.0
 * @date  2019-11-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/U8g2_Arduino
*/
#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>

/*
 *IIC constructor
 *@param Determine the overall layout:	 U8G2_R0 no rotation, landscape, draw from left to right
									U8G2_R1 Rotate 90 degree clockwise, draw from top to the bottom
									U8G2_R2 Rotate 180 degree clockwise, draw from right to the left
									U8G2_R3 Rotate 270 degree clockwise, draw from bottom to the top
									U8G2_MIRROR Display mirror content normally (used by v2.6.x version or later)   Note: U8G2_MIRROR need using with setFlipMode ()
 *@param reset：U8x8_PIN_NONE represent empty pin, will not use reset pin
 *
*/
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //M0/ESP32/ESP8266/mega2560/Uno/Leonardo

void setup(void) {
  u8g2.begin();    //Init function
  u8g2.enableUTF8Print();		// Enable UTF8 to support Arduino print () function
}

void loop(void) 
{
  /*Note that the character library occupies large memory. If only a few characters need displaying, the coding of Chinese characters can be obtained,
  Display them through the method of drawXBM, or use the MCU with larger memory*/
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  //Apply chinese2 to all the fonts of "hello world"
  //u8g2.setFont(u8g2_font_b10_t_japanese1);  // All the fonts of "こんにちは世界" are contained in Japanese: Lerning 1-6 level
  //u8g2.setFont(u8g2_font_unifont_t_korean1);  // All the fonts of "안녕하세요세계" are contained in Korean: Lerning 1-2 level
  u8g2.setFontDirection(0);   //Set font direction, rotate 0 degree, from left to right
  
   /*
   * firstPage method will change the current page number to 0
   * The content to be modified is between firstPage and nextPage; need to re-render all the content every time
   * The method consumed less ram than sendBuffer did
  */
  
  u8g2.firstPage();
  do {
    u8g2.setCursor(/* x=*/0, /* y=*/15);    //Define the print function cursor, where any output of the print function starts
    u8g2.print("Hello World!");
    u8g2.setCursor(0, 30);
    u8g2.print("你好世界");		// Chinese "Hello World" 
    //u8g2.print("こんにちは世界");		// Japanese "Hello World" 
    //u8g2.print("안녕하세요 세계");   // Korean "Hello World" 
  } while ( u8g2.nextPage() );
  delay(1000);
}
