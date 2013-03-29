void setup() {
  pinMode(13, OUTPUT); //Left direction pin
  pinMode(12, OUTPUT); //Left step pin
  pinMode(11, OUTPUT); //Right direction pin
  pinMode(10, OUTPUT); //Right step pin
}
void loop() {
  digitalWrite(13, HIGH); //Set left motor forward
  digitalWrite(11, LOW); //Set right motor forward
  for (int i = 0; i < 200; i++){
    digitalWrite(12, HIGH); //Step left wheel forward
    digitalWrite(10, HIGH); //Step right wheel forward
    delay(10); // wait a 1/10 second
    digitalWrite(12, LOW); //Stop left wheel
    digitalWrite(10, LOW); //Stop right wheel
    delay(10); // wait a 1/10 second
  }
  digitalWrite(13, LOW); //reverse left motor deirection
  digitalWrite(11, HIGH); //reverse right motor deirection
  for (int j = 0; j < 200; j++){
    digitalWrite(12, HIGH); //Step left wheel backwards
    digitalWrite(10, HIGH); //Step right wheel backwards
    delay(10); // wait a 1/10 second
    digitalWrite(12, LOW); //Stop left wheel
    digitalWrite(10, LOW); //Stop right wheel
    delay(10); // wait a 1/10 second
  }
}
