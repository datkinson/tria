//Author: Daniel Atkinson

//declare how many degrees per step the stepper motors rotate
degreesRotated = 1.8;
//declare diameter of the wheel in mm
wheelDiameter = 120;


void setup()
{
	Serial.begin(9600);
}

void loop()
{
	recieveCommand();
}

void recieveCommand()
{
//Read serial input and act accordingly

}

void turnLeft(int degrees)
{
//turn robot left by the specified degrees
	steps = degreesToSteps(degrees);
	leftMotor.step(-steps);
	rightMotor.step(steps);
}

void turnRight(int degrees)
{
//turn robot right by the specified degrees
        steps = degreesToSteps(degrees);
A
        leftMotor.step(steps);
        rightMotor.step(-steps);
}

void drive(int distance)
{
//move the specified distance
	steps = distanceToSteps(distance)
	leftMotor.step(steps);
	rightMotor.step(steps);
}

int degreesToSteps(int degrees)
{
//convert degrees to number of stepper motor steps

}

int distanceToSteps(int distance)
{
//convert distance to number of steps

}
