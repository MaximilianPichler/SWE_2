#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "lcd.h"

#define TRIG 0
#define ECHO 2

int main () {
    if (wiringPiSetup () == -1) exit (1);

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    digitalWrite(TRIG, LOW);

    fd = wiringPiI2CSetup(I2C_ADDR);
    lcd_init();



    lcdLoc(LINE4); 
    typeln(" Maximilian Pichler ");

    int index = 0;

    while (1) {
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(20);
    digitalWrite(TRIG, LOW);

    //Wait for echo start
    while(digitalRead(ECHO) == LOW);
 
    //Wait for echo end
    long startTime = micros();
    while(digitalRead(ECHO) == HIGH);
    long travelTime = micros() - startTime;
 
    //Get distance in cm
    int distance = travelTime / 58;

    printf("Distanz: %i\n", distance);

    char line1Txt[20];
    snprintf(line1Txt, sizeof(line1Txt), "Entfernung: %i     ", distance);

    char buffer[255];
    snprintf(buffer, sizeof(buffer), "curl -X POST -d '{\"value\": \"%i\", \"time\": \"%i\"}' 'https://swe2-projekt.firebaseio.com/data.json'", distance, index);
    system(buffer);
    index++;

    lcdLoc(LINE1); 
    typeln(line1Txt);

    //delay(200);
    }

    return 0;
}