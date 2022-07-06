# Lesson 2: Pressing a Button

## Digital Input

The button on our Arduino is a digital input device. This allows us to read a digital state value from the sensor. The `0` or `LOW` state indicates the button is off, or not pressed, while the `1` or `HIGH` state indicates the button is pressed.

Similar to when we connected to the LED, to interact with the button and read its input, we will need to register it as an input device and then read its digital signal.

## Write the Program

Create a new program in the Arduino IDE.

To begin, we will register both the LED and the button as input and output devices in our `setup()` function, and will define global variables for the corresponding pins.

> Hint: the pins are indicated next to each sensor. `D6` means that the button uses digital pin number 6.

```c++
int LED_PIN = 4;
int BUTTON_PIN = 6;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}
```

You can see here that we registered the LED as an output device and the button as an input device.

In the `loop()` function, we will read the digital signal from the button and turn the light on or off according to whether the button is pressed.

```c++
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

This could also be simplified to the following:

```c++
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, buttonState);
}
```

The `digitalRead()` method takes a single parameter, the pin from which we want to read the signal. This will either be `1` (`HIGH`) or `0` (`LOW`). We then take that value and write a corresponding signal to the LED pin.

## Run the Program

Verify that your code compiles and then send the program to your Arduino using the Upload button. You should see that when the button is pressed, the light turns on, and when the button is not pressed, the light is off.

Programming Challenge: [Button Light Toggle](/Challenges.md#button-light-toggle)

Previous: [Lesson 1: Turn on the Light](/Lesson01_LED.md)

Next: [Lesson 3: Buzzer Doorbell](/Lesson03_Buzzer.md)
