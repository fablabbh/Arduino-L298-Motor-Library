/*
  Fablab Bahrain L298 Motor Driver Library
  ----------------------------------------
  This library was developed by Fablab Bahrain a community makerspace in Bahrain that provides access to digital fabrication tools and technologies.
  You can learn more about Fablab Bahrain and its services at https://linktr.ee/fablabbh.
  
  About This Example Code
  -----------------------
  This example shows how to set the minimum and maximum speeds of the motor using the setMin() and setMax() methods. The motor will move forward and backward at different speeds within the set limits.
  
  About This Library
  ------------------
  The library provides an easy-to-use interface for controlling motors using the L298 H-bridge motor driver. The library supports setting the motor speed, direction, and braking.
  To use this library, you will need an L298N motor driver module. You can find the datasheet for the L298N chip at https://www.st.com/resource/en/datasheet/l298.pdf.
  You can purchase the L298N module on Amazon at https://www.amazon.com/L298N-Controller-Stepper-Driver-Module/dp/B014KMHSW6.

  Wiring:
  -------
  Connect the following pins on the L298N module to the corresponding pins on your Arduino board:
    ENA: Connect to a PWM-enabled pin on the Arduino (e.g. pin 5)
    IN1: Connect to a digital pin on the Arduino (e.g. pin 6)
    IN2: Connect to a digital pin on the Arduino (e.g. pin 7)
*/

#include <FablabL298Driver.h>

// Motor pins
const uint8_t ENA_PIN = 5;
const uint8_t IN1_PIN = 6;
const uint8_t IN2_PIN = 7;

// Create a new instance of the Motor class
FablabL298Driver motor(ENA_PIN, IN1_PIN, IN2_PIN);

void setup() {

  // Initialize the motor
  motor.begin();

  // Set the minimum and maximum speeds
  motor.setMin(50);
  motor.setMax(200);

}

void loop() {

  // Move the motor forward at different speeds
  motor.forward();

  // Start at minimum speed and gradually increase to maximum speed
  for (int i = 1; i <= 100; i++) {
    motor.goPercentage(i);
    delay(50);
  }

  // Move the motor backward at different speeds
  motor.backward();
  for (int i = 100; i >= 1; i--) {
    motor.goPercentage(i);
    delay(50);
  }

  // Stop the motor for 1 second
  motor.stop();
  delay(1000);

}