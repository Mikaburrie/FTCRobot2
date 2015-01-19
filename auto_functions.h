//functions for autonomous
const short motorSpeed = 100; //defines motor speed
float distanceToDrive = 72.0; //72 in.
float degreesToTurn = 0.0; //0.0 degrees

//drives off ramp
void drive_off_ramp (bool forward) //true = forward; false = backwards
{
	distanceToDrive = 72.0; //six feet or 72 in.
	if (forward)
	{
		drive_both_wheels (motorSpeed, motorSpeed, distanceToDrive * kInch); //drives 6 feet
	}
	else
	{
		drive_both_wheels (-(motorSpeed), -(motorSpeed), distanceToDrive * kInch);
	}
}

//controls grabber
void clasp_goal (bool pos) //true = down; false = up
{
	if(pos)
	{
		move_arm(e_hand_command_lower);
	}
	else
	{
		move_arm(e_hand_command_raise);
	}
	wait1Msec(50); //waits 0.05 seconds for arm to move
}
