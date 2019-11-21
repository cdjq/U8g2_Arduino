#include "DFRobot_CCS811.h"
#include <DFRobotHCHOSensor.h>
#include <SoftwareSerial.h>
#include <DFRobot_LM75B.h>
#include <U8x8lib.h>
#include <Wire.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); 

DFRobot_LM75B lm75b(&Wire, 0x4F); //0x4F
DFRobot_CCS811 sensor;    ///0x5A
#define SensorSerialPin  10  //this pin read the uart signal from the HCHO sensor
SoftwareSerial sensorSerial(SensorSerialPin,SensorSerialPin);
DFRobotHCHOSensor hchoSensor(&sensorSerial);

  int reTVOC=0,reCO2=0,temp=0;
  float reHCHO ;

//DFRobot_NeoPixel  rgb_display_2;


void setup(void)
{
  
  sensor.begin();       
  sensor.setMeasCycle(sensor.eCycle_1s);
  lm75b.begin(); 
  sensorSerial.begin(9600);  //the baudrate of HCHO is 9600
  sensorSerial.listen();
  Serial.begin(9600);
   
  u8x8.begin();
  u8x8.setPowerSave(0); //禁用省电模式                      
  u8x8.setFont(u8x8_font_px437wyse700a_2x2_r);//设置字体大小
  u8x8.drawString(1,1,"Welcome");       //显示内容 
  uint32_t timeStamp=millis();
  while((millis()-timeStamp)<2000){   
  reTVOC = sensor.getTVOCPPB();
  reCO2 = sensor.getCO2PPM();
  temp = lm75b.getTempC();
  while(hchoSensor.available() == 0)  
    {
    delay(1);
    }
    reHCHO = hchoSensor.uartReadPPM();
  
} 
 u8x8.clear();
}


void loop()
{

  while(hchoSensor.available() == 0)  
    {
    delay(1);
    }
    reHCHO = hchoSensor.uartReadPPM();
    Serial.println(reHCHO);
  reTVOC = sensor.getTVOCPPB();
  reCO2 = sensor.getCO2PPM();
  temp = lm75b.getTempC();
  if(reTVOC > 350)
  {
     digitalWrite(11,HIGH);
      
  }
  else
  {
    digitalWrite(11,LOW);
  }
  if(reCO2 > 1200)
  {   
     digitalWrite(11,HIGH);
  }
  else
  {
    digitalWrite(11,LOW);
  }
  u8x8.setFont(u8x8_font_px437wyse700a_2x2_r);//设置字体大小
  u8x8.drawString(0,0,"TVOC:");       //显示内容  
  u8x8.drawString(2,2,String(reTVOC).c_str());  
  u8x8.drawString(10,2,"ppm"); 
//  //u8x8.refreshDisplay();    // only required for SSD1606/7  
  delay(3000); 
  u8x8.clear(); 
  u8x8.drawString(0,0,"CO2:");       //显示内容  
  u8x8.drawString(2,2,String(reCO2).c_str());  
  u8x8.drawString(10,2,"ppb"); 
//  //u8x8.refreshDisplay();    // only required for SSD1606/7  
  delay(3000); 
  u8x8.clear(); 
  u8x8.drawString(0,0,"Temp:");       //显示内容  
  u8x8.drawString(2,2,String(temp).c_str());
 // u8g2.drawCircle(9, 2, 2 , U8G2_DRAW_ALL); 
  u8x8.drawString(10,2,"C"); 
// // u8x8.refreshDisplay();    // only required for SSnD1606/7  
  delay(3000); 
  u8x8.clear(); 
  u8x8.drawString(0,0,"HCHO:");       //显示内容  
  u8x8.drawString(2,2,String(reHCHO).c_str()); 
  u8x8.drawString(10,2,"ppm"); 
  //u8x8.refreshDisplay();    // only required for SSD1606/7  
  delay(3000);
  u8x8.clear(); 
}