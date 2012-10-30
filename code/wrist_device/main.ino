#include <LiquidCrystal.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3, 2);
String message ="";
String lcd_line0 = "";
String lcd_line1 = "";
String previous_line = "";
String current_line = "";
char inData[16];
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
char temp = 'a';

int button1 = A7;//Up
int button2 = A6;//Down
int button3 = A5;//Select
int button4 = A4;//Menu
int activeButton = 0;
int prevButton = 0;
int menuPosition = 0;
int mode=0;//0=default, 1=menu
boolean screen = true; //if screen needs writing to
String menuItems[6]={"Splash Screen", "Menu", "Button Debug", "Serial Input", "Time", "Misc"};

void setup()
{
  lcd.begin(16,2);
  Serial.begin(57600);
  Serial.write("Link Active");

}
void checkButtons (){
  prevButton=activeButton;
  if(analogRead(button1)>1000){
    activeButton=1;
  }else{
   if(analogRead(button2)>1000){
    activeButton=2;
   }else{
    if (analogRead(button3)>1000){
      activeButton=3;
    }else{
     if(analogRead(button4)>1000){
      activeButton=4;
      screen=true;
      mode=1;
      menuPosition=0;
      activeButton=0;
      displayMenu();
     }else{
      activeButton=0;
     } 
    }
   } 
  }
}
void writeMessage(int line, String input_message)
   {
    if(line==0){
      lcd_line0 = input_message;
    }
    else{
      if(line==1){
        lcd_line1 = input_message;
      }  
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(lcd_line0);
    lcd.setCursor(0,1);
    lcd.print(lcd_line1);
  }
void writeScreen(String line0, String line1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(line0);
    lcd.setCursor(0,1);
    lcd.print(line1);
  }

void loop()
{
  checkButtons();
  //menu();
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
      misc();
      break;
    default: 
    writeScreen("Error!","'Invalid Mode'");
  }
  delay(200);
}
