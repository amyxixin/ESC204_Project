// motor
#define EnA 9
#define EnB 10
#define In1 4
#define In2 5
#define In3 6
#define In4 7
#define EncA 2
#define EncB 3

//ultrasonic sensor
int echoPin = 11;
int distance = 0;
int trigPin = 12;
int normalSpeed = 75;
int maxSpeed = 255;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello I am alive");
  
  // All motor control pins are outputs
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EncA, INPUT);
  pinMode(EncB, INPUT);

  //sensor pins
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  Serial.println("A: "+String(digitalRead(EncA)) + "B: "+String(digitalRead(EncB)));
  //Serial.println());
  //Serial.println("A-B: "+String(analogRead(EnA)-analogRead(EnB)));
//  //sensor input
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  
//  long pingTime = pulseIn (echoPin, HIGH);
//  distance = pingTime * 0.034/2;
//  Serial.println(distance);
//  if (distance <= 15){
//    turn(true);
//  }else{
//    moveForward();
//  }
}

void halt() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void initMotors(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}
void moveForward(){
  //turn on both motors
  analogWrite(EnA, normalSpeed);
  analogWrite(EnB, normalSpeed);
}

void turn(bool leftOrRight) {

  if (leftOrRight) {
    //turn right
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);

    analogWrite(EnA, normalSpeed);
    analogWrite(EnB, normalSpeed);
  }else {
    //turn left
    analogWrite(EnA, 0);
    analogWrite(EnB, maxSpeed);
  }
  
}
