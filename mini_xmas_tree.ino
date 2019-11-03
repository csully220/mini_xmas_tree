/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN takes care
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
 
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 
  modified 2 Sep 2016
  by Arturo Guadalupi
*/

#define PRESTAGE 10
#define STAGE 11
#define YEL1 4
#define YEL2 5
#define YEL3 6
#define GRN 7
#define RED 8

#define ACTIVATE 2


bool start_seq = false;

// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(PRESTAGE, OUTPUT);
  pinMode(STAGE, OUTPUT);
  pinMode(YEL1, OUTPUT);
  pinMode(YEL2, OUTPUT);
  pinMode(YEL3, OUTPUT);
  pinMode(GRN, OUTPUT);

  pinMode(ACTIVATE, INPUT_PULLUP);

 while(1) {
    digitalWrite(PRESTAGE, HIGH);
    digitalWrite(STAGE, HIGH);
    delay(2000);
    digitalWrite(PRESTAGE, LOW);
    digitalWrite(STAGE, LOW);
    delay(2000);
  }

  
  for(int i=0; i < 3; i++) {
    digitalWrite(PRESTAGE, HIGH);
    digitalWrite(STAGE, HIGH);
    delay(1000);
    digitalWrite(PRESTAGE, LOW);
    digitalWrite(STAGE, LOW);
    delay(500);
  }
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PRESTAGE, LOW);
  digitalWrite(STAGE, LOW);
  digitalWrite(YEL1, LOW);
  digitalWrite(YEL2, LOW);
  digitalWrite(YEL3, LOW);
  digitalWrite(GRN, LOW);
  
  start_seq = digitalRead(ACTIVATE);
  if (start_seq) {
    digitalWrite(PRESTAGE, HIGH);
    delay(2000);
    digitalWrite(STAGE, HIGH);
    delay(490);
    digitalWrite(YEL1, HIGH);
    delay(490);
    digitalWrite(YEL1, LOW);
    digitalWrite(YEL2, HIGH);
    delay(490);
    digitalWrite(YEL2, LOW);
    digitalWrite(YEL3, HIGH);
    delay(490);
    digitalWrite(YEL3, LOW);
    digitalWrite(GRN, HIGH);
    delay(5000); 
  }
}
