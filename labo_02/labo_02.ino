unsigned long currentTime = 0;
int potentiometerPin = A0; 
const int ledPins[] = {8, 9, 10, 11};
const int buttonPin = 2;
int potentiometerValue = 0;
int mappedIndex = 0;
unsigned long serialPrevious = 0;
int serialDelay = 500;


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
   pinMode(ledPins[i], OUTPUT); 
  }
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println("Setup completed");
}

void barre_progress(int potentiometerValue,int mappedIndex){
  for(int i = 0; i < 4; i++){
    switch(mappedIndex){
      case 0 :
        if (currentTime - serialPrevious >= serialDelay) {
          serialPrevious = currentTime;
          Serial.println("[#####...............] 25%");
        }
      break;
      case 1 :
        if (currentTime - serialPrevious >= serialDelay) {
          serialPrevious = currentTime;
          Serial.println("[##########..........] 50%");
        }
      break;
      case 2 :
        if (currentTime - serialPrevious >= serialDelay) {
          serialPrevious = currentTime;
          Serial.println("[###############.....] 75%");
        }
      break;
      case 3 :
        if (currentTime - serialPrevious >= serialDelay) {
          serialPrevious = currentTime;
          Serial.println("[####################] 100%");
        }
      break;
    }
  }
}


void LEDs(int mappedIndex,int potentiometerValue){
  switch(mappedIndex){
    case 0:
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);    
    break;
    case 1:   
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);     
    break;
    case 2:      
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], LOW);    
    break;
    case 3:   
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH); 
    break; 
  }
}

void button(){
  int buttonState = 0;
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW){
    barre_progress(potentiometerValue,mappedIndex);
  }
}


void loop() {
  potentiometerValue = analogRead(potentiometerPin);
  mappedIndex = map (potentiometerValue, 0, 1023, 0, 3);
  currentTime = millis();
  button();
  LEDs(mappedIndex,potentiometerValue);
}
