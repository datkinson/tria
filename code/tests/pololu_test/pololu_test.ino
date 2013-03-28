void setup() {
  pinMode(10, OUTPUT); //Step pin
  pinMode(11, OUTPUT); //Direction pin
}
void loop() {
  digitalWrite(11, HIGH); // +5V to Pin D1
  for (int i = 0; i < 200; i++){
    digitalWrite(10, HIGH); // +5V to Pin D2
    delay(10); // wait a 1/10 second
    digitalWrite(10, LOW); // Gnd to Pin D2
    delay(10); // wait a 1/10 second
  }
  digitalWrite(11, LOW);
  for (int j = 0; j < 200; j++){
    digitalWrite(10, HIGH); // +5V to Pin D2
    delay(10); // wait a 1/10 second
    digitalWrite(10, LOW); // Gnd to Pin D2
    delay(10); // wait a 1/10 second
  }
}
