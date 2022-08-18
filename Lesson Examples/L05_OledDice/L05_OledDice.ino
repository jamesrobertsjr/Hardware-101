#include <U8g2lib.h>

#define BTN_PIN 6
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  pinMode(BTN_PIN, INPUT);
  
  u8g2.begin();
  u8g2.setFlipMode(1);
  u8g2.setFont(u8g2_font_maniac_tf);
  
  displayInstructions();
}

void loop(void) {
  int buttonState = digitalRead(BTN_PIN);

  if (buttonState == HIGH) {
    rollDice();
  }
}

void displayInstructions() {
  u8g2.clearBuffer();
  u8g2.drawStr(5, 30, "Roll the");
  u8g2.drawStr(25, 60, "dice!");
  u8g2.sendBuffer();
}

void rollDice() {
  for (int i = 0; i < 20; i++) {
    drawFace(i % 6 + 1);
    delay(5);
  }
  int randNum = random(1, 7); // random num between 1 (inc) and 7 (exc)
  drawFace(randNum);
}

void drawFace(int num)
{
  u8g2.clearBuffer();
  
  // Draw square
  u8g2.drawRFrame(40,5,50,50,10);
  
  // Draw number
  u8g2.setCursor(57,42);
  u8g2.print(num);
  
  u8g2.sendBuffer();
}
