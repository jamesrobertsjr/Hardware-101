# Arduino Challenges

Here are some programming challenges you can take on as you continue to explore the Arduino!

- [Arduino Challenges](#arduino-challenges)
  - [Beginner](#beginner)
    - [Button Light Toggle](#button-light-toggle)
    - [Print Your Name](#print-your-name)
    - [Light Delay](#light-delay)
  - [Intermediate](#intermediate)
    - [Night Light](#night-light)
    - [Chiptunes](#chiptunes)
    - [Temperature Display \& Toggle](#temperature-display--toggle)
    - [Beep Beep Selector](#beep-beep-selector)
    - [LED Strip Dial](#led-strip-dial)
    - [Parking Helper](#parking-helper)
    - [Red Light, Green Light](#red-light-green-light)
  - [Advanced](#advanced)
    - [Color Selector](#color-selector)
    - [Double Dice Roll](#double-dice-roll)
    - [Clapper Light](#clapper-light)
    - [Weather Forecast](#weather-forecast)

## Beginner

### Button Light Toggle

Write a program to toggle the LED light on and off using a button press.

**Requirements:**

The light should begin in an off state. When the button is pressed, the light should turn on and stay on until the button is pressed a second time. The light should toggle on and off with each button press.

**Solution:** [Button/Light Toggle Program](/Challenge%20Solutions/ButtonToggle/ButtonToggle.ino)

### Print Your Name

Write a program that prints your first and last name on the OLED.

**Requirements:**

Print your name on two separate lines of the OLED.

> Hint: use the `oled.clearDisplay();` function to wipe old data from the screen.

**Solution:** [Name Example](/Challenge%20Solutions/PrintName/PrintName.ino)

### Light Delay

Write a program that will blink the LED light at variable intervals based on rotary input.

**Requirements:**

Use the LED output to turn the light on and off on repeat, but instead of setting the delay to a fixed value (like `500`), use the rotary potentiometer to allow the user to adjust the delay between each light change. If the rotary is turned all the way down, the light should blink slowly. As the rotary is turned, the blinking should get faster, and when it is all the way up, the light should stay on.

**Solution:** [Rotary Light Program](/Challenge%20Solutions/LightDelay/LightDelay.ino)

## Intermediate

### Night Light

Create a night light that automatically turns on when the light level in the room falls below a certain threshold.

**Requirements:**

Write a program that uses the light detector to sense the light level in the room. When the light level falls below a certain threshold, turn on one of the LED output devices as a "night light."

> Tip: Use the Serial Plotter to compare various light levels to see when you should turn the night light on.

**Solution:** [Night Light Program](/Challenge%20Solutions/NightLight/NightLight.ino)

### Chiptunes

[Chiptunes](https://en.wikipedia.org/wiki/Chiptune), also known as 8-bit music or chip music, are the synthesized sounds made famous in arcades and other video games. Find a song you like and create a chiptune version using the Arduino.

**Requirements:**

Write a program that plays a chiptune song. The program should define the frequencies and durations of the notes in the song and then play them when a button is pressed.

**Solution:** [The Lost Forest](/Challenge%20Solutions/ChipTune/ChipTune.ino)

### Temperature Display & Toggle

Write a program that will display the current temperature on the OLED in either Fahrenheit or Celsius.
Allow the user to toggle between F and C.

> You can learn about how to integrate with the Grove's Temperature sensor here: [Detecting Temperature and Humidity](https://wiki.seeedstudio.com/Grove-Beginner-Kit-For-Arduino/#lesson-8-detecting-surrounding-temperature-humidity).

**Requirements:**

Download and include the `DHT` library into your program, then use it to read the temperature using your board's Temperature and Humidity sensor.

By default, display the temperature in Celsius. When the user pushes the button, convert the temperature to Fahrenheit and display the temperature accordingly. The button should toggle back and forth between C and F.

**Solution:** [Temperature Toggle](/Challenge%20Solutions/TemperatureToggle/TemperatureToggle.ino)

### Beep Beep Selector

Write a program that lets the user select how many times they would like to hear the program beep.

**Requirements:**

Use the rotary potentiometer to read input from the user. Convert the analog value to a number between `1` and `5` and display the number on the OLED screen. When the user presses a button, take the number that is currently displayed on the screen and beep the buzzer that many times.

> Hint: you can use the [map() function](https://www.arduino.cc/reference/en/language/functions/math/map/) to convert the rotary input to a value between `1` and `5`.

For example, when the rotary is turned all the way down, the screen will display `1`. As the user turns the rotary, the number will increase slowly from `1` to `5` (`5` being the max value). If the user presses the button when a `3` is on the screen, the buzzer will beep three times.

**Solution:** [Rotary Select Beep Program](/Challenge%20Solutions/BeepBeep/BeepBeep.ino)

### LED Strip Dial

Use the rotary potentiometer as a dial that "turns up" the lights on the RGB LED strip.

**Requirements:**

Using the rotary potentiometer as an input device, display the input level on the RGB LED strip. When the dial is turned all the way "down," all of the LEDs should be off, and as the dial is turned "up," the LEDs should turn on one by one until all of them are lit up. Light up the LEDs with your favorite color!

> Hint: use the `map()` function to convert the rotary input into an LED output.

**Solution:** [LED Dial](/Challenge%20Solutions/LedDial/LedDial.ino)

### Parking Helper

Create a program that will help drivers know how far to pull into their parking spaces to avoid damaging their car.

**Requirements:**

Use the Ultrasonic Distance Sensor to create a program that assists a driver when pulling their car into a parking space or garage. The program should use the RGB LED Strip to display a yellow color when the driver is approaching, and a red color when they should stop pulling forward.

**Solution:**

[Parking Helper](/Challenge%20Solutions/ParkingHelper/ParkingHelper.ino)

### Red Light, Green Light

Create a program that turns on red and green lights based on the command words "Stop" and "Go".

**Requirements:**

Using the Speech Recognizer, create a program that controls the lights on the RGB LED strip. It should turn the LED lights on and off when it hears "Turn the light on/off." When it hears "Stop," it should turn the RBG LED lights red, and when it hears "Go," it should turn the RGB LED lights green.

**Solution:** [Red Light, Green Light](/Challenge%20Solutions/RedLightGreenLight/RedLightGreenLight.ino)

## Advanced

### Color Selector

Create a program that allows users to select the RGB values for the RGB LED strip.

**Requirements:**

On the OLED, display the individual RGB values of the LED strip. When the user presses a button, they can edit the values one at a time. The user can use the rotary potentiometer to update each RGB value and see the results on the RGB LED. When they are done, the updated values are displayed on the OLED screen and the RGB LED strip.

Example:

1. RGB values are displayed on OLED and the corresponding color is shown on the LED strip.
2. User presses a button to enter into edit mode. They begin by editing the Red value.
3. As the user twists the rotary potentiometer, the Red value modulates between `0` and `255`.
4. When the user presses the button, the selected Red value is saved and they can then begin editing the Green value.
5. Repeat steps 3 and 4 for Green and Blue.
6. Once all three colors have been selected, the OLED will display all three selected RGB values and the RGB LED will show that color.

> Note: Since the button is hardwired to use pin `6`, you will need to plug your RGB LED strip into a different pin with your Grove connector.

**Solution:** [LED Color Select Program](/Challenge%20Solutions/ColorSelector/ColorSelector.ino)

### Double Dice Roll

Create a program that allows players to roll two dice which display their numbers with pips (dots).

**Requirements:**

Expand the [OLED dice program](/Lesson%20Examples/L05_OledDice/L05_OledDice.ino) to include at least one of the following enhancements:

- Display two dice instead of one
- Draw pips on each die face instead of printing numbers to represent values
  ![Dice pips](assets/dice-pips.png)
- Create a sound effect that plays when the dice are rolled

**Solution:** [Advanced Dice Roll](/Challenge%20Solutions/DoubleDice/DoubleDice.ino)

### Clapper Light

Write a program that turns on the LED when a user claps twice. Clap on! Clap off!

**Requirements:**

Using the sound sensor, detect when the noise level goes above a certain level, i.e., when you clap your hands (the value for this sound level may change depending on your environment).

If a clap occurs twice within 2 seconds (2000 milliseconds), toggle the LED on and off.

> You can use the `millis()` to return a `long` value representing the current elapsed milliseconds to keep track of time.

**Solution:** [Clapper Program](/Challenge%20Solutions/ClapLight/ClapLight.ino)

### Weather Forecast

Using the [OpenWeather API](https://openweathermap.org/), create an app that displays the current day's temperature, high and low forecast, and weather summary.

**Requirements:**

Create a free account with OpenWeather API to get access to an API key.

Once you have an API key, write a NodeJS program that will make an HTTP request to the OpenWeather API to retrieve the current weather. Here is the documentation for this endpoint: [Current Weather](https://openweathermap.org/current).

A sample request would look like this:

```shell
https://api.openweathermap.org/data/2.5/weather?units=imperial&lat=33.15&lon=-96.82&appid=<API_KEY>
```

You can hard code your own latitude and longitude values, or find a way to allow the user to enter them.

The Arduino program should start by displaying simple instructions, like "Press button to get forecast." Once the forecast is requested, send a data message to the NodeJS app to trigger the Weather API call.

When the API call is complete within the NodeJS app, process the data and format what you want to send back to the Arduino, then write it using Serial Port.

When the weather data is available from `Serial` in the Arduino, print the results to the OLED.

Example Output:

```shell
Temp: 78.48
Clouds
High: 83.43
Low: 74.57
```

**Solution:** [Weather Program](/Challenge%20Solutions/WeatherForecast)
