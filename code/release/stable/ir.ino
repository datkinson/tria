//Magic numbers
int leftIrId = 0;
int rightIrId = 1;
int irLower = 0;
int irUpper = 400;

int getIrReading(int sensor){
  return(distance);
}

void detectIrProximity(){
  leftIr = getIrReading(leftIrId);
  rightIr = getIrReading(rightIrId);
  Serial.print("Left: ");
  Serial.print(leftIr);
  Serial.print(" - Right: ");
  Serial.println(rightIr);
  if (leftIr < proximityThreshold){
    turnRight(arbritraryMovement);
  }
  if (rightIr < proximityThreshold){
    turnLeft(arbritraryMovement);
  }
}
bool validateIr(){
  if(leftIr < irUpper && leftIr > irLower){
    if(rightIr < irUpper && rightIr > irLower){
      return true;
    }else{
      return false;
    }
  }
}
