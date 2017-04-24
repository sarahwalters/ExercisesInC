/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}


int read_element(int *array, int index) {
    int x = array[index];
    return x;
}


int main ()
{
    /*
     * I'm not sure what you mean by "fix" because I'm not
     * sure what the intent of this code is other than to demonstrate
     * errors / misuses. This version compiles & runs with no errors,
     * and does not leak memory, but it doesn't really "do anything".
     *
     * I'm leaving the code I'm not using here, commented-out, for reference.
     */

    // int never_allocated;
    int *free_twice = malloc (sizeof (int));
    int *use_after_free = malloc (sizeof (int));
    int *never_free = malloc (sizeof (int));
    int array1[100];
    int *array2 = malloc (100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    read_element(array1, 0);
    read_element(array1, 99);

    // but it does bounds-check dynamic arrays
    read_element(array2, 0);
    read_element(array2, 99);

    // and it catches use after free
    *use_after_free = 17;
    free(use_after_free);

    // never_free is definitely lost
    *never_free = 17;
    free(never_free);

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // free_anything(&never_allocated);

    free(array2);
    free(free_twice);

    return 0;
}
