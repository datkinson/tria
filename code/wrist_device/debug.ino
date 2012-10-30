void buttonDebug(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("B1:");
  lcd.print(analogRead(button1));
  lcd.setCursor(8,0);
  lcd.print("B2:");
  lcd.print(analogRead(button2));
  lcd.setCursor(0,1);
  lcd.print("B3:");
  lcd.print(analogRead(button3));
  lcd.setCursor(8,1);
  lcd.print("B4:");
  lcd.print(analogRead(button4));
}
