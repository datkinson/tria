/*
Author: Daniel Atkinson
Version: 1.1
Controlling stepper motors based on sonar sensor readings in a reactive way
*/
#include <Stepper.h>
#define sonar1TrigPin 4
#define sonar1EchoPin 5
#define sonar2TrigPin 2
#define sonar2EchoPin 3
#define leftDirection 13
#define rightDirection 11
#define leftStep 12
#define rightStep 10


//initialise serial variable
int incomingData = 0;

//Global variables
int leftSonar, rightSonar, leftIr, rightIr, distance;

//Magic Numbers
int arbritraryMovement = 50;
int readingDelay = 20;
int proximityThreshold = 25;
int defaultDelay = 10;

void setup() {
  // initialize the serial port:
  Serial.begin(57600);
  //Set inputs and outputs of the first 2 sonar modules
  pinMode(sonar1TrigPin, OUTPUT);
  pinMode(sonar1EchoPin, INPUT);
  pinMode(sonar2TrigPin, OUTPUT);
  pinMode(sonar2EchoPin, INPUT);
  //Set motor control pins
  pinMode(leftDirection, OUTPUT); //Left direction pin
  pinMode(leftStep, OUTPUT); //Left step pin
  pinMode(rightDirection, OUTPUT); //Right direction pin
  pinMode(rightStep, OUTPUT); //Right step pin

}

void loop() {
  detectSonarProximity();
  if(validateSonar){
    reactiveSonar(leftSonar, rightSonar);
  }
}

void reactiveSonar(int left, int right){
  if(left < proximityThreshold && right < proximityThreshold){
    moveBackward(arbritraryMovement);
  }else{
    if(left < proximityThreshold){
      turnRight(arbritraryMovement);
    }else{
      if(right < proximityThreshold){
        turnLeft(arbritraryMovement);
      }else{
        moveForward(arbritraryMovement);
      }
    }
  }
}
