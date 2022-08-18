#define ROTARY_PIN A0

int rotaryValue = 0;

void setup() {
  pinMode(ROTARY_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  rotaryValue = analogRead(ROTARY_PIN);
  Serial.println(rotaryValue);
  delay(100);
}
