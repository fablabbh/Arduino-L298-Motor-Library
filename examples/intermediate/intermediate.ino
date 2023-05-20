/*
  Motor Control with Minimum and Maximum Speeds
  ---------------------------------------------
  This example shows how to set the minimum and maximum speeds of the motor using the setMin() and setMax() methods. The motor will move forward and backward at different speeds within the set limits.

  Here You Will Fin the Datasheet Of The Chip
  -------------------------------------------
  L298 Datasheet        : https://www.st.com/resource/en/datasheet/l298.pdf

  Here You Will Find The Module From Amazone
  ------------------------------------------
  L298 Module On Amazon : https://www.amazon.com/L298N-Controller-Stepper-Driver-Module/dp/B014KMHSW6

  You Are Always Welcome To Reach Out To US Via
  ---------------------------------------------
  Link Tree             : https://linktr.ee/fablabbh
  You will fin all our lin above website, socialmedia etc.
*/

#include <FABLAB_L298_Driver.h>

// Motor pins
const uint8_t ENA_PIN = 5;
const uint8_t IN1_PIN = 6;
const uint8_t IN2_PIN = 7;

// Create a new instance of the Motor class
FABLAB_L298_Driver motor(ENA_PIN, IN1_PIN, IN2_PIN);

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