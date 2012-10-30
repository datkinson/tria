void drive(){

	writeScreen("Choose a direction","L | R | Fwd | m ");
	checkButtons();
	switch (activeButton){
	case 1:
		left();
		break;
	case 2;
		right()
		break;
	case 3:
		forward();
		break;
	case 4:
		menu();
		break;
	}
}

void left(){
	Serial.write("l");
}
void right(){
	Serial.write("r");
}
void forward(){
	Serial.write("f");
}

