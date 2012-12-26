/*
Author: Daniel Atkinson
Version: 1.1
Controlling stepper motors based on sonar sensor readings in a reactive way
*/
#include <Stepper.h>
#define sonar1TrigPin 8
#define sonar1EchoPin 7
#define sonar2TrigPin 6
#define sonar2EchoPin 5

//initialise serial variable
int incomingData = 0;

//Global variables
int leftSonar, rightSonar;

//Magic Numbers
int arbritraryMovement = 50;
int motorDelay = 1000;
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
}

void loop() {
  detectProximity();
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
//full rotation diveded by degrees turned per step
const int fullTurn = 360/1.8;
//Make a motor object using the stepper library on the correct pins
Stepper motorL(fullTurn, 40,41,42,43);
Stepper motorR(fullTurn, 50,51,52,53);

void moveForward(int distance){
  Serial.println("Moving Forward");
  for (int i = 0; i < distance; i++){
    // step one step:
    motorL.step(-1);
    motorR.step(-1);
    //delay is required for some reason - !to be tested more!
    delay(defaultDelay);
  }
}

void moveBackward(int distance){
  for (int i = 0; i < distance; i++){
    motorL.step(1);
    motorR.step(1);
    delay(defaultDelay);
  }
}

void turnLeft(int distance){
  Serial.println("Turning Left");
  for (int i = 0; i < distance; i++){
    motorL.step(1);
    motorR.step(-1);
    delay(defaultDelay);
  }
}

void turnRight(int distance){
  Serial.println("Turning Right");
  for (int i = 0; i < distance; i++){
    motorL.step(-1);
    motorR.step(1);
    delay(defaultDelay);
  }
}

//Magic numbers
int sonarLower = 0;
int sonarUpper = 400;

int getSonarReading(int trigger, int echo){
  int duration, distance;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(motorDelay);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  return(distance);
}

void detectProximity(){
  leftSonar = getSonarReading(sonar1TrigPin, sonar1EchoPin);
  rightSonar = getSonarReading(sonar2TrigPin, sonar2EchoPin);
  Serial.print("Left: ");
  Serial.print(leftSonar);
  Serial.print(" - Right: ");
  Serial.println(rightSonar);
  if (leftSonar < proximityThreshold){
    turnRight(arbritraryMovement);
  }
  if (rightSonar < proximityThreshold){
    turnLeft(arbritraryMovement);
  }
}
bool validateSonar(){
  if(leftSonar < sonarUpper && leftSonar > sonarLower){
    if(rightSonar < sonarUpper && rightSonar > sonarLower){
      return true;
    }else{
      return false;
    }
  }
}
