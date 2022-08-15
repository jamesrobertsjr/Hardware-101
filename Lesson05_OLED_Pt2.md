# Lesson 5: Digital Dice

In this optional lesson, we'll explore the expanded `u8g2` library which gives us access to more fonts and drawing functions to use on the OLED. In this lesson, we'll animate a dice roll on the screen.

## Expanding the OLED Program

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

## Programming Challenges

What are some ways you could improve or expand this program to make it your own? Check out this challenge for ideas: [Double Dice Roll](/Challenges.md#double-dice-roll)

Previous Topic: [Lesson 4: Displaying Text](/Lesson04_OLED.md)

Next Topic: [Lesson 6: Graph Data](/Lesson06_Analog.md)
