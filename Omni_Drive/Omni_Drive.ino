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

int normalSpeed = 200;
int wait = 1000;

void setup() {
  Serial.begin(9600);
  Serial.println("starting...");

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

void loop() {
  //drive forwards
  setPositiveY();
  moveY();
  delay(wait);

  stopMotors();
  delay(wait/2);

//  //drive backwards
//  setNegativeY();
//  moveY();
//  delay(wait);
//  
  //move right
//  setPositiveX();
//  moveX();
//  delay(wait);
//
//  //move left
//  setNegativeX();
//  moveX();
//  delay(wait);
//
//  stopMotors();
//  delay(wait/2);
}

void setPositiveY(){
  //towards charging port
  digitalWrite(InA1, LOW);
  digitalWrite(InA2, HIGH);
  digitalWrite(InA3, HIGH);
  digitalWrite(InA4, LOW);
}

void setNegativeY(){
  //away from charging port
  digitalWrite(InA1, HIGH);
  digitalWrite(InA2, LOW);
  digitalWrite(InA3, LOW);
  digitalWrite(InA4, HIGH);
}

void setPositiveX(){
  //right
  digitalWrite(InB1, LOW);
  digitalWrite(InB2, HIGH);
  digitalWrite(InB3, LOW);
  digitalWrite(InB4, HIGH);
}

void setNegativeX(){
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

void moveY(){
  //turn on both motors
  analogWrite(EnA, normalSpeed);
  analogWrite(EnB, normalSpeed);
  analogWrite(EnC, 0);
  analogWrite(EnD, 0);
}

void moveX(){
  //turn on both motors
  analogWrite(EnA, 0);
  analogWrite(EnB, 0);
  analogWrite(EnC, normalSpeed);
  analogWrite(EnD, normalSpeed);
}
