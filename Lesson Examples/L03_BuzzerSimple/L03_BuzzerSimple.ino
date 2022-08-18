#define BUZZ_PIN 5
#define BUTTON_PIN 6

void setup() {
    pinMode(BUZZ_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    analogWrite(BUZZ_PIN, 128);
  }
  else {
    analogWrite(BUZZ_PIN, 0);
  }
}
