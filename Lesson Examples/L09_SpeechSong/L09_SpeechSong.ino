#include <SoftwareSerial.h>

#define SOFTSERIAL_RX_PIN  2
#define SOFTSERIAL_TX_PIN  3

SoftwareSerial softSerial(SOFTSERIAL_RX_PIN,SOFTSERIAL_TX_PIN);

/*
 * Song Variables
 */
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

enum Command
{
    PLAY_MUSIC =3,
    MODE_1 = 20,
    MODE_2
};

void setup()
{
    Serial.begin(9600);
    softSerial.begin(9600);
    softSerial.listen();
    pinMode(BUZZ_PIN, OUTPUT);
}

void loop()
{
    char cmd;
 
    if(softSerial.available())
    {
        cmd = softSerial.read();
        processCommand(cmd);
    }
}

void processCommand(char cmd) {
  if (cmd == Command::PLAY_MUSIC) {
    playTune();
  }
}

void playTune() {
  for (int noteIdx = 0; noteIdx < numNotes; noteIdx++) {
    int note = melody[noteIdx];
    int noteDuration = durations[noteIdx] * 300;
    tone(BUZZ_PIN, note, noteDuration);
    delay(noteDuration);
  }
}
