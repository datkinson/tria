void menu(){
  if (activeButton!=prevButton){
 if(activeButton==2){
   if(menuPosition<5){
     menuPosition++;
     screen=true;
     displayMenu();
   }
  }
  if(activeButton==1){
   if(menuPosition>0){
     menuPosition--;
     screen=true;
     displayMenu();
   }
  }
  if(activeButton==3){
   mode=menuPosition;
  screen=true; 
  }
  }
}
void displayMenu(){
  if(screen){
    String temp = ">"+menuItems[menuPosition]; 
    writeScreen(temp,menuItems[menuPosition+1]);
    screen=false;
  }
}
