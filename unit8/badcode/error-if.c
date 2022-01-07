#include <stdio.h>
#include <cs50.h>


/**
 * error-if.c
 *
 * This program contains an error which prevents it from being
 * a correct solution. Correct the errors so that it correctly
 * performs the task below.
 *
 * Accepts user input in the form of an integer and outputs
 * a message if the input is larger than 5.
 *
 * @author Ken Loomis (https://github.com/kjloomis/cs50x_lecturecode)
 */
int main ( )
{
	int num = get_int( );
	if ( num > 5 );
	{
		printf ( "Bigger than 5.\n" );
	}
	return 0;
}
