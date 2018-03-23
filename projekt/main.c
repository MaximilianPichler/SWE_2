#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define TRIG 4
#define ECHO 17

int main () {
    wiringPiSetup();

    digitalWrite(TRIG, OUTPUT);
    digitalWrite(ECHO, INPUT);

    digitalWrite(TRIG, LOW);

 

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

    return 0;
}