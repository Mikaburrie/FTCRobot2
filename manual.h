// manual mode //

void manual_main_function ()
{
	initialize ();  // In the original template this was "initializeRobot();"

	waitForStart ();   // wait for start of tele-op phase

	while (true)
	{
		//
		// Read the current values of the joystick controllers.
		//
		hogCPU (); // Prevent the messaging task from writing to it while it is being read.
		getJoystickSettings (joystick); // Added to template for kick-off presentation
		releaseCPU ();

		//
		// Manage power to the drive wheels.
		//
		motor[c_left_foot_motor] =
		convert_joystick_to_motor (joystick.joy1_y1);

		motor[c_right_foot_motor] =
		convert_joystick_to_motor (joystick.joy1_y2);

		//
		// Manage the power and direction of the LEGO arm motors, which make the
		// arm move up and down.
		//
//		int l_motor = convert_joystick_to_motor (joystick.joy2_y1);
//		motor[c_left_arm_motor] = l_motor;
//		motor[c_right_arm_motor] = l_motor;

		//
		// Manage the hand servo positions, which make the hand open and close.
		//
		//M.B. changed button 6 to button 4
		//M.B. issue with buttons on controller. not permanant
		if (joy2Btn (8) != false)
		{
			move_arm (e_hand_command_raise);
		}
		else if (joy2Btn (6) != false)
		{
			move_arm (e_hand_command_lower);
		}
		else if (joy2Btn (7) != false)
		{
			move_arm (e_hand_command_partially_raise);
		}
		else if (joy2Btn (5) != false)
		{
			move_arm (e_hand_command_partially_lower);
		}

		scoop_balls (joystick.joy2_y2);

		lift_balls (joystick.joy2_y1);



		//
		// This wait is important for several reasons.  It provides the message
		// a chance to perform its processing.  It also determines how fast the
		// servos open and close (see the increment blocks in move_hand).
		//

		wait1Msec (10);
	} // while (true)

}
