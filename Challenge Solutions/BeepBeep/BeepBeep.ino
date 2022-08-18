#include <U8g2lib.h>

#define ROTARY_PIN A0
#define BUZZ_PIN 5
#define BTN_PIN 6

U8X8_SSD1306_128X64_NONAME_HW_I2C oled(/* reset=*/ U8X8_PIN_NONE);

int rotaryValue = 0;
int mappedValue = 0;

void setup() {
  pinMode(ROTARY_PIN, INPUT);
  pinMode(BTN_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);

  oled.begin();
  //oled.setFlipMode(1); 
  oled.clearDisplay();
  oled.setFont(u8x8_font_7x14B_1x2_f);
}

void loop() {
  rotaryValue = analogRead(ROTARY_PIN);
  mappedValue = map(rotaryValue, 0, 1023, 1, 5);

  oled.setCursor(0, 0);
  oled.print("Beeps: ");
  oled.print(mappedValue);

  if (digitalRead(BTN_PIN)) {
    beep(mappedValue);
  }
}

void beep(int num) {
  for (int i = 0; i < num; i++) {
    analogWrite(BUZZ_PIN, 128);
    delay(150);
    analogWrite(BUZZ_PIN, 0);
    delay(150);
  }
}
