#define LED_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int input = Serial.parseInt();

    if (input > 0 && input < 10) {
      for (int i = 0; i < input; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200);
      }
    }
  }
}
