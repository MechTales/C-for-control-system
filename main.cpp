int StepX = 2; 
int DirX = 5; 
int LimitSwitch1 = 11; 
int LimitSwitch2 = A0;
int HallSensor = 10;
float speedMultiplier = 2; 
int buttonPin1 = 9;  
int buttonPin2 = A3;  
void setup() { 
pinMode(StepX, OUTPUT); 
pinMode(DirX, OUTPUT); 
pinMode(LimitSwitch1, INPUT_PULLUP);
pinMode(LimitSwitch2, INPUT_PULLUP); 
pinMode(HallSensor, INPUT_PULLUP); 
pinMode(buttonPin1, INPUT_PULLUP); 
pinMode(buttonPin2, INPUT_PULLUP); 
}
 
void loop() { 
  if (digitalRead(buttonPin1) == LOW || digitalRead(buttonPin2) == LOW) { 
    if (digitalRead(buttonPin1) == LOW) { 
      digitalWrite(DirX, HIGH); 
    } else { 
      digitalWrite(DirX, LOW); 
    } 
 
    while (digitalRead(buttonPin1) == LOW || digitalRead(buttonPin2) == LOW) { 
      digitalWrite(StepX, HIGH); 
      delayMicroseconds(333 * speedMultiplier);
      digitalWrite(StepX, LOW); 
      delayMicroseconds(333 * speedMultiplier);
 
      if (digitalRead(HallSensor) == LOW) { 
        break; 
      }
 
      if (digitalRead(buttonPin1)== LOW && digitalRead(LimitSwitch1)== LOW){ 
        break; 
      } 
      if (digitalRead(buttonPin2)== LOW && digitalRead(LimitSwitch2)== LOW){ 
        break; 
      } 
    } 
  } 
 
  delay(100); // Small delay before checking again 
}
