#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     eye_sensor,     sensorLightActive)
#pragma config(Motor,  motorA,          ball_lift_motor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          left_arm_motor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          ball_scoop_motor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     left_foot_motor, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right_foot_motor, tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    left_hand_servo,      tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    right_hand_servo,     tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

#include "constants.h"  // Must be included before other user-defined headers.

#include "BasicFunctions.h"
#include "motor.h"
#include "light.h"

#include "initialize.h" // Must be included after other user-defined headers.

#include "manual.h"
#include "auto_functions.h"
#include "transition.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

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
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


task main()
{
    initialize ();  // In the original template this was "initializeRobot();"

    waitForStart (); // Wait for the beginning of autonomous phase.

    clasp_goal(false); //ensures grabber is up

    drive_off_ramp (false); //drives off ramp backwards

    distanceToDrive = 42.0; //42 in.
    drive_both_wheels (-motorSpeed, -motorSpeed, distanceToDrive * kInch); //drives into goal for pick-up (3ft 4in)

    clasp_goal(true); //grabs onto goal

    degreesToTurn = 20.0; //20 degrees
    TurnRight(degreesToTurn * kDegrees); //goes at angle of 20 degrees to drive to park zone

    distanceToDrive = 132; //132 in.
    drive_both_wheels(motorSpeed, motorSpeed, distanceToDrive * kInch); //drives 11 feet to park zone

    transition(); //waits for autonomous phase to end

} // main
