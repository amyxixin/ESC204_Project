//motor connections
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

//encoder connections
#define EncL1 18  //left motor
#define EncL2 40
#define EncT1 19  //top motor
#define EncT2 41
#define EncR1 20  //right motor
#define EncR2 42
#define EncB1 21  //bottom motor
#define EncB2 43

char val = 0;
int normalSpeed = 255;

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
}

void loop() {
  if (Serial.available()){
    val = Serial.read();
    Serial.println(val);
    if (val == 'w'){
      setPosY();
      moveY();
    } else if (val == 'a'){
      setNegX();
      moveX();
    } else if (val == 's'){
      setNegY();
      moveY();
    } else if (val == 'd'){
      setPosX();
      moveX();
    } else if (val == 'c'){
      setCW();
      turn();
    } else if (val == 'v') {
      setCCW();
      turn();
    } else if (val == 'k'){
      stopMotors();
    }
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

void setCW() {
  digitalWrite(InA1, LOW);
  digitalWrite(InA2, HIGH);
  digitalWrite(InA3, HIGH);
  digitalWrite(InA4, LOW);
  digitalWrite(InB1, LOW);
  digitalWrite(InB2, HIGH);
  digitalWrite(InB3, LOW);
  digitalWrite(InB4, HIGH);
}

void setCCW() {
  digitalWrite(InA1, HIGH);
  digitalWrite(InA2, LOW);
  digitalWrite(InA3, LOW);
  digitalWrite(InA4, HIGH);
  digitalWrite(InB1, HIGH);
  digitalWrite(InB2, LOW);
  digitalWrite(InB3, HIGH);
  digitalWrite(InB4, LOW);
}

void setPosY(){
  //towards charging port
  digitalWrite(InA1, LOW);
  digitalWrite(InA2, HIGH);
  digitalWrite(InA3, LOW);
  digitalWrite(InA4, HIGH);
}

void setNegY(){
  //away from charging port
  digitalWrite(InA1, HIGH);
  digitalWrite(InA2, LOW);
  digitalWrite(InA3, HIGH);
  digitalWrite(InA4, LOW);
}

void setPosX(){
  //right
  digitalWrite(InB1, LOW);
  digitalWrite(InB2, HIGH);
  digitalWrite(InB3, HIGH);
  digitalWrite(InB4, LOW);
}

void setNegX(){
  //left
  digitalWrite(InB1, HIGH);
  digitalWrite(InB2, LOW);
  digitalWrite(InB3, LOW);
  digitalWrite(InB4, HIGH);
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

void turn() {
  analogWrite(EnA, normalSpeed);
  analogWrite(EnB, normalSpeed);
  analogWrite(EnC, normalSpeed);
  analogWrite(EnD, normalSpeed);
}
