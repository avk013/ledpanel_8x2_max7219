#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <Wire.h>
#include "Sodaq_DS3231.h"
//complement by avk013 Kovalenko Olexander
int pinCS = 10;
int numberOfHorizontalDisplays = 2;
int numberOfVerticalDisplays = 8;
int f=1,d=10,shag=0, yshag=1,yy=0,flagi=0,myx=2,myy=1;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
int wait = 100; // In milliseconds
int spacer = 1, intens_max=2,intens_min=0,intens_now=2;
int width = 5 + spacer; // The font width is 5 pixels
void setup() {
matrix.shutdown(true);
delay(600);
matrix.shutdown(false); 
Wire.begin();
rtc.begin();
matrix.setIntensity(intens_min); // Use a value between 0 and 15 for brightness
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

  matrix.fillScreen(LOW);
  //delay(wait);
   DateTime now = rtc.now(); //get the current date-time
    uint32_t ts = now.getEpoch();
  
//if (shag==d) f=-1;
//if (shag==0) f=1;
//shag+=f;
  
  String s,m,h;
   if (String(now.second(),DEC).length()==1) s="0"+String(now.second(),DEC); else s=String(now.second(),DEC);
   if (String(now.minute(),DEC).length()==1) m="0"+String(now.minute(),DEC); else m=String(now.minute(),DEC);
   if (String(now.hour(),DEC).length()==1) h="0"+String(now.hour(),DEC); else h=String(now.hour(),DEC);
   if ((h.toInt()>18)&&(h.toInt()<8))
   {intens_now=intens_min; 
   myx=0;
   myy=0;
   }
   else  
   {intens_now=intens_max;
   myx=2;
   myy=1;
   }
   if (String(now.second(),DEC)=13)
{ matrix.shutdown(true);
  delay(1);
 matrix.shutdown(false);
  //delay(14);
  matrix.setIntensity(intens_now);}
  int ss=12,so=0,siz=2; 
  String sec=h+m+s;

for(int i=0;i<=sec.length();i++)
   {
    
    
     if(i>sec.length()-3) {siz=1;ss=5;}
   if (flagi==1) {if (i==2) {
     so+=2;
     matrix.drawPixel(so, 4,1);
     matrix.drawPixel(so+1, 4,1);
     matrix.drawPixel(so, 5,1);
     matrix.drawPixel(so+1, 5,1);
     matrix.drawPixel(so, 11,1);
     matrix.drawPixel(so+1, 11,1);
     matrix.drawPixel(so, 10,1);
     matrix.drawPixel(so+1, 10,1);
     so+=2;
   }}
   if ((flagi!=1)&&(i==2)) so+=4;
    matrix.drawChar(so+shag+myx, yy+myy, sec[i] , HIGH, LOW, siz);
   so+=ss;
  // yy+=yshag;
   //if(yy==2)yshag=-1; else if(yy==0)yshag=1;
    //matrix.drawChar(13*i+shag, 0, sec[i] , HIGH, LOW, 2);
   }
     matrix.write(); // Send bitmap to display
  delay(wait);
if(flagi==1) flagi=0; else flagi=1;
}
