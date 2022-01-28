#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Switch this to true to see each element during the search
const bool VERBOSE = false;

const long MAX_ARRAY = 1000000;


void test_search ( long array[], long size);
void test_sort ( long array[], long size);
void bail ( string msg );
void calculate_search_time ( long (* function)(long, long[], long), long target, long array[], long size );
void calculate_sort_time ( void (* function)(long[], long), long array[], long size );
void generate_random ( long array[], long size );
void generate_sorted ( long array[], long size );
long linear_search ( long target, long array [], long size );
long linear_search_opt ( long target, long array [], long size );
long binary_search ( long target, long array [], long size );
void bubble_sort ( long array[], long size );
void selection_sort ( long array[], long size );
void insertion_sort ( long array[], long size );
void print_array ( long array[], long size );

/**
 * This program is created for the purpose of exploring different searching
 * and sorting algorithms without the need to read or write the code to do so.
 * Simply compile the code using make algorithms and run it using ./algorithms.
 * You can stop reading now.
 * Author: Ken Loomis
 */
int main ( void ) {
    long array [MAX_ARRAY];

    long size = 0;
    int type = 0;

    printf ( "Choose a test to run.\n" );
    type = get_int ( "\t1. Search algorithms\n\t2. Sorting algorithms\nSelect one: " );
    if ( type < 1 || type > 2 ) {
        bail ( "Invalid selection." );
    }

    printf ( "Enter the size of the array to test (max = %li).\n", MAX_ARRAY );
    size = get_int ( "\tsize: " );
    if ( size < 1 || size > MAX_ARRAY ) {
        bail ( "Invalid size." );
    }

    switch ( type ) {
        case 1: test_search ( array, size ); break;
        case 2: test_sort ( array, size ); break;
    }

    return 0;
}

/**
 * Tests the 3 search algorithms that we discussed in class: classic
 * linear search, optimized linear search, and binary search. Produces
 * the running clock time of each algorithm for analysis.
 */
void test_search ( long array[], long size) {
    if ( size > MAX_ARRAY ) bail ( "Invalid array size!" );
    long target;
    generate_random ( array, size );

    printf ( "\n\n****** Linear Search ******\n" );
    target = array[0];
    printf ( "Best-Case Scenario: \n" );
    calculate_search_time ( &linear_search, target, array, size );
    target = size+1;
    printf ( "Worst-Case Scenario: \n" );
    calculate_search_time ( &linear_search, target, array, size );

    printf ( "\n\n***** Linear search (optimized) *****\n" );
    target = array[0];
    printf ( "Best-Case Scenario: \n" );
    calculate_search_time ( &linear_search_opt, target, array, size );
    target = size+1;
    printf ( "Worst-Case Scenario: \n" );
    calculate_search_time ( &linear_search_opt, target, array, size );

    generate_sorted ( array, size );

    printf ( "\n\n***** Binary search *****\n" );
    target = array[size/2];
    printf ( "Best-Case Scenario: \n" );
    calculate_search_time ( &binary_search, target, array, size );
    target = size+1;
    printf ( "Worst-Case Scenario: \n" );
    calculate_search_time ( &binary_search, target, array, size );

    printf ( "\n***** Done *****\n\n" );
}

/**
 * Tests the 3 sorting algorithms that we discussed in class:
 * bubble sort, selections sort, and insertions sort. Produces
 * the running clock time of each algorithm for analysis.
 */
void test_sort ( long array[], long size) {
    if ( size > MAX_ARRAY ) bail ( "Invalid array size!" );

    printf ( "\n\n****** Bubble Sort ******\n" );
    generate_sorted ( array, size );
    printf ( "Best-Case Scenario: \n" );
    calculate_sort_time ( &bubble_sort, array, size );
    generate_random ( array, size );
    printf ( "Worst-Case Scenario: \n" );
    calculate_sort_time ( &bubble_sort, array, size );

    printf ( "\n\n***** Insertion Sort *****\n" );
    generate_sorted ( array, size );
    printf ( "Best-Case Scenario: \n" );
    calculate_sort_time ( &insertion_sort, array, size );
    generate_random ( array, size );
    printf ( "Worst-Case Scenario: \n" );
    calculate_sort_time ( &insertion_sort, array, size );

    printf ( "\n\n***** Selection Sort *****\n" );
    generate_sorted ( array, size );
    printf ( "Best-Case Scenario: \n" );
    calculate_sort_time ( &selection_sort, array, size );
    generate_random ( array, size );
    printf ( "Worst-Case Scenario: \n" );
    calculate_sort_time ( &selection_sort, array, size );

    printf ( "\n***** Done *****\n\n" );
}

/**
 * Bails out of the program with a error value of 1.
 * The message is displayed to the console.
 */
void bail ( string msg ) {
    printf ( "%s\n", msg );
    exit(1);
}

