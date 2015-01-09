//switches from manual to autonomous
void transition()
{
	while(true) //loops until autonomous phase stops
	{
		getJoystickSettings(joystick);
		if(joystick.StopPgm)
			break;
	}

	nMotorEncoder[c_left_foot_motor] = 0;
	nMotorEncoder[c_right_foot_motor] = 0;

	manual_main_function(); //Transitions to manual
}
