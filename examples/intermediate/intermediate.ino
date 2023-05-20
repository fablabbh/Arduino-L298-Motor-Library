/*
  Motor Control with Minimum and Maximum Speeds
  ---------------------------------------------
  This example shows how to set the minimum and maximum speeds of the motor using the setMin() and setMax() methods. The motor will move forward and backward at different speeds within the set limits.
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