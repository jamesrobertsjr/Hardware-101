# Lesson 3: Doorbell Buzzer

## Buzzer

The buzzer is a digital output device that can be used to make beeping sounds. Although it is a digital component, you we can send various tones to the device using pulse width modulation.

### Pulse Width Modulation

Using the `analogWrite()` method, we can control the buzzer's tone using pulse width modulation (PWM). PWM is a method of simulating an analog signal with a digital input.

If you are familiar with morse code, you know that digital signals are used to create short and long pulses that represent letters and numbers. In a similar way, our program can send short and long pulses to a digital output device to communicate a variable output. This is the basis of PWM.

![pwm](assets/pwm.png)

We will register the buzzer as an `OUTPUT` pin. Then, we'll send a PWM signal to the buzzer using the `analogWrite()` function. Although the buzzer is a digital output device, since we are sending an 8-bit value (a number between `0` and `255`) to the buzzer, we will use the `analogWrite()` method.

## Button Buzzer Program

Let's create a new buzzer program. We will start by simply programming the button to play a buzzer sound when pressed. This program will be almost identical to our LED/button example. We'll register both the button and buzzer pins as input/output devices, then read the button's value to trigger the buzzer's beep.

```c++
#define BUZZ_PIN 5
#define BUTTON_PIN 6

void setup() {
    pinMode(BUZZ_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    analogWrite(BUZZ_PIN, 128);
  }
  else {
    analogWrite(BUZZ_PIN, 0);
  }
}
```

When you upload and run the program, you should be able to trigger the buzzer sound using a button press.

> You can play with various values for `analogWrite()`, using numbers between `0-255` to hear the various tones, but they will mostly sound the same.

## Playing Different Notes

Although we can modulate the pulse of our signal with `analogWrite()`, this method does not affect the frequency (or note) of the signal. Arduino allows us to play specific frequencies using the `tone()` method.

The `tone()` function accepts three parameters: the pin, the note value, and the duration (in ms). For example, this would play a `C` note for one second:

```c++
tone(BUZZ_PIN, 65, 1000);
```

Here are some common notes you can use with `tone()`:

| Note | Value |
| --- | --- |
| C | 131 |
| D | 147 |
| E | 165 |
| F | 175 |
| G | 198 |
| A | 220 |
| B | 247 |
| C | 262 |

> You can find additional notes and octaves here: [musical notes](https://github.com/bhagman/Tone#musical-notes).

Let's write a function that will play a tune using some of these tones. First, we'll define some constant identifiers for the notes we will need at the top of our file:

```c++
#define NOTE_C 131
#define NOTE_D 147
#define NOTE_E 165
#define NOTE_G 198
```

We'll also define some arrays to program the melody and duration of each note in our tune (add this after our pin variables):

```c++
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
```

Now we can define a function at the end of the program to loop through our melody array and play each note:

```c++
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
```

Finally, we'll update the `loop()` method to call the `playTune()` method if the button is pressed:

```c++
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    playTune();
  }
}
```

Great! Now, if you upload and run the program, you can hear our custom "doorbell" tune play when the button is pressed.

## Programming Challenge

Can you create your own tune? Check out this challenge for some ideas: [Chiptunes](/Challenges.md#chiptunes)

Previous Topic: [Lesson 2: Pressing a Button](/Lesson02_Button.md)

Next Topic: [Lesson 4: Displaying Text](/Lesson04_OLED.md)
