#include <Adafruit_NeoPixel.h>

#define SOUND_PIN A2
#define LED_PIN   6
#define LED_COUNT  10
#define BRIGHTNESS 50 // (max = 255)

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);

  pinMode(SOUND_PIN, INPUT);
}

void loop() {
  int soundValue = analogRead(SOUND_PIN);
  int pixelMap = map(soundValue, 0, 1023, 1, LED_COUNT);
  
  displayRange(pixelMap, pixels.Color(255, 0, 0));
}

void displayRange(int numPix, uint32_t color) {
  pixels.fill();  // clear pixels
  
  // fill range of pixels
  for (int i = 0; i < numPix; i++) {
    pixels.setPixelColor(i, color);
  }
  
  pixels.show();  // update LED strip
}
