/*!
 * @file FontDirection.ino
 * @brief U8G2 font rotation display
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
 *@param Determine the basic layout: 	 U8G2_R0 no rotation, landscape, draw from left to right
									U8G2_R1 Rotate 90 degree clockwise, draw from top to the bottom
									U8G2_R2 Rotate 180 degree clockwise, draw from right to the left
									U8G2_R3 Rotate 270 degree clockwise, draw from bottom to the top
									U8G2_MIRROR Display mirror content normally (used by v2.6.x version or later)   Note: U8G2_MIRROR need using with setFlipMode ()
 *@param reset：U8x8_PIN_NONE represent empty pin, will not use reset pin
 *
*/
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo

const uint8_t col[] U8X8_PROGMEM= {0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0x00,
                                         0x00,0xc0,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xf8,0x07,0x00,
                                         0x06,0xfe,0x1f,0x18,0x07,0xff,0x3f,0x38,0xdf,0xff,0xff,0x3e,0xfa,0xff,0xff,0x17,
                                         0xf0,0xff,0xff,0x03,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,
                                         0xe0,0xff,0xff,0x01,0x20,0x00,0x00,0x01,0xa0,0xff,0x7f,0x01,0xa0,0x01,0x60,0x01,
                                         0x20,0x07,0x38,0x01,0xe0,0x0c,0xcc,0x01,0xe0,0x39,0xe7,0x01,0xe0,0xe7,0xf9,0x01,
                                         0xc0,0x1f,0xfe,0x00,0x80,0xff,0x7f,0x00,0x00,0xfe,0x1f,0x00,0x00,0xf8,0x07,0x00,
                                         0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0x00}; // Graphics data, size is 30x30

                                         

void setup() {
  u8g2.begin();  //Init function
}

void loop(void)
{ 
    u8g2.clearBuffer();    //Clear buffer

    u8g2.drawXBMP( /* x=*/0 , /* y=*/0 , /* width=*/30 , /* height=*/30 , col );     //Graphics size is 30x30 and can be changed based on the actual size.
    
    u8g2.setFont(u8g2_font_pxplusibmvga9_tf);   //Select "u8g2_font_pxplusibmvga9_tf" as a font
    for(int i = 0; i < 4;i++)
    {
      switch(i)
      {
        case 0:
        /*@brief Set the drawing direction of all the character string or fonts setFontDirection(uint8_t dir)
         *@param dir=0, Rotate 0 degree
				 dir=1, rotate 90 degree
				 dir=2, rotate 180 degree
				 dir=3, rotate 270 degree
        */
        u8g2.setFontDirection(0);           
        u8g2.drawStr(/* x=*/33, /* y=*/32, "DFR");
        break;
        
        case 1:
        u8g2.setFontDirection(1);
        u8g2.drawStr(66, 7, "DFR");
        break;
        
        case 2:
        u8g2.setFontDirection(2);
        u8g2.drawStr(110, 21, "DFR");
        break;
        
        case 3:
        u8g2.setFontDirection(3);
        u8g2.drawStr(128, 32, "DFR");
        break;
      }
      delay(500);
      u8g2.sendBuffer();//Send buffer data to the display
    }

}
