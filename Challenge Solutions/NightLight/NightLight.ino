#include <Adafruit_NeoPixel.h>

#define LIGHT_PIN A6
#define LED_PIN 6
#define LED_COUNT  10
#define BRIGHTNESS 30

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int lightValue = 0;

void setup() {
  pinMode(LIGHT_PIN, INPUT);

  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  lightValue = analogRead(LIGHT_PIN);
  if (lightValue < 200) {
    pixels.fill(pixels.Color(255, 255, 255));
    pixels.show();
  } else {
    pixels.fill();
    pixels.show();
  }
  delay(100);
}
