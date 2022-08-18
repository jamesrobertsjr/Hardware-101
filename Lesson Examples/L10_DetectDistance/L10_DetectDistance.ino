#include "Ultrasonic.h"

#define RANGE_PIN 2

int DELAY = 1000;

Ultrasonic ultrasonic(RANGE_PIN);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("The distance to obstacle is: ");
    long rangeInch = ultrasonic.MeasureInInches();
    Serial.print(rangeInch);
    Serial.println(" inch");
    delay(DELAY);
 
    long rangeCm = ultrasonic.MeasureInCentimeters();
    Serial.print(rangeCm);
    Serial.println(" cm");
    delay(DELAY);
}
