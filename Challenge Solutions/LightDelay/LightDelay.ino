#define ROTARY_PIN A0
#define LED_PIN 4

int rotaryValue = 0;

void setup() {
  pinMode(ROTARY_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  rotaryValue = analogRead(ROTARY_PIN);
  digitalWrite(LED_PIN, LOW);
  delay(rotaryValue);
  digitalWrite(LED_PIN, HIGH);
  delay(rotaryValue);
}
