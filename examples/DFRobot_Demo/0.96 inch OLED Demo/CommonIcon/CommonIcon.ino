/*!
 * @file CommonIcon.ino
 * @brief Display of several icons frequently used that U8G2 supported
 * @n U8G2 supports icons with various sizes, this demo will choose several of them to display
 * @n U8G2 icon GitHub link: https://github.com/olikraus/u8g2/wiki/fntlistall
 * 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ivey](Ivey.lu@dfrobot.com)
 * @version  V1.0
 * @date  2019-11-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/U8g2_Arduino
*/

#include <Arduino.h>
#include <U8g2lib.h>

#include <SPI.h>
#include <Wire.h>

/*
 *IIC constructor
 *@param Determine the overall layout:	 U8G2_R0 no rotation, landscape, draw from left to right
									U8G2_R1 Rotate 90 degree clockwise, draw from top to the bottom
									U8G2_R2 Rotate 180 degree clockwise, draw from right to the left
									U8G2_R3 Rotate 270 degree clockwise, draw from bottom to the top
									U8G2_MIRROR Display mirror content normally (used by v2.6.x version or later)   Note: U8G2_MIRROR need using with setFlipMode ()
 *@param reset：U8x8_PIN_NONE represent empty pin, will not use reset pin
 *SPI constructor
 *@param  cs Connect to the corresponding pin (select pin as per your needs)
 *@param  dc Connect to the corresponding pin (select pin as per your needs)
 *
*/
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9);


void setup(void)
{
  u8g2.begin();
  u8g2.setFontPosTop();  /*When using drawStr to display a character string, the default is to display the character coordinates at the bottom-left corner.
                          The function is used to change the coordinate position to the upper-left corner where displays character string.*/
}


/*
 * Select font set
 * u8g2_font_open_iconic_all_1x_t :Width :8  Height :8  encoding : 64-286
 * u8g2_font_open_iconic_all_2x_t :Width :16  Height :16  encoding : 64-286
 * u8g2_font_open_iconic_all_4x_t :Width :32  Height :32  encoding : 64-286
 * u8g2_font_open_iconic_all_6x_t :Width :48  Height :48  encoding : 64-286
 * u8g2_font_open_iconic_all_8x_t :Width :64  Height :64  encoding : 64-286
*/

/*
 * all:  app  arrow  check  email  embedded  gui  human  other  play  text  thing  weather  www
 * The encoding is started from 64 after all materialization, variable quantity (help save memory)
 *If you want to know the specific encoding value of each icon, you can view it by referring to icon though the link: https://github.com/olikraus/u8g2/wiki/fntlistall
*/
void loop(void)
{
  /*
   * firstPage method will change the current page number to 0
   * The content to be modified is between firstPage and nextPage; need to re-render all the content every time
   * The method consumed less ram than sendBuffer did
  */ 
   u8g2.firstPage();
   for(int i = 64 ; i <287; i++){
   u8g2.clear();
   do
   {
      u8g2.setFont(u8g2_font_open_iconic_all_4x_t );
      u8g2.drawGlyph(/* x=*/0, /* y=*/16, /* encoding=*/i);  //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
      u8g2.drawGlyph(/* x=*/48, /* y=*/16, /* encoding=*/i+1);  
      u8g2.drawGlyph(/* x=*/96, /* y=*/16, /* encoding=*/i+2);  
   } while ( u8g2.nextPage() );
   i = i+3;
   delay(2000);
  }
}


