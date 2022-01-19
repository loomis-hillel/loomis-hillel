#include <cs50.h>
#include <stdio.h>

/**
 * Searches an array to see if the given target exists within the array.
 * Produces a message whether it is found or not.
 */
int main ( void ) {
    int array [] = { 58, 1, 24, 7, 17, 82, 85, 27, 31, 52, 67, 89, 79, 87, 90, 63, 15, 22, 81, 75, 86, 77, 88, 56, 34, 33, 80, 76, 96, 99, 53, 43, 54, 59, 69, 11, 84, 60, 46, 92, 48, 45, 5, 78, 44, 73, 62, 83, 66, 93, 50, 35, 36, 65, 41, 16, 91, 18, 29, 100, 40, 49, 9, 4, 6, 71, 20, 95, 61, 94, 74, 12, 28, 38, 14, 19, 39, 25, 37, 30, 8, 3, 70, 57, 10, 64, 23, 55, 42, 47, 13, 98, 51, 72, 21, 68, 2, 32, 97, 26 };
    bool found = false;
    int index;
    int target = get_int( "Look for what number: " );
    
    // Create a loop here that will traverse the array looking for the target
    
    
    if ( found ) {
        printf ( "%i is in the array\n", target );
    } else {
        printf ( "%i is not in the array\n", target );
    }
    return 0;
}