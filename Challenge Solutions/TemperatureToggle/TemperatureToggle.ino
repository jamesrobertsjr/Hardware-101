#include <DHT.h>
#include <U8g2lib.h>

#define BTN_PIN 6
#define DHTPIN 3
#define DHTTYPE DHT11   // May need to change to DHT20
DHT dht(DHTPIN, DHTTYPE);

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

bool cel = false;
long current = 0;
bool buttonState = 0;

void setup() {
  dht.begin();
  u8x8.begin();
  u8x8.setPowerSave(0);  
  //u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_7x14B_1x2_f);

  pinMode(BTN_PIN, INPUT);
}

void loop() {

  if (digitalRead(BTN_PIN)) {
    if (millis() - current > 200) {
      cel = !cel;
      current = millis();
    }
  }
  
  float temp = dht.readTemperature();
  u8x8.setCursor(0, 0);
  u8x8.print("Temp: ");

  if (cel) {
    u8x8.print(temp);
    u8x8.print("C");
  } else {
    temp = temp * 9 / 5 + 32;
    u8x8.print(temp);
    u8x8.print("F");
  }

  u8x8.refreshDisplay();
}
