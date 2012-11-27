/* 
Author: Daniel Atkinson
Version: 0.1
Testing a single stepper motor 
 */
#include <Stepper.h>

//full rotation diveded by degrees turned per step
const int fullTurn = 360/1.8;

//Make a motor object using the stepper library on the correct pins
Stepper motor(fullTurn, 50,51,52,53);            

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one step:
  motor.step(1);
  //Could delay here but it waits to finish the steps anyway so no need
  //delay(10);
}

