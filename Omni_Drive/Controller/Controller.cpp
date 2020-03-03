/*
	Controller.cpp - This library provides an interface to control the robot's
	motion. Integrate it with WiFi/Bluetooth for full control.
*/

#include "Controller.h"

void Controller::init(int speed) {
	this->_speed = speed;

	pinMode(EnA, OUTPUT);
	pinMode(EnB, OUTPUT);
	pinMode(EnC, OUTPUT);
	pinMode(EnD, OUTPUT);
  
	pinMode(InA1, OUTPUT);
	pinMode(InA2, OUTPUT);
	pinMode(InA3, OUTPUT);
	pinMode(InA4, OUTPUT);
  
	pinMode(InB1, OUTPUT);
	pinMode(InB2, OUTPUT);
	pinMode(InB3, OUTPUT);
	pinMode(InB4, OUTPUT);
}

void Controller::setPositiveY() {
	digitalWrite(InA1, LOW);
	digitalWrite(InA2, HIGH);
	digitalWrite(InA3, HIGH);
	digitalWrite(InA4, LOW);
}

void Controller::setNegativeY() {
	digitalWrite(InA1, HIGH);
	digitalWrite(InA2, LOW);
	digitalWrite(InA3, LOW);
	digitalWrite(InA4, HIGH);
}

void Controller::setPositiveX() {
	digitalWrite(InB1, LOW);
	digitalWrite(InB2, HIGH);
	digitalWrite(InB3, LOW);
	digitalWrite(InB4, HIGH);
}

void Controller::setNegativeX() {
	digitalWrite(InB1, HIGH);
	digitalWrite(InB2, LOW);
	digitalWrite(InB3, HIGH);
	digitalWrite(InB4, LOW);
}

void Controller::moveY() {
	analogWrite(EnA, _speed);
	analogWrite(EnB, _speed);
	analogWrite(EnC, 0);
	analogWrite(EnD, 0);
}

void Controller::moveX() {
	analogWrite(EnA, 0);
	analogWrite(EnB, 0);
	analogWrite(EnC, _speed);
	analogWrite(EnD, _speed);
}

void Controller::moveForward() {
	this->setPositiveY();
	this->moveY();
}

void Controller::moveBack() {
	this->setNegativeY();
	this->moveY();
}

void Controller::moveLeft() {
	this->setNegativeX();
	this->moveX();
}

void Controller::moveRight() {
	this->setPositiveX();
	this->moveX();
}

void Controller::stop() {
	digitalWrite(InA1, LOW);
	digitalWrite(InA2, LOW);
	digitalWrite(InA3, LOW);
	digitalWrite(InA4, LOW);
  
	digitalWrite(InB1, LOW);
	digitalWrite(InB2, LOW);
 	digitalWrite(InB3, LOW);
	digitalWrite(InB4, LOW);
}