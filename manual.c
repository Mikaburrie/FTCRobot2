#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     joystick1,      sensorI2CMuxController)
#pragma config(Sensor, S2,     eye_sensor,     sensorLightActive)
#pragma config(Motor,  motorA,          left_arm_motor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          right_arm_motor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     left_foot_motor, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     right_foot_motor, tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    left_hand_servo,      tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    right_hand_servo,     tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    grab_servo,           tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

#include "constants.h"  // Must be included before other user-defined headers.

#include "BasicFunctions.h"
#include "motor.h"

#include "initialize.h" // Must be included after other user-defined headers.

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////n

#ifdef d_code_moved
This template function has been moved to the constants.h header file, so it can
be used for both manual and autonomous purposes.
	void initializeRobot()
{

} // initializeRobot
#endif d_code_moved

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
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
		int l_motor = convert_joystick_to_motor (joystick.joy2_y1);
		motor[c_left_arm_motor] = l_motor;
		motor[c_right_arm_motor] = l_motor;

		//
		// Manage the hand servo positions, which make the hand open and close.
		//
		//M.B. changed button 6 to button 4
		//M.B. changed joy2Btn to joy1Btn because we arn't using a second joystick(yet)
		//M.B. issue with buttons on controller. not permanant
		if (joy1Btn (6) != false)
		{
			move_arm (e_hand_command_raise);
		}
		else if (joy1Btn (8) != false)
		{
			move_arm (e_hand_command_lower);
		}
		else if (joy1Btn (5) != false)
		{
			move_arm (e_hand_command_partially_raise);
		}
		else if (joy1Btn (7) != false)
		{
			move_arm (e_hand_command_partially_lower);
		}

		//
		// This wait is important for several reasons.  It provides the message
		// a chance to perform its processing.  It also determines how fast the
		// servos open and close (see the increment blocks in move_hand).
		//
		wait1Msec (10);

	} // while (true)

} // main
