//functions for autonomous
const short motorSpeed = 100; //defines motor speed

//drives off ramp
void drive_off_ramp (bool forward) //true = forward; false = backwards
{
	if (forward)
	{
		drive_both_wheels (motorSpeed, motorSpeed, 6 * kFoot);
	}
	else
	{
		drive_both_wheels (-(motorSpeed), -(motorSpeed), 6 * kFoot);
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
}

//lifts ball scoop
void lift_dropper (int height)
{
	lift_balls(100);
	wait10Msec(height * 10);
	lift_balls(0);
}
