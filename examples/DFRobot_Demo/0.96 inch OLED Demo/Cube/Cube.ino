/*!
 * @file Cube.ino
 * @brief Rotating 3D graphics
 * @n This is a simple rotating tetrahedron
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
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9);


//2D array that stores the coordinates of all the vertices of the tetrahedron
double tetrahedron[4][3] = {{0,30,-30},{-30,-30,-30},{30,-30,-30},{0,0,30}};
void setup(void) {
  u8g2.begin();  
}

void loop(void) {
  u8g2.firstPage();
  do {
  //Draw line to connect the corresponding vertices of the tetrahedron
  u8g2.drawLine(OxyzToOu(tetrahedron[0][0], tetrahedron[0][2]), OxyzToOv(tetrahedron[0][1], tetrahedron[0][2]), OxyzToOu(tetrahedron[1][0], tetrahedron[1][2]), OxyzToOv(tetrahedron[1][1], tetrahedron[1][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[1][0], tetrahedron[1][2]), OxyzToOv(tetrahedron[1][1], tetrahedron[1][2]), OxyzToOu(tetrahedron[2][0], tetrahedron[2][2]), OxyzToOv(tetrahedron[2][1], tetrahedron[2][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[0][0], tetrahedron[0][2]), OxyzToOv(tetrahedron[0][1], tetrahedron[0][2]), OxyzToOu(tetrahedron[2][0], tetrahedron[2][2]), OxyzToOv(tetrahedron[2][1], tetrahedron[2][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[0][0], tetrahedron[0][2]), OxyzToOv(tetrahedron[0][1], tetrahedron[0][2]), OxyzToOu(tetrahedron[3][0], tetrahedron[3][2]), OxyzToOv(tetrahedron[3][1], tetrahedron[3][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[1][0], tetrahedron[1][2]), OxyzToOv(tetrahedron[1][1], tetrahedron[1][2]), OxyzToOu(tetrahedron[3][0], tetrahedron[3][2]), OxyzToOv(tetrahedron[3][1], tetrahedron[3][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[2][0], tetrahedron[2][2]), OxyzToOv(tetrahedron[2][1], tetrahedron[2][2]), OxyzToOu(tetrahedron[3][0], tetrahedron[3][2]), OxyzToOv(tetrahedron[3][1], tetrahedron[3][2]));
  // Rotate 0.1 degree
  rotate(0.1);
  
  } while ( u8g2.nextPage() );
  //delay(50);
}
/*！
 * @brief Convert the xz in the 3D coordinate system Oxyz to u in the 2D coordinate system Ouv
 * @param X-axis in the 3D coordinate system Oxyz    
 * @param Z-axis in the 3D coordinate system Oxyz
 * @return U-axis in the 2D coordinate system Ouv
 */
int OxyzToOu(double x,double z){
   
   return (int)((x + 64) - z*0.35);
}


/*！
 * @brief Convert the yz in the 3D coordinate system Oxyz to v in the 2D coordinate system Ouv
 * @param Y-axis in the 3D coordinate system Oxyz    
 * @param Z-axis in the 3D coordinate system Oxyz
 * @return V-axis in the 2D coordinate system Ouv
 */ 
int OxyzToOv(double y,double z){
    return (int)((y + 35) - z*0.35);
}


/*!
 * @brief  Rotate the coordinates of all points of the 3D graphics around the Z-axis
 * @param  angle The angle to be rotated
 *     
 *  Rotate around z (z is fixed)
    x3 = x2 * cosb - y1 * sinb
    y3 = y1 * cosb + x2 * sinb
    z3 = z2
 */
void rotate(double angle)
{
  double rad, cosa, sina, Xn, Yn;
 
  rad = angle * PI / 180;
  cosa = cos(rad);
  sina = sin(rad);
  for (int i = 0; i < 4; i++)
  {
    Xn = (tetrahedron[i][0] * cosa) - (tetrahedron[i][1] * sina);
    Yn = (tetrahedron[i][0] * sina) + (tetrahedron[i][1] * cosa);

    //Store the converted coordinates in the coordinate array
    //Since it is rotated around the z-axis, the coordinates of z-axis won't change
    tetrahedron[i][0] = Xn;
    tetrahedron[i][1] = Yn;
  }
}
