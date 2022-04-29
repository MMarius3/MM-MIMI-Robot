// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of how to display picture and 
//how to use rotate function to display string.

//Set the pins to the correct ones for your development shield or breakout board.
//when using the BREAKOUT BOARD only and using these software spi lines to the LCD,
//there is no MISO pin and You can use any free pin to define the pins,for example
//pin usage as follow:
//             CS  CD  RST  MOSI  MISO  CLK  LED 
//Arduino Uno  A5  A3  A4   A2    NONE  A1   A3
//Arduino Mega A5  A3  A4   A2    NONE  A1   A3

//when using the BREAKOUT BOARD only and using these hardware spi lines to the LCD,
//there is no MISO pin 
//the MOSI pin and CLK pin is defined by the system and can't be modified.
//other pins can be defined by youself,for example
//pin usage as follow:
//             CS  CD  RST  MOSI  MISO  CLK  LED 
//Arduino Uno  10  9   8    11    NONE  13   A3
//Arduino Mega 10  9   8    51    NONE  52   A3

//Remember to set the pins to suit your display module!

#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library

//the definiens of software spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI mylcd(ST7735S,A5,A3,-1,A2,A4,A1,A3);//software spi,model,cs,cd,miso,mosi,reset,clk,led
//LCDWIKI_SPI mylcd(SSD1283A,A5,A3,-1,A2,A4,A1,A3);//software spi,model,cs,cd,miso,mosi,reset,clk,led

//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_SPI mylcd(160,128,A5,A3,-1,A2,A4,A1,A3);//software spi,model,cs,cd,miso,mosi,reset,clk
//LCDWIKI_SPI mylcd(130,130,A5,A3,-1,A2,A4,A1,A3);//software spi,model,cs,cd,miso,mosi,reset,clk

//the definiens of hardware spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
//LCDWIKI_SPI mylcd(ST7735S,10,9,8,A3); //hardware spi,cs,cd,reset
//LCDWIKI_SPI mylcd(SSD1283A,10,9,8,A3); //hardware spi,cs,cd,reset

//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_SPI mylcd(160,128,10,9,8,A3); //hardware spi,cs,cd,reset
//LCDWIKI_SPI mylcd(130,130,10,9,8,A3); //hardware spi,cs,cd,reset

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ROYAL_BLUE   0x3386FF

