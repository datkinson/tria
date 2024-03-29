//Author: Daniel Atkinson

//declare how many degrees per step the stepper motors rotate
degreesRotated = 1.8;

//declare diameter of the wheel in mm
wheelDiameter = 120;

//declare radius of the wheel in mm
wheelRadius = wheelDiameter / 2;

//distance taveled in a single rotation
singleRotationDistance = 3.14159 * wheelDiameter;

//Number of steps for a single rotation
stepsInRotation = 360 / degreesRotated;

//distance moved in a single step
singleStepMove = singleRotationDistance / stepsInRotation;

//Width of the robot in mm from the center of each wheel
robotWidth = 200;

//width of the wheel in mm
wheelWidth = 20;


void setup()
{
	Serial.begin(9600);
}

void loop()
{
	recieveCommand();
}

//Read serial input and act accordingly
void recieveCommand()
{

}

//turn robot left by the specified degrees
void turnLeft(int degrees)
{
	steps = degreesToSteps(degrees);
	leftMotor.step(-steps);
	rightMotor.step(steps);
}

//turn robot right by the specified degrees
void turnRight(int degrees)
{
        steps = degreesToSteps(degrees);
        leftMotor.step(steps);
        rightMotor.step(-steps);
}

//move the specified distance
void drive(int distance)
{
	steps = distanceToSteps(distance)
	leftMotor.step(steps);
	rightMotor.step(steps);
}

//convert degrees to number of stepper motor steps
int degreesToSteps(int degrees)
{

}

//convert distance to number of steps
int distanceToSteps(int distance)
{

}
