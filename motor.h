//------------------------------------------------------------------------------
//
// motor.h
//
// This file provides functions that relate to driving the DC motors.
//

//------------------------------------------------------------------------------
//
// convert_joystick_to_motor
//
int convert_joystick_to_motor (short a_joystick_value)

{
    //
    // Set the default speed and direction to 0 and one, respectively.
    //
    float speed = 0;
    short direction = 1;
    const short deadBand = 28;

    //
    // If the specified joystick value is [-27,27], then set the speed to the
    // absolute value of the joystick value and subtract 28.  This margin allows
    // for a dead zone (noise) within the joystick hardware.
    //
    if ((a_joystick_value < -(deadBand)) || (a_joystick_value > deadBand))
    {
        speed = abs (a_joystick_value) - 28;
    }
    //
    // If the specified joystick value is greater than zero, then set the
    // direction to a negative value (-1) (i.e. pushing a joystick away from the
    // human has a negative value, so negate it to drive the robot "forward").
    // This will depend on how your robot is wired and/or how the pragmas are
    // configured.
    //
    if (a_joystick_value < 0)
    {
        direction = -1;
    }

    //
    // Return the speed multiplied by the direction.
    //
    return (speed * direction);

} // convert_joystick_to_motor

//GTA drive

const short top = 100; //top
const short bottom = -100; //bottom
const short db = 10; //deadband


int gta_deadband (int value, int deadband, int top_limit, int bottom_limit)
{
	int result = 0; //defines variable
	if (abs(value) < deadband) //if less than deadband
		return 0; //return 0(nothing)

	if (value > 0) result = value - deadband; //subtracts if positive
	else           result = value + deadband; //adds if negative

	if (result > top_limit) 				result = top_limit;		 //checks if result is greater than max, if true, result = max
	else if (result < bottom_limit) result = bottom_limit; //checks if result is less than min, if true, result = min

	return result;
}

int gta_joysticks_to_l_motor(short y_joystick_value, short x_joystick_value)
{
	int db_y = gta_deadband(y_joystick_value, db, top, bottom); //deadbands joystick values
	int db_x = gta_deadband(x_joystick_value, db, top, bottom);
	int result = -(db_y) - db_x; //gets left motor value

	if(result > top)  			 result = top;    //checks if result is greater than max, if true, result = max
	else if(result < bottom) result = bottom; //checks if result is less than min, if true, result = min

	return result; //returns final left motor value
}

int gta_joysticks_to_r_motor(short y_joystick_value, short x_joystick_value)
{
	int db_y = gta_deadband(y_joystick_value, db, top, bottom); //deadbands joystick values
	int db_x = gta_deadband(x_joystick_value, db, top, bottom);
	int result = -(db_y) + db_x; //gets right motor value

	if(result > top) 			   result = top;    //checks if result is greater than max, if true, result = max
	else if(result < bottom) result = bottom; //checks if result is less than min, if true, result = min

	return result; //returns final right motor value
}
