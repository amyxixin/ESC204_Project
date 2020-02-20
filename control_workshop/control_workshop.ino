#define ENCODER_A 2
#define ENCODER_B 12
#define ENCODER_C 3
#define ENCODER_D 8

#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

volatile long CountA = 0;
volatile long CountB = 0;
int speedA = 100;
int speedB = 100;

void setup() {
  pinMode(ENCODER_A, INPUT);
  pinMode(ENCODER_B, INPUT);
  pinMode(ENCODER_C, INPUT);
  pinMode(ENCODER_D, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENCODER_A), EncoderEventA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_C), EncoderEventB, CHANGE);

  Serial.begin(9600);
}

void loop() {
  regulateMotorSpeed();
  Serial.println("Motor A: " + String(CountA) + "...... Motor B: " + String(CountB));
  //delay(50);
}

void EncoderEventA() {
  if (digitalRead(ENCODER_A) == HIGH) {
    if (digitalRead(ENCODER_B) == LOW) {
      CountA++;
    } 
    else {
      CountA--;
    }
  } 
  else {
    if (digitalRead(ENCODER_B) == LOW) {
      CountA--;
    }
  }
}

void EncoderEventB() {
  if (digitalRead(ENCODER_C) == HIGH) {
  if (digitalRead(ENCODER_D) == LOW) {
      CountB--;
    } 
    else {
      CountB++;
    }
  } 
  else {
    if (digitalRead(ENCODER_D) == LOW) {
      CountB++;
    }
  }
}

//keep motor speed the same
void regulateMotorSpeed() {
  
  if (CountA > CountB) {
    speedA -= 5;
    speedB += 5;
  }

  else if (CountB < CountA) {
    speedB -= 5;
    speedA += 5;
  }

  if((CountA > 1100) && (CountB > 2300)) {//1250,2450
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
  else {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, speedA);
    analogWrite(enB, speedB);
  }
  delay(100);
}
