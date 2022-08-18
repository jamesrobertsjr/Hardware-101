#include <U8g2lib.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C oled(/* reset=*/ U8X8_PIN_NONE);

void setup() {
  oled.begin();
  oled.setFlipMode(1); 
}

void loop() {
  oled.setFont(u8x8_font_7x14B_1x2_f);
  oled.setCursor(0, 0);
  oled.print("Hello World!");
}
