#include <Controller.h>
#include <SoftwareSerial.h>

#define RX 14
#define TX 15

#define FORWARD 'w'
#define BACK 's'
#define LEFT 'a'
#define RIGHT 'd'
#define STOP 'x'

Controller controller;
const int* speed = 100;
SoftwareSerial BTSerial(RX, TX);

void setup() {
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  
  controller.init(speed);

  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    char c = BTSerial.read();

    switch(c) {
      case FORWARD: controller.moveForward(); break;
      case BACK: controller.moveBack(); break;
      case LEFT: controller.moveLeft(); break;
      case RIGHT: controller.moveRight(); break;
      case STOP: controller.stop(); break;
    }
  }
}
