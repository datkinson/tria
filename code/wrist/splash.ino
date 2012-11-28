void splash(){
  if(screen){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Welcome to");
    lcd.setCursor(0,1);
    lcd.print("Tria monitor"); 
    screen=false;
  }
}
