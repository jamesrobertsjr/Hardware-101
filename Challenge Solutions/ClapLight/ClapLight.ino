#define soundPin A2
#define ledPin 4

long timestamp;
int clapCount = 0;

bool light = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(soundPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int soundState = analogRead(soundPin); 

//  Use these lines to calibrate the sound for clapping
//    Serial.print("sound: ");
//    Serial.println(soundState);
  if (soundState > 700) {

    clapCount++;

    timestamp = millis();
    // prevent duplicate readings
    delay(500);
  }

  long elapsed = millis() - timestamp;
  
  if (elapsed < 2000 && clapCount > 1) {
    toggleLight();
  } else if (elapsed >=2000) {
    clapCount = 0;
  }

}

void toggleLight() {
  if (!light) {
      digitalWrite(ledPin, HIGH);
      light = true;
  } else {
      light = false;
      digitalWrite(ledPin, LOW);
  }
  clapCount = 0;
}
