#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define LED_COUNT  10
#define BRIGHTNESS 50 // (max = 255)

#define SOFTSERIAL_RX_PIN  2
#define SOFTSERIAL_TX_PIN  3
 
SoftwareSerial softSerial(SOFTSERIAL_RX_PIN,SOFTSERIAL_TX_PIN);
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

enum Command
{
    TURN_ON_LIGHT = 1,
    TURN_OFF_LIGHT,
    STOP = 18,
    GO = 22
};

int colorMode = 1;
bool lightOn = false;
 
void setup()
{
  pixels.begin();
  pixels.fill();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
  
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
    case Command::TURN_ON_LIGHT:
      lightOn = true;
      break;
    case Command::TURN_OFF_LIGHT:
      lightOn = false;
      break;
    case Command::STOP:
      colorMode = 1;
      break;
    case Command::GO:
      colorMode = 2;
      break;
  }
  changeLight();
}

void changeLight() {
  uint32_t color = pixels.Color(0,0,0);
  if (lightOn) {
    color = colorMode == 1
      ? pixels.Color(255, 0, 0)
      : pixels.Color(0, 255, 0);
  }
  
  pixels.fill(color);
  pixels.show();
}
