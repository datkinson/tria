void time(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Uptime:");
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  lcd.setCursor(9,1);
  lcd.print("Seconds");
}
