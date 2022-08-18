#include <SoftwareSerial.h>

#define SOFTSERIAL_RX_PIN  2
#define SOFTSERIAL_TX_PIN  3

SoftwareSerial softSerial(SOFTSERIAL_RX_PIN,SOFTSERIAL_TX_PIN);

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
  switch(cmd) {
    case Command::PLAY_MUSIC:
      Serial.println("Play music!");
      break;
    case Command::MODE_1:
      Serial.println("Option 1");
      break;
    case Command::MODE_2:
      Serial.println("Option 2");
      break;
    default:
      Serial.println("Other command");
  }
}
