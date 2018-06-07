#include "lcd.h"

int main()   {
  if (wiringPiSetup () == -1) exit (1);

  fd = wiringPiI2CSetup(I2C_ADDR);
  lcd_init();

  int xPos = 0;
  int yPos = 0;
  int count = 0;
  while(1) {
    //ClrLcd();

    switch(yPos) {
      case 0: lcdLoc(LINE1); break;
      case 1: lcdLoc(LINE2); break;
      case 2: lcdLoc(LINE3); break;
      case 3: lcdLoc(LINE4); break;
    }
    
    char myString[20];

    for (int i = 0; i < 20; i++) {
      if (i >= 20 - count) {
        myString[i] = '#';
      }
      else if (i == xPos) {
        myString[i] = '#';
      } else {
        myString[i] = ' ';
      }
    }

    
      lcdLoc(LINE1);
      typeln(myString);

      lcdLoc(LINE2);
      typeln(myString);

      lcdLoc(LINE3); 
      typeln(myString);

      lcdLoc(LINE4); 

    typeln(myString);
    delay(100);

    xPos++;

    if(xPos >= 20 - count) {
      count ++;
      xPos = 0;

    if (count >= 19) {
      count = 0;
    }
      
    }
  }

  return 0;

}
