#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include "pitches.h"

LCDWIKI_SPI mylcd(ST7735S,A5,A3,-1,A2,A4,A1,A3);//software spi,model,cs,cd,miso,mosi,reset,clk,led

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ROYAL_BLUE   0x3386FF

#define echoPin 2
#define trigPin 3

int feeling = 0; // 0 - sleep, 1 - open eyes, 2 - suspisious, 3 - annoyed, 4 - extra_annoyed, 5 - happy, 6 - extra_happy
int sensor = 4;
int state = LOW;
int val = 0;
long lastTimer = 100000;
long timer = 100000;
long lastMotionTimer = 100000;

int extra_happy_tone[] = {
 NOTE_A6, NOTE_B6, NOTE_CS7
};

int extra_happy_noteDurations[] = 
{ 
 4, 4, 4
};

int happy_tone[] = {
 NOTE_A6, NOTE_B6
};

int happy_noteDurations[] = 
{ 
 4, 4
};

int suspicious_tone[] = {
 NOTE_A1
};
int suspicious_noteDurations[] = 
{ 
 16
};

int annoyed_tone[] = {
 NOTE_D1
};

int annoyed_noteDurations[] = 
{ 
 2
};

int extra_annoyed_tone[] = {
 NOTE_D1
};

int extra_annoyed_noteDurations[] = 
{ 
 1
};
  
void sleep(void)
{
   mylcd.Set_Draw_color(BLACK);
   
   for (int i = 25; i >= 4; i--)
   {
     mylcd.Draw_Fast_HLine(88, 64+i, 51);
     mylcd.Draw_Fast_HLine(88, 64-i, 51);
     mylcd.Draw_Fast_HLine(22, 64+i, 51);
     mylcd.Draw_Fast_HLine(22, 64-i, 51);
   }
}

void blink(void)
{
   sleep();
   open_eyes();
}

