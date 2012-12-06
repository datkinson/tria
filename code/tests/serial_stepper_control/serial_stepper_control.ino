/*
Author: Daniel Atkinson
 Version: 0.2
 Controlling stepper motors via serial input
 */
#include <Stepper.h>

//full rotation diveded by degrees turned per step
const int fullTurn = 360/1.8;
//initialise serial variable
int incomingData = 0;

//Make a motor object using the stepper library on the correct pins
Stepper motorL(fullTurn, 40,41,42,43);
Stepper motorR(fullTurn, 50,51,52,53);

//Magic numbers
int arbritraryMovement = 30;

void setup() {
  // initialize the serial port:
  Serial.begin(57600);
}

void loop() {
  checkSerial();

}

void checkSerial(){
  if (Serial.available() > 0){
    incomingData = Serial.read();
    //Switch case to determine what to do with the serial data
    switch (incomingData){
    case 'f':
      Serial.println("Moving forward");
      moveForward(arbritraryMovement);
      break;
    case 'l':
      Serial.println("Turning left");
      turnLeft(arbritraryMovement);
      break;
    case 'r':
      Serial.println("Turning right");
      turnRight(arbritraryMovement);
      break;
    case 't':
      Serial.println("Testing");
      test();
      break;
    }
  }
}

void moveForward(int distance){
  for (int i = 0; i < distance; i++){
    // step one step:
    motorL.step(-1);
    motorR.step(-1);
    delay(10);
  }
}

void turnLeft(int distance){
  for (int i = 0; i < distance; i++){
    motorL.step(1);
    motorR.step(-1);
    delay(10);
  }
}

void turnRight(int distance){
  for (int i = 0; i < distance; i++){
    motorL.step(-1);
    motorR.step(1);
    delay(10);
  }
}

void test(){
  motorL.step(-100);
  motorR.step(-100);
  delay(20);
}

