#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define LED_COUNT  10
#define BRIGHTNESS 50 // (max = 255)

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  // Cycle Red
  cycleStrip(pixels.Color(255, 0, 0));

  // Cycle Green
  cycleStrip(pixels.Color(0, 255, 0));

  // Cycle Blue
  cycleStrip(pixels.Color(0, 0, 255));
}

void cycleStrip(uint32_t color) {
  // turn the pixels on one by one
  for (int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(100);
  }

  // turn the pixels off in reverse
  for (int i = pixels.numPixels() - 1; i >= 0; i--) {
    pixels.setPixelColor(i, 0);
    pixels.show();
    delay(100);
  }
}