void sleep(void)
{
   mylcd.Set_Draw_color(BLACK);

   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(109, 39, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);
   mylcd.Draw_Fast_HLine(43, 39, 9);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(105, 40, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(39, 40, 17);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(103, 41, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(37, 41, 21);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(101, 42, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(99, 43, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(33, 43, 29);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(98, 44, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(32, 44, 31);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(97, 45, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(31, 45, 33);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(96, 46, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(30, 46, 35);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(95, 47, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(29, 47, 37);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(94, 48, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(28, 48, 39);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(93, 49, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(27, 49, 41);
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(92, 50, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(26, 50, 43);
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(92, 51, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   mylcd.Draw_Fast_HLine(26, 51, 43);
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(91, 52, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   mylcd.Draw_Fast_HLine(25, 52, 45);
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(91, 53, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);
   mylcd.Draw_Fast_HLine(25, 53, 45);
   mylcd.Draw_Fast_HLine(90, 74, 47);
   mylcd.Draw_Fast_HLine(90, 54, 47);
   mylcd.Draw_Fast_HLine(24, 74, 47);
   mylcd.Draw_Fast_HLine(24, 54, 47);
   mylcd.Draw_Fast_HLine(90, 73, 47);
   mylcd.Draw_Fast_HLine(90, 55, 47);
   mylcd.Draw_Fast_HLine(24, 73, 47);
   mylcd.Draw_Fast_HLine(24, 55, 47);
   mylcd.Draw_Fast_HLine(89, 72, 49);
   mylcd.Draw_Fast_HLine(89, 56, 49);
   mylcd.Draw_Fast_HLine(23, 72, 49);
   mylcd.Draw_Fast_HLine(23, 56, 49);
   mylcd.Draw_Fast_HLine(89, 71, 49);
   mylcd.Draw_Fast_HLine(89, 57, 49);
   mylcd.Draw_Fast_HLine(23, 71, 49);
   mylcd.Draw_Fast_HLine(23, 57, 49);
   mylcd.Draw_Fast_HLine(89, 70, 49);
   mylcd.Draw_Fast_HLine(89, 58, 49);
   mylcd.Draw_Fast_HLine(23, 70, 49);
   mylcd.Draw_Fast_HLine(23, 58, 49);
   mylcd.Draw_Fast_HLine(89, 69, 49);
   mylcd.Draw_Fast_HLine(89, 59, 49);
   mylcd.Draw_Fast_HLine(23, 69, 49);
   mylcd.Draw_Fast_HLine(23, 59, 49);
   mylcd.Draw_Fast_HLine(88, 68, 51);
   mylcd.Draw_Fast_HLine(88, 60, 51);
   mylcd.Draw_Fast_HLine(22, 68, 51);
   mylcd.Draw_Fast_HLine(22, 60, 51);
  
}

void blink(void)
{
   mylcd.Set_Draw_color(BLACK);

   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(109, 39, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);
   mylcd.Draw_Fast_HLine(43, 39, 9);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(105, 40, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(39, 40, 17);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(103, 41, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(37, 41, 21);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(101, 42, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(99, 43, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(33, 43, 29);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(98, 44, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(32, 44, 31);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(97, 45, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(31, 45, 33);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(96, 46, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(30, 46, 35);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(95, 47, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(29, 47, 37);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(94, 48, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(28, 48, 39);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(93, 49, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(27, 49, 41);
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(92, 50, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(26, 50, 43);
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(92, 51, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   mylcd.Draw_Fast_HLine(26, 51, 43);
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(91, 52, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   mylcd.Draw_Fast_HLine(25, 52, 45);
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(91, 53, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);
   mylcd.Draw_Fast_HLine(25, 53, 45);
   mylcd.Draw_Fast_HLine(90, 74, 47);
   mylcd.Draw_Fast_HLine(90, 54, 47);
   mylcd.Draw_Fast_HLine(24, 74, 47);
   mylcd.Draw_Fast_HLine(24, 54, 47);
   mylcd.Draw_Fast_HLine(90, 73, 47);
   mylcd.Draw_Fast_HLine(90, 55, 47);
   mylcd.Draw_Fast_HLine(24, 73, 47);
   mylcd.Draw_Fast_HLine(24, 55, 47);
   mylcd.Draw_Fast_HLine(89, 72, 49);
   mylcd.Draw_Fast_HLine(89, 56, 49);
   mylcd.Draw_Fast_HLine(23, 72, 49);
   mylcd.Draw_Fast_HLine(23, 56, 49);
   mylcd.Draw_Fast_HLine(89, 71, 49);
   mylcd.Draw_Fast_HLine(89, 57, 49);
   mylcd.Draw_Fast_HLine(23, 71, 49);
   mylcd.Draw_Fast_HLine(23, 57, 49);
   mylcd.Draw_Fast_HLine(89, 70, 49);
   mylcd.Draw_Fast_HLine(89, 58, 49);
   mylcd.Draw_Fast_HLine(23, 70, 49);
   mylcd.Draw_Fast_HLine(23, 58, 49);
   mylcd.Draw_Fast_HLine(89, 69, 49);
   mylcd.Draw_Fast_HLine(89, 59, 49);
   mylcd.Draw_Fast_HLine(23, 69, 49);
   mylcd.Draw_Fast_HLine(23, 59, 49);
   mylcd.Draw_Fast_HLine(88, 68, 51);
   mylcd.Draw_Fast_HLine(88, 60, 51);
   mylcd.Draw_Fast_HLine(22, 68, 51);
   mylcd.Draw_Fast_HLine(22, 60, 51);

   delay(200);

   mylcd.Set_Draw_color(ROYAL_BLUE);

   mylcd.Draw_Fast_HLine(88, 68, 51);
   mylcd.Draw_Fast_HLine(88, 60, 51);
   mylcd.Draw_Fast_HLine(22, 68, 51);
   mylcd.Draw_Fast_HLine(22, 60, 51);
   mylcd.Draw_Fast_HLine(89, 69, 49);
   mylcd.Draw_Fast_HLine(89, 59, 49);
   mylcd.Draw_Fast_HLine(23, 69, 49);
   mylcd.Draw_Fast_HLine(23, 59, 49);
   mylcd.Draw_Fast_HLine(89, 70, 49);
   mylcd.Draw_Fast_HLine(89, 58, 49);
   mylcd.Draw_Fast_HLine(23, 70, 49);
   mylcd.Draw_Fast_HLine(23, 58, 49);
   mylcd.Draw_Fast_HLine(89, 71, 49);
   mylcd.Draw_Fast_HLine(89, 57, 49);
   mylcd.Draw_Fast_HLine(23, 71, 49);
   mylcd.Draw_Fast_HLine(23, 57, 49);
   mylcd.Draw_Fast_HLine(89, 72, 49);
   mylcd.Draw_Fast_HLine(89, 56, 49);
   mylcd.Draw_Fast_HLine(23, 72, 49);
   mylcd.Draw_Fast_HLine(23, 56, 49);
   mylcd.Draw_Fast_HLine(90, 73, 47);
   mylcd.Draw_Fast_HLine(90, 55, 47);
   mylcd.Draw_Fast_HLine(24, 73, 47);
   mylcd.Draw_Fast_HLine(24, 55, 47);
   mylcd.Draw_Fast_HLine(90, 74, 47);
   mylcd.Draw_Fast_HLine(90, 54, 47);
   mylcd.Draw_Fast_HLine(24, 74, 47);
   mylcd.Draw_Fast_HLine(24, 54, 47);
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(91, 53, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);
   mylcd.Draw_Fast_HLine(25, 53, 45);
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(91, 52, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   mylcd.Draw_Fast_HLine(25, 52, 45);
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(92, 51, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   mylcd.Draw_Fast_HLine(26, 51, 43);
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(92, 50, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(26, 50, 43);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(93, 49, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(27, 49, 41);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(94, 48, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(28, 48, 39);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(95, 47, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(29, 47, 37);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(96, 46, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(30, 46, 35);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(97, 45, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(31, 45, 33);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(98, 44, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(32, 44, 31);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(99, 43, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(33, 43, 29);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(101, 42, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(103, 41, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(37, 41, 21);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(105, 40, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(39, 40, 17);
   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(109, 39, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);
   mylcd.Draw_Fast_HLine(43, 39, 9);
}

void suspicious(void)
{
   mylcd.Set_Draw_color(BLACK);

   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(109, 39, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);
   mylcd.Draw_Fast_HLine(43, 39, 9);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(105, 40, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(39, 40, 17);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(103, 41, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(37, 41, 21);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(101, 42, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(99, 43, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(33, 43, 29);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(98, 44, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(32, 44, 31);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(97, 45, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(31, 45, 33);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(96, 46, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(30, 46, 35);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(95, 47, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(29, 47, 37);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(94, 48, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(28, 48, 39);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(93, 49, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(27, 49, 41);
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(92, 50, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(26, 50, 43);
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(92, 51, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   mylcd.Draw_Fast_HLine(26, 51, 43);
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(91, 52, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   mylcd.Draw_Fast_HLine(25, 52, 45);
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(91, 53, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);
   mylcd.Draw_Fast_HLine(25, 53, 45);
   mylcd.Draw_Fast_HLine(90, 54, 47);
   mylcd.Draw_Fast_HLine(24, 54, 47);
   mylcd.Draw_Fast_HLine(90, 55, 47);
   mylcd.Draw_Fast_HLine(24, 55, 47);
   mylcd.Draw_Fast_HLine(89, 56, 49);
   mylcd.Draw_Fast_HLine(23, 56, 49);
   mylcd.Draw_Fast_HLine(89, 57, 49);
   mylcd.Draw_Fast_HLine(23, 57, 49);
   mylcd.Draw_Fast_HLine(89, 58, 49);
   mylcd.Draw_Fast_HLine(23, 58, 49);
}

void extra_annoyed(void)
{
   mylcd.Set_Draw_color(BLACK);
   
   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(109, 39, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);
   mylcd.Draw_Fast_HLine(43, 39, 9);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(105, 40, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(39, 40, 17);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(103, 41, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(37, 41, 21);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(101, 42, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);

   int n = 100;
   for (int i = 0; i < n; i++)
   {
   mylcd.Set_Draw_color(BLACK);

   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(33, 43, 29);
   mylcd.Draw_Fast_HLine(32, 44, 31);
   mylcd.Draw_Fast_HLine(31, 45, 33);
   mylcd.Draw_Fast_HLine(30, 46, 35);
   mylcd.Draw_Fast_HLine(29, 47, 37);
   mylcd.Draw_Fast_HLine(28, 48, 39);
   mylcd.Draw_Fast_HLine(27, 49, 41);
   mylcd.Draw_Fast_HLine(26, 50, 43);
   mylcd.Draw_Fast_HLine(26, 51, 43);
   mylcd.Draw_Fast_HLine(25, 52, 45);
   
   delay(30);
   
   mylcd.Set_Draw_color(ROYAL_BLUE);
   
   mylcd.Draw_Fast_HLine(25, 52, 45);
   mylcd.Draw_Fast_HLine(26, 51, 43);
   mylcd.Draw_Fast_HLine(26, 50, 43);
   mylcd.Draw_Fast_HLine(27, 49, 41);
   mylcd.Draw_Fast_HLine(28, 48, 39);
   mylcd.Draw_Fast_HLine(29, 47, 37);
   mylcd.Draw_Fast_HLine(30, 46, 35);
   mylcd.Draw_Fast_HLine(31, 45, 33);
   mylcd.Draw_Fast_HLine(32, 44, 31);
   mylcd.Draw_Fast_HLine(33, 43, 29);
   mylcd.Draw_Fast_HLine(35, 42, 25);

   long randDelay;
   randDelay = random(1, 7);

   if(randDelay == 1)
     {
      delay(500);
     }
   else if (randDelay >= 2 && randDelay <= 4)
     {
      delay(1000);
     }
   else
     {
      delay(50);
     }
   }
}

void annoyed(void)
{
  mylcd.Set_Draw_color(BLACK);
   
   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(109, 39, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);
   mylcd.Draw_Fast_HLine(43, 39, 9);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(105, 40, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(39, 40, 17);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(103, 41, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(37, 41, 21);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(101, 42, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(35, 42, 25);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);
}

void test(void)
{
   extra_annoyed();
   delay(1000);
}

void setup() 
{
  mylcd.Init_LCD();
  Serial.begin(9600);
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Rotation(1);
  int r=25,i=0,j=0;
  mylcd.Set_Draw_color(ROYAL_BLUE);
  int w = mylcd.Get_Display_Width();
  int h = mylcd.Get_Display_Height();
  mylcd.Fill_Circle(w/2 - 33, h/2, r);
  mylcd.Fill_Circle(w/2 + 33, h/2, r);
}

void loop() 
{
  test();
}
