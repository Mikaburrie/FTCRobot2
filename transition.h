void transition()
{
	while(true) //loops until autonomous phase stops
	{
		getJoystickSettings(joystick);
		if(joystick.StopPgm)
			break;
	}
	manual_main_function(); //Transitions to manual
}
