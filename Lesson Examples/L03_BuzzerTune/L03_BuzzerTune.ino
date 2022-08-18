#define NOTE_C 131
#define NOTE_D 147
#define NOTE_E 165
#define NOTE_G 198

#define BUZZ_PIN 5
#define BUTTON_PIN 6

int melody[] = {
  NOTE_E, NOTE_E, NOTE_E,
  NOTE_E, NOTE_E, NOTE_E,
  NOTE_E, NOTE_G, NOTE_C, NOTE_D, NOTE_E
};

int durations[] = {
  1, 1, 2,
  1, 1, 2,
  1, 1, 1, 1, 4
};

int numNotes = 11;

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
    // get the current note
    int note = melody[noteIdx];
    // convert duration to milliseconds
    int noteDuration = durations[noteIdx] * 300;
    // play note
    tone(BUZZ_PIN, note, noteDuration);
    delay(noteDuration);
  }
}
