#include <ctype.h>
#include <stdio.h>

int buttonUp = 0;
int buttonDown = 1;
int buttonLeft = 2;
int buttonRight = 3;
int buttonSelect = 4;
int buttonBack = 5;

int activeButton = 0;
int prevButton = 0;

void setup()
{
  Serial.begin(57600);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(buttonSelect, INPUT);
  pinMode(buttonBack, INPUT);
}
void checkButtons (){
  prevButton=activeButton;
  if (digitalRead(buttonUp) == HIGH){
    upPressed();
  }
  if (digitalRead(buttonDown) == HIGH){
    downPressed();
  }
  if (digitalRead(buttonLeft) == HIGH){
    leftPressed();
  }
  if (digitalRead(buttonRight) == HIGH){
    rightPressed();
  }
  if (digitalRead(buttonSelect) == HIGH){
    selectPressed();
  }
  if (digitalRead(buttonBack) == HIGH){
    backPressed();
  }
}

void upPressed(){
  Serial.write('f');
}
void downPressed(){
  Serial.write('b');
}
void leftPressed(){
  Serial.write('l');
}
void rightPressed(){
  Serial.write('r');
}
void selectPressed(){

}
void backPressed(){

}

void loop()
{
  checkButtons();
  delay(200);
}
