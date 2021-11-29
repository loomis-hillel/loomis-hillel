#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void printBar( int size ){
    for (int i=0; i<size; i++ )
        printf( "-" );
    printf ( "\n" );
}

int main(void) {

    printf("char:\n");
    printBar(48);
    printf("\tbytes :\t%d\n", CHAR_BIT/8);
    printf("\tmin   :\t%d\n", CHAR_MIN);
    printf("\tmax   :\t%d\n", CHAR_MAX);
    printBar(48);

    printf("short:\n");
    printBar(48);
    printf("\tbytes :\t%lu\n", sizeof(short));
    printf("\tmin   :\t%d\n", SHRT_MIN);
    printf("\tmax   :\t%d\n", SHRT_MAX);
    printBar(48);

    printf("int:\n");
    printBar(48);
    printf("\tbytes :\t%lu\n", sizeof(int));
    printf("\tmin   :\t%d\n", INT_MIN);
    printf("\tmax   :\t%d\n", INT_MAX);
    printBar(48);

    printf("unsigned int:\n");
    printBar(48);
    printf("\tbytes :\t%lu\n", sizeof(unsigned int));
    printf("\tmin   :\t%u\n", 0);
    printf("\tmax   :\t%u\n", UINT_MAX);
    printBar(48);

    printf("long:\n");
    printBar(48);
    printf("\tbytes :\t%lu\n", sizeof(long));
    printf("\tmin   :\t%li\n", LONG_MIN);
    printf("\tmax   :\t%li\n", LONG_MAX);
    printBar(48);

    printf("long:\n");
    printBar(48);
    printf("\tbytes :\t%lu\n", sizeof(unsigned long));
    printf("\tmin   :\t%u\n", 0);
    printf("\tmax   :\t%lu\n", ULONG_MAX);
    printBar(48);

    return 0;
}