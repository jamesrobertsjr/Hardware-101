int LED_PIN = 4;
int BUTTON_PIN = 6;

int prevBtnState = 0;
int lightOn = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState != prevBtnState && buttonState == 1) {
    if (lightOn) {
      digitalWrite(LED_PIN, HIGH);
      lightOn = true;
    }
    else {
      digitalWrite(LED_PIN, LOW);
      lightOn = false;
    }
  }

  prevBtnState = buttonState;

//    digitalWrite(LED_PIN, HIGH);
//    delay(1000);
//    digitalWrite(LED_PIN, LOW);
//    delay(1000);
}
