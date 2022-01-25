#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Switch this to true to see each element during the search
bool VERBOSE = true;

int linear_search ( string target, string array [], int size );
int linear_search_opt ( string target, string array [], int size );
int binary_search ( string target, string array [], int size );

/**
 * Allows the use to search for an element of an array that
 * contains a list of strings in sorted order. Produces the
 * index position of the searched for string if it is in
 * the array or a message indicating that it is not found.
 * The user also selects the search algorithm used.
 * Author: Ken Loomis
 */
int main ( void ) {
    string pets [] = { "alligator", "bird", "cat", "chinchilla", "cockroach",
                       "dog", "ferret", "fish", "hedgehog", "iguana",
                       "mouse", "pig", "rabbit", "rock", "snail",
                       "snake", "spider", "turtle" };
    int size = 18;
    int loc = -1;
    string target = get_string ( "What do you want to look for: " );
    int search = get_int ( "1. Linear search\n2. Linear search (optimized)\n3. Binary seach\nSelect one: " );

    if ( search == 1 ) {
        loc = linear_search (target, pets, size);
    } else if ( search == 2 ) {
        loc = linear_search_opt (target, pets, size);
    } else {
        loc = binary_search (target, pets, size);
    }
    if ( loc > 0 ) {
        printf ( "%s at location %i\n", target, loc );
    } else {
        printf ( "%s is not in the array\n", target );
    }

}

/**
 * Performs a sequential search of the array to find the target.
 * Returns the index position of the element if found or -1 otherwise.
 */
int linear_search ( string target, string array [], int size ) {

    int loc = -1;
    for ( int i=0; i<size; i++ ) {
        if ( strcmp( target, array[i]) == 0 ) {
            loc = i;
        }
        if (VERBOSE) printf ( "%s\n", array[i] );
    }
    return loc;

}

/**
 * Performs a sequential search of the array to find the target.
 * The search terminates early if the element is found.
 * Returns the index position of the element if found or -1 otherwise.
 */
int linear_search_opt ( string target, string array [], int size ) {

    int loc = -1;
    for ( int i=0; i<size && loc<0; i++ ) {
        if ( strcmp( target, array[i]) == 0 ) {
            loc = i;
        }
        if (VERBOSE) printf ( "%s\n", array[i] );
    }
    return loc;

}

/**
 * Performs a binary search of the array to find the target.
 * The search terminates early if the element is found.
 * Returns the index position of the element if found or -1 otherwise.
 */
int binary_search ( string target, string array [], int size ) {

    int loc = -1;
    int left = 0;
    int right = size;
    int middle = 0; // given a value to silence warnings

    while ( left < right && loc < 0 ) {
        // Calculate the middle value.

        // Determine the comparison value (greater than, less than, or equal)

        // Use the comparison value to calculate a range (left/right) or get the index.

        // Leave this at the bottom
        if (VERBOSE) printf ( "%s\n", array[middle] );
    }
    return loc;

}
