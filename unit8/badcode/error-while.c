#include <stdio.h>
#include <cs50.h>

/**
 * error-while.c
 *
 * This program contains an error which prevents it from being
 * a correct solution. Correct the errors so that it correctly
 * performs the task below.
 *
 * Accepts multiple homework scores from the user until
 * they enter a negative number. It then produces the
 * average of the scores (with 2 decimals of precision.)
 *
 * @author Ken Loomis (https://github.com/kjloomis/cs50x_lecturecode)
 */
int main(void)
{
	int count = 0;
	int sum = 0;
	printf ( "Enter HW scores (-1 when done): " );
	while(1)
	{
		int num = get_int( );
		if ( num <= 0 ) break;
		sum += num;
		count++;
	}
	printf ( "HW Average = %.2f", sum/count );
}
