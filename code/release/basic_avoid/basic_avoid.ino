/*
Author: Daniel Atkinson
Version: 1
Controlling stepper motors based on sonar sensor readings
*/
#include <Stepper.h>

#define sonar1TrigPin 8
#define sonar1EchoPin 7
#define sonar2TrigPin 6
#define sonar2EchoPin 5

//full rotation diveded by degrees turned per step
const int fullTurn = 360/1.8;
//initialise serial variable
int incomingData = 0;

//Make a motor object using the stepper library on the correct pins
Stepper motorL(fullTurn, 40,41,42,43);
Stepper motorR(fullTurn, 50,51,52,53);

//Global variables
int leftSonar, rightSonar;

//Magic numbers
int arbritraryMovement = 100;
int proximityThreshold = 20;

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
  moveForward(arbritraryMovement);
  detectProximity();
}


void moveForward(int distance){
  Serial.println("Moving Forward");
  for (int i = 0; i < distance; i++){
    // step one step:
    motorL.step(-1);
    motorR.step(-1);
    //delay is required for some reason - !to be tested more!
    delay(10);
  }
}

void moveBackward(int distance){
  for (int i = 0; i < distance; i++){
    motorL.step(1);
    motorR.step(1);
    delay(10);
  }
}

void turnLeft(int distance){
  Serial.println("Turning Left");
  for (int i = 0; i < distance; i++){
    motorL.step(1);
    motorR.step(-1);
    delay(10);
  }
}

void turnRight(int distance){
  Serial.println("Turning Right");
  for (int i = 0; i < distance; i++){
    motorL.step(-1);
    motorR.step(1);
    delay(10);
  }
}

int getSonarReading(int trigger, int echo){
  int duration, distance;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
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

