#include <ctype.h>
#include <stdio.h>
#include <string.h>

int buttonUp = 0;
int buttonDown = 1;
int buttonLeft = 2;
int buttonRight = 3;
int buttonSelect = 4;
int buttonBack = 5;

int activeButton = 0;
int prevButton = 0;
int mode=0;//0=default, 1=menu

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

}

void upPressed(){

}
void downPressed(){

}
void leftPressed(){

}
void rightPressed(){

}
void selectPressed(){

}
void backPressed(){

}

void loop()
{
  checkButtons();
  switch (mode) {
  case 0:
    splash();
    break;
  case 1:
    menu();
    break;
  case 2:
    buttonDebug();
    break;
  case 3:
    printSerialLcd();
    break;
  case 4:
    time();
    break;
  case 5:
    drive();
    break;
  default:
    writeScreen("Error!","'Invalid Mode'");
  }
  delay(200);
}
