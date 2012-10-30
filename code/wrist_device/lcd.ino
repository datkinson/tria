void printSerialLcd(){
 int i=0;
  char commandbuffer[100];

  if(Serial.available()){
     delay(100);
     while( Serial.available() && i< 99) {
        commandbuffer[i++] = Serial.read();
     }
     commandbuffer[i++]='\0';
  }

  if(i>0)
  {
    previous_line=current_line;
    current_line=(char*)commandbuffer;
    writeScreen(previous_line,current_line);
     Serial.println(current_line);
  } 
}
