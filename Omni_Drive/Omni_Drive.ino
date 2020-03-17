#include <PIDController.h>

volatile long int left_encoder_pos = 0;
volatile long int right_encoder_pos = 0;
volatile long int top_encoder_pos = 0;
volatile long int bottom_encoder_pos = 0;

PIDController pos_pid_left;
PIDController pos_pid_right;
PIDController pos_pid_top;
PIDController pos_pid_bottom;

unsigned int integerValue=0;  // Max value is 65535
char incomingByte;

//motor garbage
#define EnA 2
#define EnB 3
#define EnC 4
#define EnD 5

//top and bottom
#define InB1 30
#define InB2 31
#define InB3 32
#define InB4 33

//left and right
#define InA1 22
#define InA2 23
#define InA3 24
#define InA4 25

//encoder garbage
#define EncL1 18  //left motor
#define EncL2 40
#define EncT1 19  //top motor
#define EncT2 41
#define EncR1 20  //right motor
#define EncR2 42
#define EncB1 21  //bottom motor
#define EncB2 43

int leftSpeed = 255;
int rightSpeed = 255;
int topSpeed = 255;
int bottomSpeed = 255;

int wait = 1000;
int normalSpeed = 255;
int distance = 100;

void setup() {
  Serial.begin(9600);
  Serial.println("starting...");

  //initializing motors
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

  //initializing encoders
  pinMode(EncL1, INPUT);
  pinMode(EncL2, INPUT);
  
  pinMode(EncT1, INPUT);
  pinMode(EncT2, INPUT);
  
  pinMode(EncR1, INPUT);
  pinMode(EncR2, INPUT);
  
  pinMode(EncB1, INPUT);
  pinMode(EncB2, INPUT);

  attachInterrupt(digitalPinToInterrupt(EncL1), encCountL, RISING);
  attachInterrupt(digitalPinToInterrupt(EncT1), encCountT, RISING);
  attachInterrupt(digitalPinToInterrupt(EncR1), encCountR, RISING);
  attachInterrupt(digitalPinToInterrupt(EncB1), encCountB, RISING);

  pos_pid_left.begin();
  pos_pid_left.tune(100, 0, 2000);
  pos_pid_left.limit(-255, 255);

  pos_pid_right.begin();
  pos_pid_right.tune(100, 0, 2000);
  pos_pid_right.limit(-255, 255);

  pos_pid_top.begin();
  pos_pid_top.tune(100, 0, 2000);
  pos_pid_top.limit(-255, 255);

  pos_pid_bottom.begin();
  pos_pid_bottom.tune(100, 0, 2000);
  pos_pid_bottom.limit(-255, 255);
}

void loop() {
  //  This allows user to enter n number of encoder counts they want the robot to drive til
  //  We were going to convert this to distance in mm but didn't have the time
  
  // this is an example for top and bottom motors which control left and right movement
  // the same can be done for right and left motors
  
  if (Serial.available() > 0) {  
    integerValue = 0;        
    while(1) {           
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   
      if (incomingByte == -1) continue;  
      integerValue *= 10;  
      integerValue = ((incomingByte - 48) + integerValue);
      pos_pid_top.setpoint(integerValue);
      pos_pid_bottom.setpoint(integerValue);
    }
  }

  pos_pid_top.setpoint(integerValue);
  pos_pid_bottom.setpoint(integerValue);
  setPidsX();
  
  delay(10);
}

void setPidsY() {
  leftSpeed = pos_pid_left.compute(left_encoder_pos);
  rightSpeed = pos_pid_right.compute(right_encoder_pos);

  float avgYSpeed = (leftSpeed + rightSpeed)/2;

  if(avgYSpeed > 0) {
    setPosY();
    setSpeedY(avgYSpeed);
  }else{
    setNegY();
    setSpeedY(abs(avgYSpeed));
  }
  
  Serial.println(String(left_encoder_pos) + "   " + String(right_encoder_pos));
}

void setPidsX() {
  topSpeed = pos_pid_top.compute(top_encoder_pos);
  bottomSpeed = pos_pid_bottom.compute(bottom_encoder_pos);

  float avgXSpeed = (topSpeed + bottomSpeed)/2;

  if(avgXSpeed > 0) {
    setPosX();
    setSpeedX(avgXSpeed);
  }else{
    setNegX();
    setSpeedX(abs(avgXSpeed));
  }
  
  Serial.println(String(top_encoder_pos) + "   " + String(bottom_encoder_pos));
}

void encCountL(){
  if(digitalRead(EncL2) == HIGH){
    left_encoder_pos++;
  }else{
    left_encoder_pos--;
  }
}

void encCountR(){
  if(digitalRead(EncR2) == HIGH){
    right_encoder_pos++;
  }else{
    right_encoder_pos--;
  }
}

void encCountT(){
  if(digitalRead(EncT2) == HIGH){
    top_encoder_pos++;
  }else{
    top_encoder_pos--;
  }
}

void encCountB(){
  if(digitalRead(EncB2) == HIGH){
    bottom_encoder_pos++;
  }else{
    bottom_encoder_pos--;
  }
}

void setSpeedY(int power){
  if(power > 100){
    analogWrite(EnA, power);
    analogWrite(EnB, power);
  }else{
    digitalWrite(EnA, LOW);
    digitalWrite(EnB, LOW);
  }
}

void setSpeedX(int power){
  if(power > 100){
    analogWrite(EnC, power);
    analogWrite(EnD, power);
  }else{
    digitalWrite(EnC, LOW);
    digitalWrite(EnD, LOW);
  }
}

void setPosY(){
  //towards charging port
  digitalWrite(InA1, LOW);
  digitalWrite(InA2, HIGH);
  digitalWrite(InA3, HIGH);
  digitalWrite(InA4, LOW);
}

void setNegY(){
  //away from charging port
  digitalWrite(InA1, HIGH);
  digitalWrite(InA2, LOW);
  digitalWrite(InA3, LOW);
  digitalWrite(InA4, HIGH);
}

void setPosX(){
  //right
  digitalWrite(InB1, LOW);
  digitalWrite(InB2, HIGH);
  digitalWrite(InB3, LOW);
  digitalWrite(InB4, HIGH);
}

void setNegX(){
  //left
  digitalWrite(InB1, HIGH);
  digitalWrite(InB2, LOW);
  digitalWrite(InB3, HIGH);
  digitalWrite(InB4, LOW);
}

void stopMotors(){
  digitalWrite(InA1, LOW);
  digitalWrite(InA2, LOW);
  digitalWrite(InA3, LOW);
  digitalWrite(InA4, LOW);
  
  digitalWrite(InB1, LOW);
  digitalWrite(InB2, LOW);
  digitalWrite(InB3, LOW);
  digitalWrite(InB4, LOW);
}
