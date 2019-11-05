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

#define ACTIVATE 3

#define YEL1_L 4
#define YEL1_R 5
#define YEL2_L 6
#define YEL2_R 7
#define YEL3_L 8
#define YEL3_R 9
#define GRN_L A0
#define GRN_R A1

#define PRESTAGE 10
#define STAGE 11

bool start_seq = false;

// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(ACTIVATE, INPUT_PULLUP);
  pinMode(PRESTAGE, OUTPUT);
  pinMode(STAGE, OUTPUT);
  pinMode(YEL1_L, OUTPUT);
  pinMode(YEL1_R, OUTPUT);
  pinMode(YEL2_L, OUTPUT);
  pinMode(YEL2_R, OUTPUT);
  pinMode(YEL3_L, OUTPUT);
  pinMode(YEL3_R, OUTPUT);
  pinMode(GRN_L, OUTPUT);
  pinMode(GRN_R, OUTPUT);

  digitalWrite(PRESTAGE, LOW);
  digitalWrite(STAGE, LOW);
  digitalWrite(YEL1_L, LOW);
  digitalWrite(YEL1_R, LOW);
  digitalWrite(YEL2_L, LOW);
  digitalWrite(YEL2_R, LOW);
  digitalWrite(YEL3_L, LOW);
  digitalWrite(YEL3_R, LOW);
  digitalWrite(GRN_L, LOW);
  digitalWrite(GRN_R, LOW);
    
  /*for(int i=0; i < 3; i++) {
    digitalWrite(YEL1_L, HIGH);
    digitalWrite(YEL1_R, HIGH);
    delay(200);
    digitalWrite(YEL1_L, LOW);
    digitalWrite(YEL1_R, LOW);
    digitalWrite(YEL2_L, HIGH);
    digitalWrite(YEL2_R, HIGH);
    delay(200);
    digitalWrite(YEL2_L, LOW);
    digitalWrite(YEL2_R, LOW);
    digitalWrite(YEL3_L, HIGH);
    digitalWrite(YEL3_R, HIGH);
    delay(200);
    digitalWrite(YEL3_L, LOW);
    digitalWrite(YEL3_R, LOW);
  }*/
}

// the loop function runs over and over again forever
void loop() {
  
  start_seq = !digitalRead(ACTIVATE);
  if (start_seq) {
    digitalWrite(PRESTAGE, HIGH);
    delay(4000);
    digitalWrite(STAGE, HIGH);
    delay(2000);
    digitalWrite(YEL1_L, HIGH);
    digitalWrite(YEL1_R, HIGH);
    delay(500);
    digitalWrite(YEL1_L, LOW);
    digitalWrite(YEL1_R, LOW);
    digitalWrite(YEL2_L, HIGH);
    digitalWrite(YEL2_R, HIGH);
    delay(500);
    digitalWrite(YEL2_L, LOW);
    digitalWrite(YEL2_R, LOW);
    digitalWrite(YEL3_L, HIGH);
    digitalWrite(YEL3_R, HIGH);
    delay(500);
    digitalWrite(YEL3_L, LOW);
    digitalWrite(YEL3_R, LOW);
    digitalWrite(GRN_L, HIGH);
    digitalWrite(GRN_R, HIGH);
    delay(5000);
    digitalWrite(PRESTAGE, LOW);
    digitalWrite(STAGE, LOW);
    digitalWrite(GRN_L, LOW);
    digitalWrite(GRN_R, LOW);
    start_seq = false;
  }
}
