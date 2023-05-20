/*
    Motor Control Using Serial Input
    --------------------------------
    This example shows how to control a motor using serial input. The user can enter a PWM value between 0 and 255 to control the speed and direction of the motor.
*/

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

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Command the motor using serial input
  motor.command(Serial);
}