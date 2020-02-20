int stepPin = 3;
int dirPin = 2;
int pause = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin, LOW);

  for(int x = 0; x < 200; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pause);
  }

  delay(1000);
}
