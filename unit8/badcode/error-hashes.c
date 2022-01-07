#include <stdio.h>
#include <cs50.h>

/**
 * error-hashes.c
 *
 * This program contains an error which prevents it from being
 * a correct solution. Correct the errors so that it correctly
 * performs the task below.
 *
 * Produces the numbers 10 through 1 as output to the terminal
 *
 * @author Ken Loomis
 */
int main( void ) {

    for ( int i=10; i<1; i-- ){
        printf( "%i\n", i );
    }
    return 0;
}
