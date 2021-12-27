/*!
 * @file Font.ino
 * @brief Display of several fonts direction that U8G2 supported
 * @n U8G2 supports kinds of fonts, this demo just displays four directions (no display mirror)
 * @n U8G2 font GitHub link: https://github.com/olikraus/u8g2/wiki/fntlistall
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
 *@param Determine the overall layout: 	 U8G2_R0 no rotation, landscape, draw from left to right
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


//width:30,height:30 
const uint8_t col[] U8X8_PROGMEM= {0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xe0,0x01,0x00,0x00,
                                         0xc0,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0xe0,
                                         0x01,0x00,0x00,0xf8,0x07,0x00,0x06,0xfe,0x1f,0x18,0x07,0xff,0x3f,
                                         0x38,0xdf,0xff,0xff,0x3e,0xfa,0xff,0xff,0x17,0xf0,0xff,0xff,0x03,
                                         0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,0xe0,
                                         0xff,0xff,0x01,0x20,0x00,0x00,0x01,0xa0,0xff,0x7f,0x01,0xa0,0x01,
                                         0x60,0x01,0x20,0x07,0x38,0x01,0xe0,0x0c,0xcc,0x01,0xe0,0x39,0xe7,
                                         0x01,0xe0,0xe7,0xf9,0x01,0xc0,0x1f,0xfe,0x00,0x80,0xff,0x7f,0x00,
                                         0x00,0xfe,0x1f,0x00,0x00,0xf8,0x07,0x00,0x00,0xe0,0x01,0x00,0x00,
                                         0xc0,0x00,0x00}; 

void setup() {
  u8g2.begin();
  u8g2.setFontPosTop();/*When using drawStr to display a character string, the default is to display the character coordinates at the bottom-left corner.
                          The function is used to change the coordinate position to the upper-left corner where displays character string.*/
}

void Rotation() {
  u8g2.setFont(u8g2_font_bracketedbabies_tr        );
  u8g2.firstPage(); 
  do {
    u8g2.drawXBMP( /* x=*/0 , /* y=*/0 , /* width=*/30 , /* height=*/30 , col );//Draw graphics
	/*@brief Set the drawing direction of all the character string or fonts setFontDirection(uint8_t dir)
     *@param dir=0, Rotate 0 degree
		     dir=1, rotate 90 degree
			 dir=2, rotate 180 degree
			 dir=3, rotate 270 degree
    */
    u8g2.setFontDirection(0);			
    u8g2.drawStr( /* x=*/64,/* y=*/32, " DFR");		//Draw character string
    u8g2.setFontDirection(1);
    u8g2.drawStr(64,32, " DFR");
    u8g2.setFontDirection(2);
    u8g2.drawStr(64,32, " DFR");
    u8g2.setFontDirection(3);
    u8g2.drawStr(64,32, " DFR");
  }while(u8g2.nextPage()); 
  delay(1500);
}

void loop(void)
{ 
    u8g2.setFont( u8g2_font_sticker_mel_tr      );
    for(int i = 0 ; i < 4 ; i++ )
    {
       switch(i)
       {
          case 0:
            u8g2.setFontDirection(0);
            break;
          case 1:
            u8g2.setFontDirection(1);
            break;
          case 2:
            u8g2.setFontDirection(2);
            break;
          case 3: 
            u8g2.setFontDirection(3);
            break;
       }
	  /*
	   * firstPage method will change the current page number to 0
	   * The content to be modified is between firstPage and nextPage; need to re-render all the content every time
	   * The method consumed less ram than sendBuffer did
	  */ 
      u8g2.firstPage();  
      do 
      {
        u8g2.drawStr(64, 32, "DFR");
        u8g2.drawXBMP( 0 , 0 , 30 , 30 , col );
      }while(u8g2.nextPage()); 
      delay(500);
    }
    Rotation();
}
