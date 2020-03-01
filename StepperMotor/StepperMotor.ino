int stepPin = 3;
int dirPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin, HIGH);

//  if (Serial.available() > 0) {  
//    int integerValue = 0;        
//    while(1) {           
//      char incomingByte = Serial.read();
//      if (incomingByte == '\n') break;   
//      if (incomingByte == -1) continue;  
//      integerValue *= 10;  
//      integerValue = ((incomingByte - 48) + integerValue);
//      Serial.println(String(integerValue));
//      if(integerValue > 0 && integerValue < 500){
//        raiseLeadScrew(integerValue);
//      }
//    }
//  }
//  
//  delay(10);

  raiseLeadScrew(100);
  delay(1000);
}

void raiseLeadScrew(int d) {
  const int p = 1000;

  int numTurns = floor(d * (200/8));
  
  for(int x = 0; x < numTurns; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(p);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(p);
  }
}
