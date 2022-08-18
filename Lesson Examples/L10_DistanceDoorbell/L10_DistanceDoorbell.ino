#include "Ultrasonic.h"

#define NOTE_C 523
#define NOTE_F 349

#define RANGE_PIN 2
#define BUZZ_PIN 5

int DELAY = 1000;
int rangeMin = 100;
int inRange = false;

Ultrasonic ultrasonic(RANGE_PIN);

void setup()
{
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop()
{
  long rangeCm = ultrasonic.MeasureInCentimeters();
  if (rangeCm < rangeMin) {
    if (!inRange) {
      ringDoorbell(); // only ring doorbell first time
    }
    inRange = true;
  } else {
    inRange = false;
  }
  delay(DELAY);
}

void ringDoorbell() {
  tone(BUZZ_PIN, NOTE_C, 500);
  delay(500);
  tone(BUZZ_PIN, NOTE_F, 700);
  delay(700);
}
