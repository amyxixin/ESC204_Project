/*
	Controller.h - This library provides an interface to control the robot's
	motion. Integrate it with WiFi/Bluetooth for full control.
*/

#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

#define EnA 2
#define EnB 3
#define EnC 4
#define EnD 5

#define InA1 22
#define InA2 23
#define InA3 24
#define InA4 25

#define InB1 30
#define InB2 31
#define InB3 32
#define InB4 33

class Controller {
	private:
		int _speed;

		//set the motor directions in each axis of motion
		void setPositiveY();
		void setNegativeY();
		void setPositiveX();
		void setNegativeX();

		//move along the current set X or Y direction
		void moveX();
		void moveY();

	public:

		//set speed and input modes
		void init(int speed);

		//move in direction
		void moveForward();
		void moveBack();
		void moveLeft();
		void moveRight();

		//stop
		void stop();
};

#endif