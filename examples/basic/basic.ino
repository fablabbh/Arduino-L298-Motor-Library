/*
  Basic Motor Control
  -------------------
	Here's an example Arduino sketch that demonstrates how to use the Motor library to control a motor

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

#include <FablabL298Driver.h>

// Motor pins
const uint8_t ENA_PIN = 5;
const uint8_t IN1_PIN = 6;
const uint8_t IN2_PIN = 7;

// Create a new instance of the Motor class
FABLAB_L298_Driver motor(ENA_PIN, IN1_PIN, IN2_PIN);

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