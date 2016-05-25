#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <Wire.h>
#include "Sodaq_DS3231.h"
//complement by avk013 Kovalenko Olexander
int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
//int numberOfHorizontalDisplays = 2;
int numberOfHorizontalDisplays = 2;
int numberOfVerticalDisplays = 8;
int f=1,d=9,shag=0;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "0123456789";
int wait = 250; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels

void setup() {
  matrix.shutdown(true);
     delay(300);
  matrix.shutdown(false); 
 Serial.begin(9600);      // открываем последовательное соединение
Wire.begin();
rtc.begin();
  matrix.setIntensity(0); // Use a value between 0 and 15 for brightness

matrix.setPosition(0, 1, 0);
matrix.setPosition(8, 0, 0);
matrix.setPosition(1, 3, 0);
matrix.setPosition(9, 2, 0);
matrix.setPosition(2, 5, 0);
matrix.setPosition(10, 4, 0);
matrix.setPosition(3, 7, 0);
matrix.setPosition(11, 6, 0);
matrix.setPosition(4, 9, 0);
matrix.setPosition(12, 8, 0);
matrix.setPosition(5, 11, 0);
matrix.setPosition(13, 10, 0);
matrix.setPosition(6, 13, 0);
matrix.setPosition(14, 12, 0);
matrix.setPosition(7, 15, 0);
matrix.setPosition(15, 14, 0);
//matrix.setPosition(14, 0, 8);
//matrix.setPosition(14, 8, 1);

matrix.setRotation(7, 2);
matrix.setRotation(6, 2);
matrix.setRotation(5, 2);
matrix.setRotation(4, 2);
matrix.setRotation(3, 2);
matrix.setRotation(2, 2);
matrix.setRotation(1, 2);
matrix.setRotation(0, 2);

matrix.setRotation(1);
}

void loop() {
  matrix.shutdown(true);
  delay(14);
  matrix.shutdown(false);
  delay(14);
  matrix.setIntensity(0); // Use a value between 0 and 15 for brightness
  matrix.fillScreen(LOW);
  delay(wait);
   matrix.setIntensity(0);
   DateTime now = rtc.now(); //get the current date-time
    uint32_t ts = now.getEpoch();
//int i=5;
 /*for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ )
  //  for ( int i = 0 ; i < 64; i++ )
{

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
    if ( letter < tape.length() ) 
      {
        matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
   }

    matrix.write(); // Send bitmap to display

  }
  */
if (shag==d) f=-1;
if (shag==0) f=1;
shag+=f;
  
  String s,m;
   if (String(now.second(),DEC).length()==1) s="0"+String(now.second(),DEC); else s=String(now.second(),DEC);
   if (String(now.minute(),DEC).length()==1) m="0"+String(now.minute(),DEC); else m=String(now.minute(),DEC);
  int ss=11,so=0,siz=2; 
  String sec=String(now.hour(),DEC)+m+s;
 for(int i=0;i<=sec.length();i++)
   {if(i>sec.length()-3) {siz=1;ss=7;}
    matrix.drawChar(so+shag, 0, sec[i] , HIGH, LOW, siz);
   so+=ss;
    //matrix.drawChar(13*i+shag, 0, sec[i] , HIGH, LOW, 2);
   }
     matrix.write(); // Send bitmap to display
     delay(wait);
     matrix.fillScreen(LOW);
     delay(wait);
  /*       Serial.println('/');
Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.date(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
    delay(wait);
    */
}
