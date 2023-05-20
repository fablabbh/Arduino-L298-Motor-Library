/*
	Here's an example Arduino sketch that demonstrates how to use the Motor library to control a motor
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