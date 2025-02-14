unsigned long currentTime = 0;
int potentiometerPin = A1; 
const int ledPins[] = {8, 9, 10, 11};
const int buttonPin = 2;
int buttonState = 0;
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

void barre_progress(){
  potentiometerValue = analogRead(potentiometerPin);
  mappedIndex = map (potentiometerValue, 0, 1023, 0, 20);

  for (int i = 0; i < 20; i++){
    if(mappedIndex <= 5){
        switch(mappedIndex){
          case 0:
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[....................] 0%");  
          } 
          break;
          case 1 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[#...................] 5%");  
          } 
          break;
          case 2 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[##..................] 10%"); 
          } 
          break;
          case 3 :          
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[###.................] 15%");
          } 
          break;
          case 4 :
           if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[####................] 20%");
          } 
          break;
          case 5 :
           if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[#####...............] 25%");
          } 
          break;
        }
    }else if(mappedIndex <= 10){
        switch(mappedIndex){
          case 6 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[######..............] 30%");
          } 
          break;
          case 7 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[#######.............] 35%");
          } 
          break;
          case 8 : 
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[########............] 40%");
          } 
          break;
          case 9 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[#########...........] 45%");
          }
          break;
          case 10 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[##########..........] 50%");
          }
          break;
        }
    }else if(mappedIndex <=15){
        switch(mappedIndex){
          case 11 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[###########.........] 55%");
          }
          break;
          case 12 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[############........] 60%");
          }
          break;
          case 13 :        
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[#############.......] 65%");
          }
          break;
          case 14 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[##############......] 70%");
          }
          break;
          case 15 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[###############.....] 75%");
          }
          break;
        }
    }else {
        switch(mappedIndex){
          case 16 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[################....] 80%");
          }
          break;
          case 17 :          
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[#################...] 85%");
          }
          break;
          case 18 :         
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[##################..] 90%");
          }
          break;
          case 19 :          
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[###################.] 95%");
          }
          break;
          case 20 :
          if (currentTime - serialPrevious >= serialDelay) {
            serialPrevious = currentTime;
            Serial.println("[####################] 100%");
          }
          break;
      }
    }
  }
  
}

void LEDs(){
  potentiometerValue = analogRead(potentiometerPin);
  mappedIndex = map (potentiometerValue, 0, 1023, 0, 20); 
  
  if(mappedIndex < 5){
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
  }else if(mappedIndex < 10){
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
  }else if(mappedIndex < 15){
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], LOW);
  }else {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH);
  } 
}

void button(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
   barre_progress();
  }
}

void loop() {
  currentTime = millis();
 button();
  LEDs();
}
