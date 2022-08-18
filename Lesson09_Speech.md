# Speech Recognizer

The Internet of Things (IoT) describes a network of devices and objects that can connect and communicate with one another. One of the most common ways we see IoT within our day-to-day lives is through voice-activated Smart Home devices like the Amazon Echo, Google Nest, or Apple HomePod. Each of these Smart Home hubs respond to voice-activated commands, and then connect to other Bluetooth or WiFi-connected devices to execute the commands.

In this lesson, we will integrate a simple speech recognition sensor to demonstrate how to build a voice-activated device.

## Materials

You will need the [Grove Speech Recognizer](https://www.seeedstudio.com/Grove-Speech-Recognizer.html) to complete this lesson, which does not come built into the Grove Beginner Kit.

You will need to connect the speech recognition sensor to the Arduino on port **D2**.

## Hello Hicell

Like most other voice-activated devices, our speech recognition sensor responds to a specific "wake" word: "Hicell." When the sensor hears the word "Hicell," it will listen for a command.

Unlike Amazon and Apple, our sensor does not have the same natural language processing capabilities as Alexa or Siri. Instead, our sensor responds to twenty-two command words.

When you say "Hicell," a small LED light on the sensor will turn red as it listens, and then the LED will turn blue if it recognizes your command. Each command has a corresponding numeric value that can then be evaluated by our program.

### Command/value table

| Command | Value |
|---|---|
| Turn on the light | 1 |
| Turn off the light | 2 |
| Play music | 3 |
| Pause | 4 |
| Next | 5 |
| Previous | 6 |
| Up | 7 |
| Down | 8 |
| Turn on the TV | 9 |
| Turn off the TV | 10 |
| Increase temperature | 11 |
| Decrease temperature | 12 |
| What’s the time | 13 |
| Open the door | 14 |
| Close the door | 15 |
| Left | 16 |
| Right | 17 |
| Stop | 18 |
| Start | 19 |
| Mode 1 | 20 |
| Mode 2 | 21 |
| Go | 22 |

## Responding to Voice Commands

Now that we understand how to interact with the sensor, let's begin writing our first voice-activated program. We will first create a program that responds to voice commands by printing text commands to the Serial Monitor. Then, we'll expand the program to play a song when the correct command is given.

### SoftwareSerial Library

We have seen in other lessons how Arduino can communicate with the computer using serial communication. We are going to use serial communication again to interact with the speech recognition sensor, but this time we'll utilize the `SoftwareSerial` library. This library allows us send and receive serial communication back and forth between the Arduino and the external sensor.

The `SoftwareSerial` library should be pre-installed with your Arduino software. To use it, we simply need to import into our program.

Create a new program and add this `SoftwareSerial` import at the top of the file:

```c
#include <SoftwareSerial.h>
```

We'll also define two variables to represent the pins on which the Speech Recognizer is going to communicate. The `RX` pin is used to receive serial data, and the `TX` pin is used to transmit serial data. Add this to your program:

```c
#define SOFTSERIAL_RX_PIN  2
#define SOFTSERIAL_TX_PIN  3
```

Finally, we'll create an object that represents our connection to the Speech Recognizer using the `SoftwareSerial` constructor:

```c
SoftwareSerial softSerial(SOFTSERIAL_RX_PIN,SOFTSERIAL_TX_PIN);
```

Now we're ready to interact with the Speech Recognizer!

### Listen for Commands

To begin, let's initialize our program by setting up a Serial port and begin listening for communication. We will open serial communication for both the Arduino and the Speech Recognizer. This will allow the Arduino to listen for data from the Speech Recognizer, but also allow the Arduino to print data to the Serial Monitor.

Update the `setup()` function with the following:

```c++
void setup()
{
    Serial.begin(9600);
    softSerial.begin(9600);
    softSerial.listen();
}
```

Next, we need to listen for and process data sent to us from the Speech Recognizer. In the `loop()` function, we can listen for data received with the `softSerial.available()` function.

Add this to the `loop()` function so that we can see how the Speech Recognizer sends commands to our Arduino:

```c++
void loop()
{
    char cmd;
 
    if(softSerial.available())
    {
        cmd = softSerial.read();
        Serial.println((int) cmd);
    }
}
```

In this code snippet, we are waiting until the `softSerial` has data available to read. Then, we read the data sent, cast it to an `int` data type and print it to the Serial Monitor.

If you open the Serial Monitor and set the baud rate to `9600`, you should be able to see our program print out command words as you speak them.

Try it out! First, say the wake word, "Hicell," and wait for the red light to come on. Then, say one of the command words in the table above. If the sensor recognizes your command, the light will turn blue and the program will print the corresponding integer to the Serial Monitor!

### Define our Commands

As we've just demonstrated, when our Speech Recognizer hears one of the 22 registered commands, it will send a corresponding command code (`1` - `22`) to the Arduino.

We could hard code our program's logic to respond to specific integer values, but this would make our program brittle, as well as difficult to read and maintain. Instead, we'll create an `enum` variable that can be used to represent specific commands.

> An `enum` is a user-defined data type that maps specific names to integer constants.

Now, we don't need to define every single available command, but only the ones that we need for our program. Add this to your program before the `setup()` function:

```c
enum Command
{
    PLAY_MUSIC =3,
    MODE_1 = 20,
    MODE_2
};
```

We've selected three commands for our first program. Notice that the numbers provided match the integer values defined in the Hicell command table above. By default, enum values will start with `0` and increment each name value by one. We can override this by providing explicit values for each command. (Since we did not provide a number for `MODE_2`, it will increment from the previous value.)

### Respond to Commands

With our commands defined, we can now begin processing the commands and responding to them within our program.

Let's start by creating a function, `processCommand()`, that will take an `int` parameter and perform logic based on which `Command` it matches. We'll use a switch/case block to see if command from the sensor matches any of our `Command` enum values.

Add this after the `loop()` function:

```c++
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
```

Now, we just need to call our function. In the `loop()` if statement, replace the `Serial.println()` line with the following:

```c++
processCommand(cmd);
```

Now, when we run our program and say one of the programmed commands, we will see human-readable output in our Serial Monitor.

## Integrating with Other Devices

Now that we have seen how to respond to voice commands within our Arduino program, let's expand the program to actually respond by integrating other sensors.

As you can imagine, there are many possibilities available for creating an IoT device! You could turn on lights, display text or sprites on the OLED, or even connect to a NodeJS program to perform API operations based on voice commands.

In this example, we will integrate the buzzer song we created in Lesson 3 to have our device "Play Music."

Let's build on the program we just finished. We'll need to connect to the buzzer pin, define our song variables, and then create a function that plays the song.

### Define Buzzer Variables

We'll need to define variables at the top of our file for the buzzer pins and our music notes. Add these to your program (you can add the data for your own song if you want!):

```c++
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
```

### Initialize the Buzzer

Next, we need to initialize the buzzer in the `setup()` function:

```c++
pinMode(BUZZ_PIN, OUTPUT);
```

### Create a Song Function

Now, let's create a small function to play our song:

```c++
void playTune() {
  for (int noteIdx = 0; noteIdx < numNotes; noteIdx++) {
    int note = melody[noteIdx];
    int noteDuration = durations[noteIdx] * 300;
    tone(BUZZ_PIN, note, noteDuration);
    delay(noteDuration);
  }
}
```

### "Hicell, Play Music"

Finally, let's update our `processCommand()` function to call the `playTune()` function when the `PLAY_MUSIC` command is spoken.

You can either update the existing `switch` statement, or, since we no longer need the additional options, you can replace the entire `switch/case` with an if statement:

```c++
void processCommand(char cmd) {
  if (cmd == Command::PLAY_MUSIC) {
    playTune();
  }
}
```

Alright! Now, when you run the program and ask Hicell to play music, it will play our song!

## Programming Challenge

What ways can you think of to integrate the Speech Recognizer into other IoT programs?

Here's a challenge that integrates the RGB LED strip:

- [Red Light, Green Light](/Challenges.md#red-light-green-light)

Previous Topic: [Lesson 8: RGB LED](/Lesson08_RGB_LED.md)

Next Topic: [Lesson 10: Measuring Distance](/Lesson09_Speech.md)
