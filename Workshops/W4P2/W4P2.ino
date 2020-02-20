// defines pins numbers 
//int stepPin = 3; 
//int dirPin = 2;
#define In1 4
#define In2 5
#define In3 6
#define In4 7
#define EnA 9
#define EnB 10
#define POT A0

void setup() {
  // put your setup code here, to run once:
  // Sets the two pins as Outputs 
//  pinMode(stepPin,OUTPUT); 
//  pinMode(dirPin,OUTPUT); 
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(POT, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(dirPin,LOW); //enables the motor to move in particular direction
  
  int normalSpeed = analogRead(POT)*10;
  

  analogWrite(EnA, 250);
  analogWrite(EnB, 250);

  
  //makes 200 pulses for making one full cycle rotation
  int del =1000;
  for (int x = 0; x < 200; x++){
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
    
      delayMicroseconds(del);
      
      digitalWrite(In1, LOW);
      digitalWrite(In3, HIGH);
      digitalWrite(In4, HIGH);
      digitalWrite(In2, LOW);
      
      delayMicroseconds(del);
    
      digitalWrite(In3, HIGH);
      digitalWrite(In2, HIGH);
      digitalWrite(In1, LOW);
      digitalWrite(In4, LOW);
      
      delayMicroseconds(del);
      
      digitalWrite(In2, LOW);
      digitalWrite(In4, LOW);
      digitalWrite(In3, HIGH);
      digitalWrite(In1, HIGH);
//    digitalWrite(stepPin,HIGH);
//    delayMicroseconds(normalSpeed);
//    digitalWrite(stepPin,LOW);
//    delayMicroseconds(normalSpeed);
  }
  delay(1000); //one second delay
}
