/*
	Motor - a small library for Arduino to handle motor control using L298 HBridge
	
	MIT licensed.
*/

#include "FablabL298Driver.h"
#include <Arduino.h>

// Constructor With Parameter
FablabL298Driver::FABLAB_L298_Driver(uint8_t enable, uint8_t in1, uint8_t in2) {
	_ena_pin  = enable;
	_in1_pin  = in1;
	_in2_pin  = in2;
}

// Set The Starting Parameters
void FablabL298Driver::begin() {
	pinMode(_ena_pin, OUTPUT);
	pinMode(_in1_pin, OUTPUT);
	pinMode(_in2_pin, OUTPUT);
	digitalWrite(_ena_pin, LOW);
	digitalWrite(_in1_pin, LOW);
	digitalWrite(_in2_pin, LOW);
	_speed  = 255;
}

// To Check The Value Before Writing To the Motor
void FablabL298Driver::checkWrite(uint8_t value) {
	if(_speed != value) {
		_speed = value;
		analogWrite(_ena_pin, _speed);
	}
}

// Set Minimum Speed
void FablabL298Driver::setMin(uint8_t value) {
	_min_speed = value;
}

// Set Maximum Speed
void FablabL298Driver::setMax(uint8_t value) {
	_max_speed = value;
}

// Invert Motor Direction
void FablabL298Driver::invert() {
	_invert = !_invert;
}

// Move Forword
void FablabL298Driver::forward() {
	if(_invert == false) {
		digitalWrite(_in1_pin, LOW);
		digitalWrite(_in2_pin, HIGH);
	} else {
		digitalWrite(_in1_pin, HIGH);
		digitalWrite(_in2_pin, LOW);
	}
}

// Move Backword
void FablabL298Driver::backward() {
	if(_invert == false) {
		digitalWrite(_in1_pin, HIGH);
		digitalWrite(_in2_pin, LOW);
	} else {
		digitalWrite(_in1_pin, LOW);
		digitalWrite(_in2_pin, HIGH);
	}
}

// Motor Speed
void FablabL298Driver::goMin() {
	checkWrite(_min_speed);
}

// Motor Speed
void FablabL298Driver::goMax() {
	checkWrite(_max_speed);
}

// Motor Speed
void FablabL298Driver::goSpeed(uint8_t speed) {
	// Make Sure You Are Between The Limits
	speed = constrain(speed, _min_speed, _max_speed);
	// Analog 
	checkWrite(speed);
}

// Motor Speed
void FablabL298Driver::goPercentage(uint8_t percentage) {
	// Stop The Motor
	if(percentage == 0) {
		// Stops the Motor
		checkWrite(0);
	}
	// Make Sure You Are Between The Limits
	percentage = map(percentage, 1, 100, _min_speed, _max_speed);
	// Analog 
	checkWrite(percentage);
}

// Motor Speed
void FablabL298Driver::goOverride(uint8_t value) {
	// Stop The Motor
	analogWrite(_ena_pin, value);
}

// Press Break
void FablabL298Driver::stop() {
	checkWrite(0);
}

// Command By Serial
unsigned int FablabL298Driver::command(Stream &serial) {

	// Data Buffer
	unsigned int lastTriedValue = 0;

	// Continous Loop
	while(1) {

		// Print A Message
		serial.print("Please Enter Your PWM Value : ");

		// Wait For User Input
		while(!serial.available()) {}

		// Read The Value Convert To Number
		if(serial.available()) {
			String x = serial.readStringUntil('\n');
			while(serial.available()) {
				serial.read();
			}
			serial.println();
			x.trim();
			if(x == "EXIT" || x == "Exit" || x == "exit") {
				serial.println("Exiting Command Function");
				stop();
				return lastTriedValue;
			} else {
				lastTriedValue = x.toInt();
				serial.println(lastTriedValue);
				goSpeed(lastTriedValue);
			}
		}

	}

}