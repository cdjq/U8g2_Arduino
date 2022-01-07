/*!
 * @file Font.ino
 * @brief Display of several fonts that U8G2 supported
 * @n U8G2 supports kinds of fonts, this demo just displays several of them
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
 *@param Determine the basic layout:	 U8G2_R0 no rotation, landscape, draw from left to right
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
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);    //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9);

void setup(void)
{
  u8g2.begin();       //Init function
  u8g2.setFontPosTop();  /*When using drawStr to display a character string, the default criteria is to display the lower-left coordinate of the characters.
                          The function is used to change the criteria to display the upper-left coordinate of the characters.*/
}


void draw(int a )
{
   switch(a)
   {
     case 0: 
     u8g2.setFont(u8g2_font_bubble_tr   );    //Set font set, the font is "u8g2_font_bubble_tr"
     u8g2.drawStr(/* x=*/0,/* y=*/0, "DFR123");       //Start to draw the character string "DFR123" at the coordinates of x=0, y=0
     u8g2.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf     );
     u8g2.drawStr(0, 25, "DFR123");  
     u8g2.setFont(u8g2_font_HelvetiPixelOutline_tr     );
     u8g2.drawStr(0, 45, "DFR123"); 
     break;            
     case 1: 
     u8g2.setFont(u8g2_font_tenstamps_mr    );
     u8g2.drawStr(0,0, "DFR123");  
     u8g2.setFont(u8g2_font_jinxedwizards_tr      );
     u8g2.drawStr(56, 16, "DFR123");  
     u8g2.setFont(u8g2_font_secretaryhand_tr      );
     u8g2.drawStr(0, 32, "DFR123"); 
     u8g2.setFont(u8g2_font_freedoomr10_mu       );
     u8g2.drawStr(56, 48, "DFR123"); 
     break;                     
   }	   
}

 void loop()
{
  for( int i = 0; i <2 ; i++)
  {
   /*
	* firstPage method will change the current page number to 0
	* The content to be modified is between firstPage and nextPage; re-render all the content every time
	* This method consumed less ram than sendBuffer did
   */ 
    u8g2.firstPage();   
    do
	  {
		  draw(i);
	  } while( u8g2.nextPage() );
	  delay(2000);
  }
}
