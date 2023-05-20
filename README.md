# Motor Library for Arduino

This is a small library for controlling a motor using the L298 H-Bridge chip on an Arduino board. It provides an easy-to-use interface for controlling the speed and direction of the motor.

## About

This library was created by FabLab Bahrain and is maintained by Ghassan Yusuf. FabLab Bahrain is a community-driven makerspace that provides access to tools and resources for people to learn, create, and innovate. To learn more about FabLab Bahrain, visit their website at [www.fablabbahrain.com](https://www.fablabbahrain.com/).

## Motivation

At the heart of every great Arduino project lies the ability to control motors with ease. However, motor control can be a daunting task for many beginners, requiring the use of timers, input monitoring, and pull-ups. We wanted to make motor control accessible to everyone, regardless of their level of experience with Arduino.

That's why we created the Motor library! Our library is designed to simplify motor control and make it easy for new users to get started with Arduino. With just a few lines of code, you can control your motor's speed and direction, making learning and building new projects more accessible and fun.

We're committed to making the Arduino community a welcoming place for everyone, and we believe that our Motor library is just one small step in that direction. We hope that our library will help you build amazing projects with minimum effort and maximum enjoyment.

We offer different versions of the library to suit your needs and make it easy for you to select the one that works best for your specific project. Whether you're a beginner or an experienced Arduino user, we're confident that our library will help you achieve your motor control goals in an efficient and enjoyable way.

## Installation

To use this library, simply download the `Motor.h` and `Motor.cpp` files and place them in your Arduino sketchbook library folder. Alternatively, you can download the repository and extract the files to your sketchbook library folder.

## Usage

To use the Motor library in your Arduino sketch, you need to include the `Motor.h` header file:

```c++
#include <Motor.h>
```

Then, create a new instance of the Motor class and specify the pins used to control the motor:

```c++
Motor motor(ena_pin, in1_pin, in2_pin);
```

Replace `ena_pin`, `in1_pin`, and `in2_pin` with the actual pin numbers you are using.

### LinksThe Motor library is designed to work with the L298 H-Bridge chip. Here are some helpful links related to the L298:

- [L298 Datasheet](https://www.st.com/resource/en/datasheet/l298.pdf)
- [L298 Module on Amazon](https://www.amazon.com/L298N-Controller-Stepper-Driver-Module/dp/B014KMHSW6)

## Methods

The Motor class provides the following methods:

### `begin()`

This method initializes the pins used to control the motor. It should be called once in the `setup()` function of your Arduino sketch.

```c++
motor.begin();
```

### `setMin()`

This method sets the minimum speed of the motor. The default minimum speed is 0.

```c++
motor.setMin(50); // Set the minimum speed to 50
```

### `setMax()`

This method sets the maximum speed of the motor. The default maximum speed is 255.

```c++
motor.setMax(200); // Set the maximum speed to 200
```

### `invert()`

This method inverts the direction of the motor. It is useful when the motor is mounted in reverse.

```c++
motor.invert(); // Invert the direction of the motor
```

### `forward()`

This method sets the direction of the motor to forward.

```c++
motor.forward(); // Set the direction of the motor to forward
```

### `backward()`

This method sets the direction of the motor to backward.

```c++
motor.backward(); // Set the direction of the motor to backward
```

### `goMin()`

This method sets the speed of the motor to the minimum speed.

```c++
motor.goMin(); // Set the speed of the motor to the minimum speed
```

### `goMax()`

This method sets the speed of the motor to the maximum speed.

```c++
motor.goMax(); // Set the speed of the motor to the maximum speed
```

### `goSpeed()`

This method sets the speed of the motor to a user-defined value between the minimum and maximum speeds.

```c++
motor.goSpeed(100); // Set the speed of the motor to 100
```

### `goPercentage()`

This method moves the motor with a percentage between the minimum and maximum speeds, where minimum speed is 1% and maximum speed is 100%, and stopping is 0%.

```c++
motor.goPercentage(50); // Move the motor at 50% of the maximum speed
```

### `goOverride()`

This method overrides the motor speed regardless of minimum and maximum constraints.

```c++
motor.goOverride(128); // Set the motor speed to 128
```

### `stop()`

This method stops the motor by setting the enable pin to low.

```c++
motor.stop(); // Stop the motor
```

### `command()`

This method is used to control the motor using serial input. It prompts the user to enter a PWM value and sets the motor speed accordingly. To exit the command function, enter "EXIT", "Exit", or "exit" as the input value.

```c++
motor.command(Serial); // Control the motor using serial input
```

## Example

Here's an example Arduino sketch that demonstrates how to use the Motor library to control a motor:

```c++
#include <Motor.h>

// Motor pins
const uint8_t ENA_PIN = 5;
const uint8_t IN1_PIN = 6;
const uint8_t IN2_PIN = 7;

// Create a new instance of the Motor class
Motor motor(ENA_PIN, IN1_PIN, IN2_PIN);

void setup() {
  // Initialize the motor
  motor.begin();
}

void loop() {
  // Move the motor forward at 50% speed
  motor.forward();
  motor.goPercentage(50);
  delay(5000);

  // Stop the motor
  motor.stop();
  delay(1000);

  // Move the motor backward at 75% speed
  motor.backward();
  motor.goPercentage(75);
  delay(5000);

  // Stop the motor
  motor.stop();
  delay(1000);
}
```

## License

This library is licensed under the MIT License. See the `LICENSE` file for more details.