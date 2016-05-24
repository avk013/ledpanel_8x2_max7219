#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
//complement by avk013 Kovalenko Olexander
int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 2;
int numberOfVerticalDisplays = 8;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "0123456789";
int wait = 70; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels

void setup() {

  matrix.setIntensity(0); // Use a value between 0 and 15 for brightness
  /*matrix.setPosition(0, 7, 1);
  matrix.setPosition(1, 6, 1);
  matrix.setPosition(2, 5, 1);
  matrix.setPosition(3, 4, 1);
  matrix.setPosition(4, 3, 1);
  matrix.setPosition(5, 2, 1);
matrix.setPosition(6, 1, 1);
matrix.setPosition(7, 0, 1);
matrix.setPosition(8, 7, 0);
matrix.setPosition(9, 6, 0);
matrix.setPosition(10, 5, 0);
matrix.setPosition(11, 4, 0);
*/
//matrix.setPosition(6, 7, 1);
//matrix.setPosition(14, 7, 0);
//matrix.setPosition(7, 6, 1);
//matrix.setPosition(15, 6, 0);
//matrix.setPosition(0, 0, 0);
//matrix.setPosition(13, 5, 0);
//matrix.setPosition(4, 4, 1);
//matrix.setPosition(12, 4, 0);
//matrix.setPosition(3, 3, 1);
//matrix.setPosition(11, 3, 0);
//matrix.setPosition(2, 2, 1);
//matrix.setPosition(10, 2, 0);
//matrix.setPosition(1, 1, 1);
//matrix.setPosition(1, 1, 0);
//matrix.setPosition(0, 8, 1);
//matrix.setPosition(1, 0, 0);
//matrix.setPosition(0, 7, 0);
//matrix.setPosition(8, 7, 1);





//matrix.setRotation(0,1);
//matrix.setRotation(6,1);
//matrix.setRotation(5,1);
//matrix.setRotation(14,3);
//matrix.setRotation(15,3);
//matrix.setRotation(13,3);







//matrix.setRotation(13,3);
//matrix.setPosition(2, 5, 0);
//matrix.setPosition(3, 4, 0);
//matrix.setPosition(4, 3, 0);
//matrix.setPosition(5, 2, 0);
//matrix.setPosition(6, 1, 0);
//matrix.setPosition(7, 0, 0);
/*
matrix.setPosition(0, 7, 0);
matrix.setPosition(1, 6, 0);
matrix.setPosition(2, 5, 0);
matrix.setPosition(3, 4, 0);
matrix.setPosition(4, 3, 0);
matrix.setPosition(5, 2, 0);
matrix.setPosition(6, 1, 0);
matrix.setPosition(7, 0, 0);
matrix.setPosition(8, 7, 1);
matrix.setPosition(9, 6, 1);
matrix.setPosition(10, 5, 1);
matrix.setPosition(11, 4, 1);
matrix.setPosition(12, 3, 1);
matrix.setPosition(13, 2, 1);
matrix.setPosition(14, 1, 1);
matrix.setPosition(15, 0, 1);
//matrix.setPosition(8, 0, 0);

*/
// Adjust to your own needs
//  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
//matrix.setPosition(0, 0, 0);
//matrix.setPosition(1, 0, 1);
//matrix.setPosition(2, 1, 0);
//matrix.setPosition(1, 0, 1);
//int nd=0;
//for (int i=0;i<2;i++)
//{for (int ii=0;ii<8;ii++)
//matrix.setPosition(nd++, ii, i);
//}




//  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
//  matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
//  matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>
//  ...
//  matrix.setRotation(0, 2);    // The first display is position upside down
//  matrix.setRotation(3, 2);    // The same hold for the last display




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
matrix.setRotation(1);
matrix.setRotation(7, 2);
matrix.setRotation(6, 2);
matrix.setRotation(5, 2);
matrix.setRotation(4, 2);
matrix.setRotation(3, 2);
matrix.setRotation(2, 2);
matrix.setRotation(1, 2);
matrix.setRotation(0, 2);

}

void loop() {
//int i=5;
 for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ )
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

    delay(wait);
  }
 /* matrix.fillScreen(LOW);
  for(int i=0;i<=7;i++)
   {matrix.drawChar(i*8, 4, tape[i], HIGH, LOW, 1);
   }
     matrix.write(); // Send bitmap to display
     delay(wait);
     matrix.fillScreen(LOW);
     delay(wait);*/
}
