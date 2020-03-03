/*
	Controller.h - This library provides an interface to control the robot's
	motion. Integrate it with WiFi/Bluetooth for full control.
*/

#ifndef ChargeEController_h
#define ChargEController_h

#include "Arduino.h"


//motor connections
#define EnA 2
#define EnB 3
#define EnC 4
#define EnD 5

//forward and back
#define InA1 22
#define InA2 23
#define InA3 24
#define InA4 25

//left and right
#define InB1 30
#define InB2 31
#define InB3 32
#define InB4 33

//encoder connections
#define EncL1 18  //left motor
#define EncL2 40
#define EncT1 19  //top motor
#define EncT2 41
#define EncR1 20  //right motor
#define EncR2 42
#define EncB1 21  //bottom motor
#define EncB2 43

class ChargEController {
	private:
		int _xspeed = 255;
		int _yspeed = 255;
		int _turnspeed = 255;

		//set the motor directions in each axis of motion
		void setPositiveY();
		void setNegativeY();
		void setPositiveX();
		void setNegativeX();
		void setCW();
		void setCCW();

		//move along the current set X or Y direction
		void moveX();
		void moveY();

		//rotate
		void rotate();

		//set lead screw direction
		void setPositiveZ();
		void setNegativeZ();

		//move lead screw
		void moveZ();

	public:

		//set speed and input modes
		ChargEController(int xspeed, int yspeed, int turnspeed);

		//move in direction
		void moveForward();
		void moveBack();
		void moveLeft();
		void moveRight();

		//rotate
		void rotateCW();
		void rotateCCW();

		//stop
		void stop();

		//move lead screw in direction
		void moveUp();
		void moveDown();

		void stopZ();
}
#endif