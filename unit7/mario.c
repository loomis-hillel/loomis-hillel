#include<stdio.h>
#include<cs50.h>

/**
 * Produces a pyramid shape (like in Super Mario Bros 
 * level 1-1) based on the height provided by the user.
 * Author: Ken Loomis (with the help of AP CS Principles students)
 */
int main ( void ) {

    // Variable declaration
    int height, hashes;

    // Collect the height from the user
    height = get_int( "Height: " );
    while ( height < 1 || height > 8 ) {
        height = get_int( "Height: " );
    }
    
    // Display the pyramid of the correct height
    // by printing each row at a time.
    hashes = 1;
    while ( hashes <= height) {
        // In each row, display the correct number
        // of spaces
        for ( int count=0; count<height-hashes; count++ ) {
            printf ( " " );    
        }
        // In each row, display the correct number
        // of hashes
        for ( int count=0; count<hashes; count++ ) {
            printf ( "#" );    
        }
        printf ( "\n" );
        // hashes = hashes + 1;
        hashes++;
    }
    return 0;
}