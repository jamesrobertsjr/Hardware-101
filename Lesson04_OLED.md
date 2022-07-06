# Lesson 4: Digital Dice

In this lesson, we will learn how to display content on the OLED device. We'll start out by displaying text, then will write a program that allows users to "roll" a die: when the button is pressed, we'll randomly select a die face and display it to the screen.

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

Let's start by programmimg our OLED to simply display text on the screen. We'll start by initializing our device and setting its drawing orientation in `setup()`:

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

> Note: The `u8x8` library also uses a subset of the `u8g2` fonts. You can find a list of available `u8x8` fonts here: [U8x8 Font List](https://github.com/olikraus/u8g2/wiki/fntlist8x8).

## Expanding the Program

If your program only needs to use text, using `u8g8` is ideal since it is a smaller library that will take up less space on the device. However, if you need expanded fonts or additional drawing features, you can use the full [u8g2 library](https://github.com/olikraus/u8g2/wiki/u8g2reference).

This library includes extended font options, as well as dozens of methods that allow you to easily draw lines, shapes, glyphs, and even bitmap images. You can see a program that demos many of the drawing features here: [Shape Demo](https://github.com/Seeed-Studio/Seeed_Learning_Space/blob/master/Grove%20-%20OLED%20Display%200.96''(SSD1315)V1.0/ShapeTest/ShapeTest.ino)

Let's create a new program that will use the `u8g2` library. Start a new Arduino program, and add this to the beginning ot initialize a `u8g2` object:

```c++
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
```

### Drawing Dice

We can go about displaying dice on the screen in multiple ways. We could print numbers to the screen, use glyphs or bitmaps to display dice images, or draw rectangles and circles on the screen to represent each die face. For this example, we will draw a simple square with a number in the middle to represent each die face.

> Note: The font list for `u8g2` is different than `u8x8`. You can find the [u8g2 font reference](https://github.com/olikraus/u8g2/wiki/fntlistall) here.

When we want to draw (and redraw) shapes on the screen, we'll make use of the `clearBuffer()` and `sendBuffer()` methods. These functions clear the data from and send new instructions to the screen.

To draw a square, we'll use the `drawRFrame()` method, which accepts five parameters: starting `x` & `y` positions, the `height`, the `width`, and a border radius. Our method will look like this:

```c++
u8g2.drawRFrame(40,5,50,50,10);
```

This will draw a rounded square starting at x/y coordinates `(40, 5)` with a height and width of `50px` and a border radius of `10px`.

Next, we can send text to the screen by using the `drawStr()` method, which accepts `x`, `y`, and string parameters, or by using the `setCursor()` and `print()` methods. If you want to print string data to the screen, its simpler to use `drawStr()`, but if you want to stringify an `int` or other data type, you can leverage the `print()` method.

Altogether, a method that prints a die face to the screen might look like this:

```c++
void drawFace(int num)
{
  u8g2.clearBuffer();
  
  // Draw square
  u8g2.drawRFrame(40,5,50,50,10);
  
  // Draw number
  u8g2.setCursor(57,42);
  u8g2.print(num);
  
  u8g2.sendBuffer();
}
```

### Implementing the Dice Roll

Using our `drawFace()` method, we can write the rest of our program. This program should:

1. Initialize the peripherals
2. Display instructions
3. Animate a die roll when the button is pressed
4. Select and display a random number between 1-6 on the die face

#### 1. Initialize the Peripherals

We'll initialize our OLED screen and button in the `setup()` of our program. We'll also make a call to a `displayInstructions()` method, which we'll implement shortly.

```c++
#include <U8g2lib.h>

int BTN_PIN = 6;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  pinMode(BTN_PIN, INPUT);
  
  u8g2.begin();
  u8g2.setFlipMode(1);
  u8g2.setFont(u8g2_font_maniac_tf);
  
  displayInstructions();
}
```

Notice that our `setup()` method both sets the button as an input and initializes our OLED. As part of our OLED initialization, we set the flip mode and set the font for our program.

#### 2. Display Instructions

To display instructions, we'll simply write the text "Roll the dice!" to the screen. Since this text will span two lines, we use the `drawStr()` method twice. We're using the `sendBuffer()` method to send the data to the screen.

```c++
void displayInstructions() {
  u8g2.clearBuffer();
  u8g2.drawStr(5, 30, "Roll the");
  u8g2.drawStr(25, 60, "dice!");
  u8g2.sendBuffer();
}
```

#### 3. Animate a Die Roll when the Button is Pressed

We can simulate a die roll by calling our `drawFace()` method multiple times in succession. Let's write a method called `rollDice()` that does this:

```c++
void rollDice() {
  for (int i = 0; i < 20; i++) {
    drawFace(i % 6 + 1);
    delay(5);
  }
}
```

This method simply uses a `for` loop to display the numbers 1-6 on the die.

We'll call this method in our `loop()` function when the button is pressed, like we've done in other lessons:

```c++
void loop(void) {
  int buttonState = digitalRead(BTN_PIN);

  if (buttonState == HIGH) {
    rollDice();
  }
}
```

#### 4. Select and Display a Random Number Between 1-6

Finally, we'll select a random number for our die and display it on the screen. We'll leverage Arduino's `random()` function to select our number, which accepts a first parameter as the min value (inclusive) and a second parameter as the max value (exclusive). This random number will then be passed to our `drawFace()` method.

Update the `rollDice()` with the following:

```c++
void rollDice() {
  for (int i = 0; i < 20; i++) {
    drawFace(i % 6 + 1);
    delay(5);
  }
  int randNum = random(1, 7); // random num between 1 (inc) and 7 (exc)
  drawFace(randNum);
}
```

### Run the Program

If you have not already been iteratively testing the program, it's now time to run our app! Upload the program and run it on the Arduino to test out the die roll. When the program first starts, it should display the "Roll the die!" message. Then, when you press the button, the die roll animation should appear and then land on a random number.

What are some ways you could improve or expand this program to make it your own?

Programming Challenge: [Double Dice Roll](/Challenges.md#double-dice-roll)

Previous: [Lesson 3: Buzzer Doorbell](/Lesson03_Buzzer.md)

Next: [Lesson 5: ]