void suspicious(void)
{
   blink();
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

   int melodySize = sizeof(suspicious_tone) / sizeof(4);
   for (int thisNote = 0; thisNote < melodySize; thisNote++) {
      int noteDuration = 1000/suspicious_noteDurations[thisNote];
      tone(8, suspicious_tone[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.3;
      delay(pauseBetweenNotes);
      noTone(8);
  }
}

void extra_annoyed(void)
{
   blink();
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

   int melodySize = sizeof(extra_annoyed_tone) / sizeof(4);
   for (int thisNote = 0; thisNote < melodySize; thisNote++) {
      int noteDuration = 1000/extra_annoyed_noteDurations[thisNote];
      tone(8, extra_annoyed_tone[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
  }

   int n = 10;
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
   blink();
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

   int melodySize = sizeof(annoyed_tone) / sizeof(4);
   for (int thisNote = 0; thisNote < melodySize; thisNote++) {
      int noteDuration = 1000/annoyed_noteDurations[thisNote];
      tone(8, annoyed_tone[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
  }
}

void open_eyes(void)
{
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

void happy()
{
   sleep();

   mylcd.Set_Draw_color(ROYAL_BLUE);

   mylcd.Draw_Fast_HLine(88, 68, 51);
   mylcd.Draw_Fast_HLine(22, 68, 51);

   mylcd.Draw_Fast_HLine(22, 60, 51);
   mylcd.Draw_Fast_HLine(88, 60, 51);
   
   mylcd.Draw_Fast_HLine(89, 69, 49);
   mylcd.Draw_Fast_HLine(23, 69, 49);

   mylcd.Draw_Fast_HLine(22, 59, 51);
   mylcd.Draw_Fast_HLine(88, 59, 51);
   
   mylcd.Draw_Fast_HLine(89, 70, 49);
   mylcd.Draw_Fast_HLine(23, 70, 49);

   mylcd.Draw_Fast_HLine(22, 58, 51);
   mylcd.Draw_Fast_HLine(88, 58, 51);
   
   mylcd.Draw_Fast_HLine(89, 71, 49);
   mylcd.Draw_Fast_HLine(23, 71, 49);

   mylcd.Draw_Fast_HLine(22, 57, 51);
   mylcd.Draw_Fast_HLine(88, 57, 51);
   
   mylcd.Draw_Fast_HLine(89, 72, 49);
   mylcd.Draw_Fast_HLine(23, 72, 49);

   mylcd.Draw_Fast_HLine(22, 56, 51);
   mylcd.Draw_Fast_HLine(88, 56, 51);
   
   mylcd.Draw_Fast_HLine(90, 73, 47);
   mylcd.Draw_Fast_HLine(24, 73, 47);

   mylcd.Draw_Fast_HLine(22, 55, 51);
   mylcd.Draw_Fast_HLine(88, 55, 51);
   
   mylcd.Draw_Fast_HLine(90, 74, 47);
   mylcd.Draw_Fast_HLine(24, 74, 47);

   mylcd.Draw_Fast_HLine(22, 54, 51);
   mylcd.Draw_Fast_HLine(88, 54, 51);
   
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);

   mylcd.Draw_Fast_HLine(22, 53, 51);
   mylcd.Draw_Fast_HLine(88, 53, 51);
   
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);

   mylcd.Draw_Fast_HLine(88, 52, 51);
   mylcd.Draw_Fast_HLine(22, 52, 51);
   
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);

   mylcd.Draw_Fast_HLine(22, 51, 51);
   mylcd.Draw_Fast_HLine(88, 51, 51);
   
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   mylcd.Draw_Fast_HLine(95, 81, 37);
   mylcd.Draw_Fast_HLine(29, 81, 37);
   mylcd.Draw_Fast_HLine(96, 82, 35);
   mylcd.Draw_Fast_HLine(30, 82, 35);
   mylcd.Draw_Fast_HLine(97, 83, 33);
   mylcd.Draw_Fast_HLine(31, 83, 33);
   mylcd.Draw_Fast_HLine(98, 84, 31);
   mylcd.Draw_Fast_HLine(32, 84, 31);
   mylcd.Draw_Fast_HLine(99, 85, 29);
   mylcd.Draw_Fast_HLine(33, 85, 29);
   mylcd.Draw_Fast_HLine(101, 86, 25);
   mylcd.Draw_Fast_HLine(35, 86, 25);
   mylcd.Draw_Fast_HLine(103, 87, 21);
   mylcd.Draw_Fast_HLine(37, 87, 21);
   mylcd.Draw_Fast_HLine(105, 88, 17);
   mylcd.Draw_Fast_HLine(39, 88, 17);
   mylcd.Draw_Fast_HLine(109, 89, 9);
   mylcd.Draw_Fast_HLine(43, 89, 9);

   int melodySize = sizeof(happy_tone) / sizeof(4);
   for (int thisNote = 0; thisNote < melodySize; thisNote++) {
      int noteDuration = 1000/happy_noteDurations[thisNote];
      tone(8, happy_tone[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.3/2;
      delay(pauseBetweenNotes);
      noTone(8);
   }
}

void extra_happy()
{
   sleep();

   mylcd.Set_Draw_color(ROYAL_BLUE);

   mylcd.Draw_Fast_HLine(88, 68, 51);
   mylcd.Draw_Fast_HLine(22, 68, 51);
   
   mylcd.Draw_Fast_HLine(89, 69, 49);
   mylcd.Draw_Fast_HLine(23, 69, 49);
   
   mylcd.Draw_Fast_HLine(89, 70, 49);
   mylcd.Draw_Fast_HLine(23, 70, 49);
   
   mylcd.Draw_Fast_HLine(89, 71, 49);
   mylcd.Draw_Fast_HLine(23, 71, 49);
   
   mylcd.Draw_Fast_HLine(89, 72, 49);
   mylcd.Draw_Fast_HLine(23, 72, 49);
   
   mylcd.Draw_Fast_HLine(90, 73, 47);
   mylcd.Draw_Fast_HLine(24, 73, 47);
   
   mylcd.Draw_Fast_HLine(90, 74, 47);
   mylcd.Draw_Fast_HLine(24, 74, 47);
   
   mylcd.Draw_Fast_HLine(91, 75, 45);
   mylcd.Draw_Fast_HLine(25, 75, 45);
   
   mylcd.Draw_Fast_HLine(91, 76, 45);
   mylcd.Draw_Fast_HLine(25, 76, 45);
   
   mylcd.Draw_Fast_HLine(92, 77, 43);
   mylcd.Draw_Fast_HLine(26, 77, 43);
   
   mylcd.Draw_Fast_HLine(92, 78, 43);
   mylcd.Draw_Fast_HLine(26, 78, 43);
   mylcd.Draw_Fast_HLine(93, 79, 41);
   mylcd.Draw_Fast_HLine(27, 79, 41);
   mylcd.Draw_Fast_HLine(94, 80, 39);
   mylcd.Draw_Fast_HLine(28, 80, 39);
   
   mylcd.Draw_Fast_HLine(96, 81, 35);
   mylcd.Draw_Fast_HLine(30, 81, 35);
   
   mylcd.Draw_Fast_HLine(98, 82, 31);
   mylcd.Draw_Fast_HLine(32, 82, 31);
   
   mylcd.Draw_Fast_HLine(100, 83, 27);
   mylcd.Draw_Fast_HLine(34, 83, 27);
   
   mylcd.Draw_Fast_HLine(102, 84, 23);
   mylcd.Draw_Fast_HLine(36, 84, 23);
   
   mylcd.Draw_Fast_HLine(104, 85, 19);
   mylcd.Draw_Fast_HLine(38, 85, 19);
   
   mylcd.Draw_Fast_HLine(107, 86, 13);
   mylcd.Draw_Fast_HLine(41, 86, 13);

   mylcd.Draw_Fast_HLine(88, 60, 24);
   mylcd.Draw_Fast_HLine(22, 60, 24);
   mylcd.Draw_Fast_HLine(116, 60, 23);
   mylcd.Draw_Fast_HLine(50, 60, 23);

   mylcd.Draw_Fast_HLine(88, 59, 20);
   mylcd.Draw_Fast_HLine(22, 59, 20);
   mylcd.Draw_Fast_HLine(119, 59, 20);
   mylcd.Draw_Fast_HLine(53, 59, 20);

   mylcd.Draw_Fast_HLine(89, 58, 15);
   mylcd.Draw_Fast_HLine(23, 58, 15);
   mylcd.Draw_Fast_HLine(123, 58, 15);
   mylcd.Draw_Fast_HLine(57, 58, 15);

   mylcd.Draw_Fast_HLine(90, 57, 12);
   mylcd.Draw_Fast_HLine(24, 57, 12);
   mylcd.Draw_Fast_HLine(125, 57, 12);
   mylcd.Draw_Fast_HLine(59, 57, 12);

   mylcd.Draw_Fast_HLine(91, 56, 10);
   mylcd.Draw_Fast_HLine(25, 56, 10);
   mylcd.Draw_Fast_HLine(126, 56, 10);
   mylcd.Draw_Fast_HLine(60, 56, 10);

   int melodySize = sizeof(extra_happy_tone) / sizeof(4);
   for (int thisNote = 0; thisNote < melodySize; thisNote++) {
      int noteDuration = 1000/extra_happy_noteDurations[thisNote];
      tone(8, extra_happy_tone[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.3/2;
      delay(pauseBetweenNotes);
      noTone(8);
   }
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
  sleep();
  pinMode(sensor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

int compute_distance()
{
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void loop() 
{
  val = digitalRead(sensor);
  int curr_dist = compute_distance();
  Serial.println(curr_dist);
  if (val == HIGH) {
    delay(2000);
    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;
      open_eyes();
      feeling = 1;
    }
    if (curr_dist > 50 && curr_dist < 500)
    {
      if (feeling == 1)
      {
        long rand_blink = random(1, 3);
        if (rand_blink == 2)
        {
          blink();
        }
      } 
      if (lastMotionTimer == 100000)
      {
        lastMotionTimer = 100000;
        lastTimer = 100000;
        lastMotionTimer = millis()/1000;
      }
    }
    else if (curr_dist > 20 && curr_dist < 500)
    {
      if (lastTimer == 100000)
      {
        lastMotionTimer = 100000;
        lastTimer = 100000;
        lastTimer = millis()/1000;
      }
    }
    else if (curr_dist <= 20 && curr_dist < 500 && feeling != 5)
    {
      lastMotionTimer = 100000;
      lastTimer = 100000;
      Serial.println("Happy");
      happy();
      feeling = 5;
    }
    else if((curr_dist <= 5 || curr_dist > 500) && feeling != 6)
    {
      Serial.println("Extra Happy");
      lastMotionTimer = 100000;
      lastTimer = 100000;
      extra_happy();
      feeling = 6;
    }
  }
  else {
      delay(2000);
      sleep();
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;
    }
  }
  timer = millis()/1000;
  if (timer - lastMotionTimer > 15 && feeling != 2)
  {
    Serial.println("Suspicious");
    lastMotionTimer = 100000;
    lastTimer = 100000;
    suspicious();
    feeling = 2;
  }
  if (timer - lastTimer > 15 && feeling != 3)
  {
    Serial.println("Annoyed");
    lastMotionTimer = 100000;
    //lastTimer = 100000;
    annoyed();
    feeling = 3;
  }
  else if (timer - lastTimer > 30  && feeling != 4)
  {
    Serial.println("Extra Annoyed");
    lastMotionTimer = 100000;
    lastTimer = 100000;
    extra_annoyed();
    feeling = 4;
  }
}
