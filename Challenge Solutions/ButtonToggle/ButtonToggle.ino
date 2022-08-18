#define LED_PIN 4
#define BUTTON_PIN 6

int prevBtnState = 0;
int lightOn = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  // Check for button press
  if (buttonState != prevBtnState && buttonState == 1) {
    // Turn light on if it was previously off
    if (!lightOn) {
      digitalWrite(LED_PIN, HIGH);
      lightOn = true;
    }
    else {
      digitalWrite(LED_PIN, LOW);
      lightOn = false;
    }
    // Delay to prevent input noise
    delay(300);
  }

  // Remember button state
  prevBtnState = buttonState;
}
