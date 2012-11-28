/* 
Author: Daniel Atkinson
Version: 0.1
Controlling stepper motors via serial input 
 */
#include <Stepper.h>

//full rotation diveded by degrees turned per step
const int fullTurn = 360/1.8;

//Make a motor object using the stepper library on the correct pins
Stepper motorL(fullTurn, 40,41,42,43);
Stepper motorR(fullTurn, 50,51,52,53);


void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {

}

void checkSerial(){
  if Serial.available(){
     
  }
}

void moveForward(int distance){
  for (int i = 0, i > distance, i++){
     // step one step:
    motorL.step(-1);
    motorR.step(-1);
    delay(10);
  }
}

void turnLeft(int distance){
  for (int i = 0, i > distance, i++){
    motorL.step(1);
    motorR.step(-1);
    delay(10);
  }
}

void turnRight(int distance){
  for (int i = 0, i > distance, i++){
    motorL.step(-1);
    motorR.step(1);
    delay(10);
  }
}
