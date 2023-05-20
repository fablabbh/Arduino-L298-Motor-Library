/*
  Motor Control Using Serial Input
  --------------------------------
  This example shows how to control a motor using serial input. The user can enter a PWM value between 0 and 255 to control the speed and direction of the motor.

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

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Command the motor using serial input
  motor.command(Serial);
}