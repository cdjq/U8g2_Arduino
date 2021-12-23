# U8g2_Arduino: Arduino Monochrome Graphics Library

![https://raw.githubusercontent.com/wiki/olikraus/u8g2/img/uc1701_dogs102_uno_board_320.jpg](https://raw.githubusercontent.com/wiki/olikraus/u8g2/img/uc1701_dogs102_uno_board_320.jpg) 

U8glib V2 library for Arduino

Description: https://github.com/olikraus/u8g2/wiki

Issue Tracker: https://github.com/olikraus/u8g2/issues

Download (2.26.14): https://github.com/olikraus/U8g2_Arduino/archive/master.zip

## U8g2_Arduino: Monochrome Graphics Library
* This `U8g2_Arduino` monochrome graphics library boasts high performance. It provides general display (point, line, circle, etc.), the icons frequently used, good-looking fonts, etc. Based on the current products, DFRobot has optimized `U8g2_Arduino`:
    1. Added DFRobot_Demo file, offered the Demo with the product characteristic.
    2. Deleted all the materialization function of the Demo


## Function List
`U8g2_Arduino` integrates a plenty of function components, helping offer rich monochrome display effects.

`U8g2_Arduino` API interface function: https://github.com/olikraus/u8g2/wiki/u8g2reference#updatedisplayarea=%E5%BA%93%E6%96%87%E4%BB%B6

`U8g2_Arduino` fonts parameters list: https://github.com/olikraus/u8g2/wiki/fntlistall

## U8g2_Arduino Compatibility
`U8g2_Arduino` supports kinds of MCU, veiw the supported MCU types in the following chart.

MCU          |     Uno      |   Leonardo    |     FireBeetleESP32     |    FireBeetleESP8266    |     m0         |     BK7251      
-----------  | :----------: |  :----------: |  :----------: |  :----------: | :------------: |   ------------
U8g2_Arduino |      √       |       √       |      √        |       √       |       √        |  


## U8g2_Arduino Supported Display
 
`U8g2_Arduino` supports varied display driver IC and resolution. Veiw the current available driver and display in the following chart. You can receive live updates by U8g2_Arduino based on different products.<br>

* SSD1306 0.91" OLED-A<br>
[产品图片]
* SSD1306 0.91" OLED-B<br>
[产品图片]
* SSD1306 0.96" OLED<br>
[产品图片]


## Install U8g2_Arduino Fireware
`U8g2_Arduino` can be easily used by people with different software development level. For a beginner, you can also use it to realize various displays even though you only have a knowledge of basic Arduino. The `U8g2_Arduino` API interface function link can help you learn how to use it.

1. Download Arduino IDE<br>
1. Download `U8g2_Arduino` code from github<br>
1. Use Arduino IDE to open "GraphicsTest.ino" in the downloaded file<br>
1. Connect to your Arduino Uno development board<br>
1. Select tools> board: Arduino Uno and tools> ports: select your Arduino development board<br>
1. Click "Check", and "Upload" the soft to your development board



## FQA

1. Q: Why can't some sample programs be run on Arduino UNO/Leonardo?
    
 * A: Because of the small memory size of Arduino UNO/Leonardo, it can't store the whole program; you can change a master with larger memory, such as Firebettle-ESP32, etc. We have the corresponding instructions in the header file of each ino for your reference.<br>

2. Q: Why can't Korean in Language.ino be displayed properly?

*  A: It's related to Arduino encoding method. Using utf8 encoding in Arduino IDE will not cause such problem. It does not display properly in the sample program but will display normally after uploading the code.
