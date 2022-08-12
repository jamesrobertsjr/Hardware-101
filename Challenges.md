# Arduino Challenges

Here are some programming challenges you can try as you continue to explore how to use your Arduino!

## Beginner

### Button Light Toggle

Write a program to toggle the LED light on and off using a button press.

**Requirements:**

The light should begin in an off state. When the button is pressed, the light should turn on and stay on until the button is pressed a second time. The light should toggle on and off with each button press.

**Solution:** [Button/Light Toggle Program](/programs/Button_Sketch_2.ino)

### Print Your Name

Write a program that prints your name on the OLED.

**Requirements:**

Print your name on two separate lines of the OLED.

**Solution:** TODO

### Light Delay

Write a program that will blink the LED light at variable intervals based on rotary input.

**Requirements:**

Use the LED output to turn the light on and off on repeat, but instead of setting the delay to a fixed value (like `1000`), use the rotary potentiometer to allow the user to adjust the delay between each light change. If the rotary is turned all the way down, the light should blink slowly. As the rotary is turned, the blinking should get faster, and when it is all the way up, the light should stay on.

**Solution:** TODO

## Intermediate

### Night Light

Create a night light that automatically turns on when the light level in the room falls below a certain threshold.

**Requirements:**

Write a program that uses the light detector to sense the light level in the room. When the light level falls below a certain threshold, turn on one of the LED output devices as a "night light."

> Tip: Use the Serial Plotter to compare various light levels to see when you should turn the night light on.

**Solution:** TODO

### Chiptunes

[Chiptunes](https://en.wikipedia.org/wiki/Chiptune), also known as 8-bit music or chip music, are the synthesized sounds made famous in arcades and other video games. Find a song you like and create a chiptune version using the Arduino.

**Requirements:**

Write a program that plays a chiptune song. The program should define the frequencies and durations of the notes in the song and then play them when a button is pressed.

**Example:** [The Lost Forest](/programs/Buzzer_Sketch_2.ino)

### Temperature Display & Toggle

Display temp on OLED, press button to toggle between C and F.

TODO - include ref to temp in handbook

### Beep Beep Selector

Write a program that lets the user select how many times they would like to hear the program beep.

**Requirements:**

Use the rotary potentiometer to read input from the user. Convert the analog value to a number between `1` and `5` (hint: use modulo) and display the number on the OLED screen. When the user presses a button, take the number that is currently displayed on the screen and beep the buzzer that many times.

For example, when the rotary is turned all the way down, the screen will display `1`. As the user turns the rotary, the number will increase slowly from `1` to `5` (`5` being the max value). If the user presses the button when a `3` is on the screen, the buzzer will beep three times.

**Solution:** TODO

## Advanced

### Color Selector

Rotary select color, light up RGB

TODO

### Double Dice Roll

Create a program that allows players to roll two dice which display their numbers with pips (dots).

**Requirements:**

Expand the [OLED dice program](programs/OLED_Dice_Sketch.ino) to include the following enhancements:

- Display two dice instead of one
- Draw pips on each die face instead of printing numbers to represent values
  ![Dice pips](assets/dice-pips.png)
- Create a sound effect that plays when the dice are rolled

**Solution:** [Advanced Dice Roll](/programs/OLED_Dice_Sketch_2.ino)

### Clapper Light

Write a program that turns on the LED when a user claps twice. Clap on! Clap off!

**Requirements:**

TODO

**Solution:** [Clapper Program](/programs/Clapper_Sketch.ino)
