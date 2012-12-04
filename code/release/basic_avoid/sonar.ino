/*
Author: Daniel Atkinson
Version: 0.1
Title: Dual sonar test
*/
#define trigPin1 8
#define echoPin1 7
#define trigPin2 6
#define echoPin2 5

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  sonar1();
  sonar2();
  delay(500);
}
void sonar1(){
  int duration, distance;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 400 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sonar1: ");
    Serial.print(distance);
    Serial.print(" cm - ");
  }
}
void sonar2(){
  int duration, distance;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 400 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sonar2: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

