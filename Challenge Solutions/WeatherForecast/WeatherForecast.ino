#include <U8g2lib.h>

#define BTN 6

U8X8_SSD1306_128X64_NONAME_HW_I2C oled(/* reset=*/ U8X8_PIN_NONE);

long currentTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(BTN, INPUT);
  
  oled.begin();
  //oled.setFlipMode(1); 
  oled.clearDisplay();
  oled.setFont(u8x8_font_7x14B_1x2_f);

  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.print("Press button\nto retrieve\nweather");
}

void loop() {
  if (digitalRead(BTN)) {
    load();
  }

  if (Serial.available()) {
    readWeatherData();
  }
}

void load() {
  if (millis() - currentTime > 1000) {
    currentTime = millis();
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.print("Loading...");
    Serial.println(1);
  }
}

void readWeatherData() {
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.print(Serial.readString());
}
