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

#define DRT_SIG 2
#define STEP_THRU A2
#define ACTIVATE A3

#define YEL1_L 5
#define YEL1_R 5
#define YEL2_L 7
#define YEL2_R 7
#define YEL3_L 9
#define YEL3_R 9
#define GRN_L 10
#define GRN_R 10

#define PRESTAGE 12
#define STAGE 13

bool start_seq = false;
bool step_thru = false;
int lamp_row = 0;
unsigned long rt_start = 0;
bool rt_sig_rcvd = false;
// the setup function runs once when you press reset or power the board

void all_off(){
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
}

void drt_signal() {
  if(!rt_sig_rcvd) {
    Serial.println(millis() - rt_start);
  }
  rt_sig_rcvd = true;
  //Serial.write("/n");
}

void setup() {
  Serial.begin(9600);
  pinMode(DRT_SIG, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(DRT_SIG), drt_signal, LOW);
  pinMode(ACTIVATE, INPUT_PULLUP);
  pinMode(STEP_THRU, INPUT_PULLUP);
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
  rt_start = millis();
  all_off();
}

// the loop function runs over and over again forever
void loop() {
  start_seq = !digitalRead(ACTIVATE);
  if (start_seq) {
    rt_sig_rcvd = false;
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
    rt_start = millis();
    delay(5000);
    digitalWrite(PRESTAGE, LOW);
    digitalWrite(STAGE, LOW);
    digitalWrite(GRN_L, LOW);
    digitalWrite(GRN_R, LOW);
    start_seq = false;
  }
  step_thru = !digitalRead(STEP_THRU);
  while (step_thru) {
    delay(200);
    if (!digitalRead(ACTIVATE)){
      lamp_row = 0;
      all_off();
      break;
    }
    if (!digitalRead(STEP_THRU)) {

      switch (lamp_row) {
        // PRESTAGE
        case 0:
          all_off();
          digitalWrite(PRESTAGE, HIGH);
          break;
        case 1:
          all_off();
          digitalWrite(STAGE, HIGH);
          break;
        case 2:
          all_off();
          digitalWrite(YEL1_L, HIGH);
          digitalWrite(YEL1_R, HIGH);
          break;
        case 3:
          all_off();
          digitalWrite(YEL2_L, HIGH);
          digitalWrite(YEL2_R, HIGH);
          break;
        case 4:
          all_off();
          digitalWrite(YEL3_L, HIGH);
          digitalWrite(YEL3_R, HIGH);
          break;
        case 5:
          all_off();
          digitalWrite(GRN_L, HIGH);
          digitalWrite(GRN_R, HIGH);
          break;
        default:
          lamp_row = 0;
          step_thru = false;
          all_off();
          break;
      }
      lamp_row++;
    }
  }
}
