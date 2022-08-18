#include "Ultrasonic.h"
#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define LED_COUNT  10
#define BRIGHTNESS 50
#define RANGE_PIN 2

Ultrasonic ultrasonic(RANGE_PIN);
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int cautionDistance = 72;  // 6 feet
int stopDistance = 36;     // 3 feet
uint32_t cautionColor = pixels.Color(255, 255, 0);
uint32_t stopColor = pixels.Color(255, 0, 0);

void setup()
{
  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
    Serial.begin(9600);

}
void loop()
{
  long rangeInch = ultrasonic.MeasureInInches();
  Serial.println(rangeInch);
  if (rangeInch <= stopDistance) {
    showLight(stopColor);
  } else if (rangeInch <= cautionDistance) {
    showLight(cautionColor);
  } else {
    showLight(0);
  }
  delay(200);
}

void showLight(uint32_t color) {
  pixels.fill(color);
  pixels.show();
}
