#include <Adafruit_NeoPixel.h>
#include <U8g2lib.h>

#define ROTARY_PIN A0
#define BTN_PIN   6
#define LED_PIN   2
#define LED_COUNT  10
#define BRIGHTNESS 50

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
U8X8_SSD1306_128X64_NONAME_HW_I2C oled(/* reset=*/ U8X8_PIN_NONE);

int rotaryValue = 0;
int mappedValue = 0;

int red = 255, green = 255, blue = 255;

enum State {
  main_menu,
  red_select,
  green_select,
  blue_select
};

State menuState;

long current = 0;

void setup() {
  pinMode(ROTARY_PIN, INPUT);
  
  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);

  oled.begin();
 // oled.setFlipMode(1); 
  oled.clearDisplay();
  oled.setPowerSave(0); 
  oled.setFont(u8x8_font_7x14B_1x2_f);

  menuState = main_menu;
}

void loop() {

  if (digitalRead(BTN_PIN)) {
    toggleMenu();
  }

  if (menuState == main_menu) {
    displayRGBMenu();
  } else {
    rotaryValue = 1024 - analogRead(ROTARY_PIN);
    mappedValue = map(rotaryValue, 0, 1023, 0, 255);

    lightSelect(mappedValue);
    displayRGBSelect(mappedValue);
  }

  pixels.fill(pixels.Color(red, green, blue));
  pixels.show();
}

void displayRGBMenu() {
  oled.setCursor(0, 0);
  oled.print("Red: ");
  oled.println(red);
  
  oled.setCursor(0, 10);
  oled.print("Green: ");
  oled.print(green);

  oled.setCursor(0, 20);
  oled.print("Blue: ");
  oled.print(blue);
  
  oled.refreshDisplay();
}

void displayRGBSelect(int num) {
  oled.setCursor(0, 0);
  if (menuState == red_select) {
    oled.print("Red: ");
  } else if (menuState == green_select) {
    oled.print("Green: ");
  } else if (menuState == blue_select) {
    oled.print("Blue: ");
  }

  if (num < 100) oled.print("0");
  if (num < 10) oled.print("0");
  oled.print(num);
}

void lightSelect(int value) {
  if (menuState == red_select) {
    red = value;
  } else if (menuState == green_select) {
    green = value;
  } else if (menuState == blue_select) {
    blue = value;
  }
}

void toggleMenu() {
  if (millis() - current < 300) {
    return;
  }

  current = millis();
  
  switch (menuState) {
    case main_menu:
      menuState = red_select;
      break;
    case red_select:
      menuState = green_select;
      break;
    case green_select:
      menuState = blue_select;
      break;
    case blue_select:
      menuState = main_menu;
      break;
  }
  oled.clearDisplay();
}
