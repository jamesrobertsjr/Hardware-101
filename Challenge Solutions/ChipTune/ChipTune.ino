#define NOTE_E 82
#define NOTE_F 87
#define NOTE_G 98
#define NOTE_A 110
#define NOTE_B 123
#define NOTE_C 131
#define NOTE_D 147
#define NOTE_E2 164

#define BUZZ_PIN 5
#define BUTTON_PIN 6

int melody[] = {
  NOTE_F, NOTE_A, NOTE_B,
  NOTE_F, NOTE_A, NOTE_B,
  NOTE_F, NOTE_A, NOTE_B, NOTE_E2, NOTE_D,
  NOTE_B, NOTE_C, NOTE_B, NOTE_G, NOTE_E
};

int durations[] = {
  1, 1, 2,
  1, 1, 2,
  1, 1, 1, 1, 2,
  1, 1, 1, 1, 4
};

int numNotes = 16;

void setup() {
    pinMode(BUZZ_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    playTune();
  }
}

void playTune() {
  for (int noteIdx = 0; noteIdx < numNotes; noteIdx++) {
    // convert duration to milliseconds
    int noteDuration = durations[noteIdx] * 250;
    // play note
    tone(BUZZ_PIN, melody[noteIdx], noteDuration);
    delay(noteDuration);
  }
}
