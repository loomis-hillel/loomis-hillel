#include <stdio.h>
#include <cs50.h>

/**
 * scores.c
 *
 * Accepts multiple homework scores from the user until
 * they enter a negative number. It then produces the
 * average of the scores (with 2 decimals of precision.)
 *
 * @author Ken Loomis
 */
int main(void)
{
	int count;
	float sum = 0;
	// declare an array of 10 scores here
	printf ( "Enter 10 homework scores: \n" );
	for(count = 0; count < 10; count++)
	{
		// ?? = get_int( "score:" );
		// sum += ??;
	}
	printf ( "HW Average = %.2f\n", sum/count );
}
