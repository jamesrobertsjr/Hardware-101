#include <U8g2lib.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C oled(/* reset=*/ U8X8_PIN_NONE);

long current = 0;

void setup() {
  Serial.begin(9600);
  
  oled.begin();
  oled.setFlipMode(1); 
  oled.clearDisplay();
  oled.setFont(u8x8_font_7x14B_1x2_f);
}

void loop() {
  if (millis() - current > 2000) {
    Serial.println("Hello from Arduino!");
    current = millis();
    oled.clearDisplay();
  }

  if (Serial.available()) {
    oled.setCursor(0, 0);
    oled.print(Serial.readString());
  }
}
