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
 for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ )
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
}
