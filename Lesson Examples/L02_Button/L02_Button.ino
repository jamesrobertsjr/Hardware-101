#define LED_PIN 4
#define BUTTON_PIN 6

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, buttonState);
}
