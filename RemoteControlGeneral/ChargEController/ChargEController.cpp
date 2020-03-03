/*
	Controller.cpp - This library provides an interface to control the robot's
	motion. Integrate it with WiFi/Bluetooth for full control.
*/

#include "ChargEController.h"

ChargEController::ChargEController(int xspeed, int yspeed, int turnspeed) {
	this->_xspeed = xspeed;
	this->_yspeed = yspeed;
	this->_turnspeed = turnspeed;

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

void ChargEController::setPositiveY() {
	digitalWrite(InA1, LOW);
	digitalWrite(InA2, HIGH);
	digitalWrite(InA3, HIGH);
	digitalWrite(InA4, LOW);
}

void ChargEController::setNegativeY() {
	digitalWrite(InA1, HIGH);
	digitalWrite(InA2, LOW);
	digitalWrite(InA3, LOW);
	digitalWrite(InA4, HIGH);
}

void ChargEController::setPositiveX() {
	digitalWrite(InB1, LOW);
	digitalWrite(InB2, HIGH);
	digitalWrite(InB3, LOW);
	digitalWrite(InB4, HIGH);
}

void ChargEController::setNegativeX() {
	digitalWrite(InB1, HIGH);
	digitalWrite(InB2, LOW);
	digitalWrite(InB3, HIGH);
	digitalWrite(InB4, LOW);
}

void ChargEController::setCW() {
	digitalWrite(InA1, LOW);
	digitalWrite(InA2, HIGH);
	digitalWrite(InA3, HIGH);
	digitalWrite(InA4, LOW);

	digitalWrite(InB1, LOW);
	digitalWrite(InB2, HIGH);
	digitalWrite(InB3, LOW);
	digitalWrite(InB4, HIGH);

}

void ChargEController::setCCW() {
	digitalWrite(InA1, HIGH);
	digitalWrite(InA2, LOW);
	digitalWrite(InA3, LOW);
	digitalWrite(InA4, HIGH);

	digitalWrite(InB1, HIGH);
	digitalWrite(InB2, LOW);
	digitalWrite(InB3, HIGH);
	digitalWrite(InB4, LOW);
}

void ChargEController::moveY() {
	analogWrite(EnA, _yspeed);
	analogWrite(EnB, _yspeed);
	analogWrite(EnC, 0);
	analogWrite(EnD, 0);
}

void ChargEController::moveX() {
	analogWrite(EnA, 0);
	analogWrite(EnB, 0);
	analogWrite(EnC, _xspeed);
	analogWrite(EnD, _xspeed);
}

void ChargEController::rotate() {
	analogWrite(EnA, _turnspeed);
	analogWrite(EnB, _turnspeed);
	analogWrite(EnC, _turnspeed);
	analogWrite(EnD, _turnspeed);
}

void ChargEController::setPositiveZ() {

}

void ChargEController::setNegativeZ() {

}

void ChargEController::moveZ() {

}

void ChargEController::moveForward() {
	this->setPositiveY();
	this->moveY();
}

void ChargEController::moveBack() {
	this->setNegativeY();
	this->moveY();
}

void ChargEController::moveLeft() {
	this->setNegativeX();
	this->moveX();
}

void ChargEController::moveRight() {
	this->setPositiveX();
	this->moveX();
}

void ChargEController::rotateCW() {
	this->setCW();
	this->rotateCW();
}

void ChargEController::rotateCCW() {
	this->setCCW();
	this->rotateCCW();
}

void ChargEController::stop() {
	digitalWrite(InA1, LOW);
	digitalWrite(InA2, LOW);
	digitalWrite(InA3, LOW);
	digitalWrite(InA4, LOW);
  
	digitalWrite(InB1, LOW);
	digitalWrite(InB2, LOW);
 	digitalWrite(InB3, LOW);
	digitalWrite(InB4, LOW);
}

void ChargEController::moveUp() {

}

void ChargEController::moveDown() {

}

void ChargEController::stopZ() {
	
}