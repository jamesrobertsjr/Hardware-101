#include <Adafruit_NeoPixel.h>

#define ROTARY_PIN A0
#define LED_PIN   6
#define LED_COUNT  10
#define BRIGHTNESS 50

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int rotaryValue = 0;
int mappedValue = 0;

void setup() {
  pinMode(ROTARY_PIN, INPUT);
  
  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  rotaryValue = 1024 - analogRead(ROTARY_PIN);
  mappedValue = map(rotaryValue, 0, 1023, 1, LED_COUNT);
  
  lightUp(mappedValue, pixels.Color(255, 0, 127));
}

void lightUp(int numPix, uint32_t color) {
  pixels.fill();  // clear pixels
  
  // fill range of pixels
  for (int i = 0; i < numPix; i++) {
    pixels.setPixelColor(i, color);
  }
  
  pixels.show();  // update LED strip
}