/**
 * Displays the results and runtime of the given search algorithm.
 */
void calculate_search_time ( long (* function)(long, long[], long), long target, long array[], long size ) {
    clock_t t = clock();
    long loc = (*function) ( target, array, size);
    t = clock() - t;
    long time_taken = ( (long) t ); // CLOCKS_PER_SEC;
    printf("\tThe value %li was found at index %li\n", target, loc);
    printf("\tThe search took %li ms to execute\n", time_taken);
}

/**
 * Displays the runtime of the given sorting algorithm.
 */
 void calculate_sort_time ( void (* function)(long[], long), long array[], long size ) {
    clock_t t = clock();
    (*function) ( array, size);
    t = clock() - t;
    long time_taken = ( (long) t ); // CLOCKS_PER_SEC;
    printf("\tThe sort took %li ms to execute\n", time_taken);
 }

/**
 * Generate an array of random positive numbers upto the size given.
 * It is assumed that the array is large enough to hold that many
 * numbers. The numbers will be between 0 and size. Duplicates may result.
 */
void generate_random ( long array[], long size ) {
    if ( size > MAX_ARRAY ) bail ( "Invalid array size!" );
    clock_t t = clock();
    srand((unsigned) time(&t));
    for ( long i=0; i<size; i++ ) {
        array[i] = rand() % size;
    }
    return;
}

/**
 * Generate an array of sorted positive numbers up to the size given.
 * It is assumed that the array is large enough to hold that many
 * numbers. The numbers will be between 0 and size. No duplicates will result.
 */
void generate_sorted ( long array[], long size ) {
    if ( size > MAX_ARRAY ) bail ( "Invalid array size!" );
    for ( long i=0; i<size; i++ ) {
        array[i] = i;
    }
    return;
}

/**
 * Performs a sequential search of the array to find the target.
 * Returns the index position of the element if found or -1 otherwise.
 */
long linear_search ( long target, long array [], long size ) {

    long loc = -1;
    for ( long i=0; i<size; i++ ) {
        if ( target == array[i] ) {
            loc = i;
        }
        if (VERBOSE) printf ( "%li\n", array[i] );
    }
    return loc;

}

/**
 * Performs a sequential search of the array to find the target.
 * The search terminates early if the element is found.
 * Returns the index position of the element if found or -1 otherwise.
 */
long linear_search_opt ( long target, long array [], long size ) {

    long loc = -1;
    for ( long i=0; i<size && loc<0; i++ ) {
        if ( target == array[i] ) {
            loc = i;
        }
        if (VERBOSE) printf ( "%li\n", array[i] );
    }
    return loc;

}

/**
 * Performs a binary search of the array to find the target.
 * The search terminates early if the element is found.
 * Returns the index position of the element if found or -1 otherwise.
 */
long binary_search ( long target, long array [], long size ) {

    long loc = -1;
    long left = 0;
    long right = size;
    long middle = 0; // given a value to silence warnings

    while ( left < right && loc < 0 ) {
        middle = (left + right) / 2;
        if ( target > array[middle] ) {
            left = middle+1;
        } else if ( target < array[middle]) {
            right = middle;
        } else {
            loc = middle;
        }
        if (VERBOSE) printf ( "%li\n", array[middle] );
    }
    return loc;

}

/**
 * Sorts the array according to the bubble sort algorithm.
 */
void bubble_sort ( long array[], long size ) {

	bool swapped = true;
    while (swapped) {
        swapped = false;
	    for (long i = 1; i < size; i++ ) {
		    if ( array[i-1] > array[i] ) {
		        long swap = array[i];
		        array[i] = array[i-1];
		        array[i-1] = swap;
		        swapped = true;
		    }
	    }
        size = size - 1;
	}

}

/**
 * Sorts the array according to the selection sort algorithm.
 */
void selection_sort ( long array[], long size ) {

	for ( long j = 0; j < size-1; j++ ) {
        long minPos = j;
	    for ( long i = j+1; i < size; i++ ) {
            if ( array[i] < array[minPos] ) {
				minPos = i;
            }
	    }

        if ( minPos != j ) {
            long swap = array[j];
		    array[j] = array[minPos];
		    array[minPos] = swap;
        }
	}

}

/**
 * Sorts the array according to the insertion sort algorithm.
 */
void insertion_sort ( long array[], long size ) {
    for ( long i = 1; i < size; i++ ) {
        long x = array[i];
        long j = i - 1;
        while ( j >= 0 && array[j] > x ) {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = x;
    }

}

void print_array ( long array[], long size ) {
    for ( long i = 1; i < size-1; i++ ) {
        printf ( "%li, ", array[i] );
        if ( i % 20 == 0 ) printf ( "\n" );
    }
    printf ( "%li\n\n", array[size-1] );
}