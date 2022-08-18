#include <U8g2lib.h>

#define BTN_PIN 6
#define BZZ_PIN 5

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  pinMode(BTN_PIN, INPUT);
  pinMode(BZZ_PIN, OUTPUT);
  
  u8g2.begin();
  u8g2.setFlipMode(1);
  u8g2.setFont(u8g2_font_maniac_tf);

  // seed random number generator
  randomSeed(analogRead(A3));
  
  displayInstructions();
}

void loop(void) {
  int buttonState = digitalRead(BTN_PIN);

  if (buttonState == HIGH) {
    rollDice();
  }
}

/*
 * Welcome message/instructions
 */
void displayInstructions() {
  u8g2.clearBuffer();
  u8g2.drawStr(5, 30, "Roll the");
  u8g2.drawStr(25, 60, "dice!");
  u8g2.sendBuffer();
}

/* 
 * Animates Dice Roll
 */
void rollDice() {
  // generate two random nums between 1 (inc) and 7 (exc)
  int randNum = random(1, 7);
  int randNum2 = random(1, 7);
  
  for (int i = 0; i < 25; i++) {
    // want to simulate fast random numbers
    int fastNum = (randNum + i) % 6 + 1;
    int fastNum2 = fastNum % 6 + 1;

    drawDice(fastNum, fastNum2);
    int freq = 120;
    tone(BZZ_PIN, freq, 5);
    // slow down delay between each iteration
    delay(5+i*3); 
  }

  // display dice result
  delay(50);
  drawDice(randNum, randNum2);
  tone(BZZ_PIN, 165, 100);
}

/*
 * Display two dice on screen
 * Params:
 *   - num1: value of first die
 *   - num2: value of second die
 */
void drawDice(int num1, int num2) {
    u8g2.clearBuffer();
    drawFace(num1, 10, 5);
    drawFace(num2, 70, 5);
    u8g2.sendBuffer();
}

/*
 * Draw an individual die at a particular position
 * Params:
 *   - num: value of die
 *   - x: x position of die
 *   - y: y position of die
 */
void drawFace(int num, int x, int y)
{
  // Draw square
  u8g2.drawRFrame(x, y, 50, 50, 10);
  
  // Draw pips for each die value
  switch (num) {
    case 1:
      u8g2.drawDisc(25 + x, 25 + y, 5);
      break;
    case 2:
      u8g2.drawDisc(10 + x, 10 + y, 5);
      u8g2.drawDisc(40 + x, 40 + y, 5);
      break;
    case 3:
      u8g2.drawDisc(25 + x, 25 + y, 5);
      u8g2.drawDisc(10 + x, 10 + y, 5);
      u8g2.drawDisc(40 + x, 40 + y, 5);
      break;
    case 4: 
      u8g2.drawDisc(10 + x, 10 + y, 5);
      u8g2.drawDisc(40 + x, 40 + y, 5);
      u8g2.drawDisc(40 + x, 10 + y, 5);
      u8g2.drawDisc(10 + x, 40 + y, 5);
      break;
    case 5: 
      u8g2.drawDisc(10 + x, 10 + y, 5);
      u8g2.drawDisc(40 + x, 40 + y, 5);
      u8g2.drawDisc(40 + x, 10 + y, 5);
      u8g2.drawDisc(10 + x, 40 + y, 5);
      u8g2.drawDisc(25 + x, 25 + y, 5);
      break;
    case 6:
      u8g2.drawDisc(10 + x, 10 + y, 5);
      u8g2.drawDisc(10 + x, 25 + y, 5);
      u8g2.drawDisc(10 + x, 40 + y, 5);
      u8g2.drawDisc(40 + x, 10 + y, 5);
      u8g2.drawDisc(40 + x, 25 + y, 5);
      u8g2.drawDisc(40 + x, 40 + y, 5);
      break;  
  }
}
