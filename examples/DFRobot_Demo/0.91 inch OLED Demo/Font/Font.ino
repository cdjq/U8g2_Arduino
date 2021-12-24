/*!
 * @file Font.ino
 * @brief Display of several fonts that U8G2 supported
 * @n U8G2 supports kinds of fonts, this demo just displays part of them
 * @n U8G2 font GitHub link: https://github.com/olikraus/u8g2/wiki/fntlistall
 * 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ajax](Ajax.zhong@dfrobot.com)
 * @version  V1.0
 * @date  2019-11-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/
*/
#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>

/*
 *IIC constructor
 *@param Determine the overall layout: 	 U8G2_R0 no rotation, landscape, draw from left to right
									U8G2_R1 Rotate 90 degree clockwise, draw from top to the bottom
									U8G2_R2 Rotate 180 degree clockwise, draw from right to the left
									U8G2_R3 Rotate 270 degree clockwise, draw from bottom to the top
									U8G2_MIRROR Display mirror content normally (used by v2.6.x version or later)   Note: U8G2_MIRROR need using with setFlipMode ()
 *@param reset：U8x8_PIN_NONE represent empty pin, will not use reset pin
 *
*/
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo


void setup(void){
  u8g2.begin();            //Init function
  u8g2.setFontPosTop();   /*When using drawStr to display a character string, the default is to display the character coordinates at the bottom-left corner.
                          The function is used to change the coordinate position to the upper-left corner where displays character string.*/
    }

void loop(void){
  u8g2.clearBuffer();            //Clear buffer  
  u8g2.setFont(u8g2_font_maniac_tr); //Set "u8g2_font_maniac_tr" as a font 
  u8g2.drawStr(/* x=*/0, /* y=*/5, "DFR123");  //Start to draw the character string "DFR123" at the coordinates of x=0，y=5  
  u8g2.sendBuffer();          //Send buffer to the display      
  
  delay(1000);               //Delay 1000ms
   
  u8g2.clearBuffer();             
  
  u8g2.setFont(u8g2_font_secretaryhand_tf); 
  u8g2.drawStr(0, 0, "DFR123");   
  
  u8g2.setFont(u8g2_font_heavybottom_tr);
  u8g2.drawStr(70, 0, "DFR12");   //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
  
  u8g2.setFont(u8g2_font_fancypixels_tf);
  u8g2.drawStr(0, 20, "DFR123");  //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
  
  u8g2.setFont(u8g2_font_fancypixels_tf);
  u8g2.drawStr(70, 20, "DFR123");  //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
  
  u8g2.sendBuffer();               
  delay(1000); 
}
