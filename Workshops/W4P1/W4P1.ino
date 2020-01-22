#define ENCODER_A 2 
#define ENCODER_B 8
//#define ENCODER_C 3
//#define ENCODER_D 11
#define POT A0
#define EnA 9
#define EnB 10
#define In1 4
#define In2 5
#define In3 6
#define In4 7

volatile long CountA = 0;
volatile long CountB = 0;
int normalSpeed = 30;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENCODER_A, INPUT); 
  pinMode(ENCODER_B, INPUT); // initialize hardware interrupts 
//  pinMode(ENCODER_C, INPUT);
 // pinMode(ENCODER_D, INPUT);
  pinMode(POT, INPUT); 
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), EncoderEvent, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(ENCODER_C), EncoderEvent, CHANGE);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Serial.println("CountA: " +String(CountA) );
  //+ " CountB: " +String(CountB)); 
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, normalSpeed);
  analogWrite(EnB, normalSpeed);
  delay(1000);
  analogWrite(EnA, 0);
  analogWrite(EnB, 0);
  delay(1000);
  //normalSpeed += 50;
}

void EncoderEvent() { 
  if (digitalRead(ENCODER_A)==HIGH) {
    if (digitalRead(ENCODER_B) == LOW ) { 
      CountA--; 
    } else { 
      CountA++; 
    }
  } else { 
    if (digitalRead(ENCODER_B) == LOW) { 
      CountA++;
      //Serial.println("Stop2");
    } else { 
      //Serial.println("Backward");
      CountA--; 
    }
  }
  Serial.println("CountA: " +String(CountA) );

//  if (digitalRead(ENCODER_C)==HIGH) {
//    if (digitalRead(ENCODER_D) == LOW ) { 
//      CountB++; 
//    } else{ 
//      //CountB--; 
//    }
//  } else { 
//    if (digitalRead(ENCODER_D) == LOW) { 
//      //CountB--;
//    } else { 
//      CountB++; }
//  }
}
