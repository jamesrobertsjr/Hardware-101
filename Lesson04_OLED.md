# Lesson 4: Display Text

In this lesson, we will learn how to display content on the OLED device. We will start out by demonstrating how to display simple text.

If you want to explore more drawing features, you can continue on to Lesson 4.5 as we expand the program to allow users to "roll" a die.

## OLED Display

The OLED Display component is a monochromatic LED that we can program to display text, shapes, and even bitmap images. This component is connected to the Arduino using an I2C protocol signal. An I2C connection uses two wires to transmit data to and from the micro-controller: the Serial Data Line (SDL) and the Serial Clock Line (SCL).

When using I2C components with Arduino, we will typically need to import an additional library into our program to provide us with the commands needed to interact with the device.

## Installing the U8g2 Library

The first time we use the OLED, will need to install the [U8g2](https://github.com/olikraus/u8g2/wiki/u8g2reference) library to our computer.

1. Open the Arduino IDE and click on `Sketch` > `Include Library` > `Manage Libraries...`
2. Search for `u8g2` and click `Install` on the `U8g2` library by `oliver`.

   ![u8g2 library](/assets/u8g2lib.png)

This will download the OLED library for us to reference in our Arduino programs.

## Using the U8g2 Library with the OLED Display

With the library downloaded to our computer, we can now import it into our programs to interact with the OLED sensor. We can include the library using the following command at the top of our program:

```c++
#include <U8g2lib.h>
```

The next step is to create a global object that points to our OLED device. The data type for this object is `U8X8_SSD1306_128X64_ALT0_HW_I2C`. We will create an object variable named `oled` and use the provided type constructor from the `U8g2lib` library.

```c++
U8X8_SSD1306_128X64_NONAME_HW_I2C oled(/* reset=*/ U8X8_PIN_NONE);
```

This constructor call and object definition takes the place of where we have typically defined a global pin variable.

Let's start by programming our OLED to simply display text on the screen. We'll start by initializing our device and setting its drawing orientation in `setup()`:

```c++
void setup() {
  oled.begin();
  oled.setFlipMode(1); 
}
```

The `begin()` method will turn on and initialize the device. The `setFlipMode()` function is used to rotate where content is displayed.

Now, we are ready to send data to the screen. this will happen in our `loop()` function.

```c++
void loop() {
  oled.setFont(u8x8_font_7x14B_1x2_f);
  oled.setCursor(0, 0);
  oled.print("Hello World!");
}
```

The `setFont()` method allows us to select a font from the `u8x8` library. The font name used here, `u8x8_font_7x14B_1x2_f` is a constant provided by our library import.

The next command, `setCursor()` is used to place the cursor at the top left-hand corner of the screen. When we use draw or print commands, unless otherwise specified, the device will draw the content wherever the cursor is currently placed.

> Note: The OLED screen is 128x64 pixels.

Finally, the `print()` command is used to print the specified text, `"Hello World!"`, to our OLED device. Alternatively, instead of calling `setCursor()` and `print()`, you can use the `drawString()` method which combines these two commands into one:

```c++
oled.drawString(0, 0, "Hello World!");
```

If you upload and run the program on your Arduino, you should see the text displayed!

### U8X8 API

Our program is currently using a `U8X8` constructor, which gives us access to the `u8x8` library. This is a *text-only* library that provides a subset of methods focused on printing text to the screen. You can explore all of the methods available in this library here: [U8x8 Reference](https://github.com/olikraus/u8g2/wiki/u8x8reference).

> The `u8x8` library also uses a subset of the `u8g2` fonts. You can find a list of available `u8x8` fonts here: [U8x8 Font List](https://github.com/olikraus/u8g2/wiki/fntlist8x8).

This concludes our basic OLED example. You can move on to the next lesson to explore more fonts and drawing features, or you can skip to [Lesson 6](Lesson06_Analog.md) to learn about analog input devices.

### Example Programs

The library we installed for `U8g2` includes many example programs you can run on your Arduino to test out the features available in the library. You can access them by going to `File` > `Examples` in your Arduino menu, and then selecting `U8g2` at the bottom of the list.

For example, choose the `page_buffer` > `GraphicsTest` program to see an example of some of the expanded graphics available with the extended library.

> Note: To run the example programs, you will have to uncomment one of the `u8g2` constructors at the top of the file. You can select the `U8G2_SSD1306_128X64_NONAME_HW_I2C` device for our Arduino.

You can explore some of the other programs to see how to more fully utilize the library.

## Programming Challenge

Can you print multiple lines of text to the screen? How about change what is displayed based on a button press? Check out these challenges for inspiration:

- [Name Print](Challenges.md#print-your-name)
- [Temperature Display](Challenges.md#temperature-display--toggle)

Previous Topic: [Lesson 3: Buzzer Doorbell](/Lesson03_Buzzer.md)

Next Topic: [Lesson 5: Digital Dice](/Lesson05_OLED_Pt2.md)
