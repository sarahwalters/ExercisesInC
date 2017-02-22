/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void print_local ()
{
    int local = 5;
    printf ("Address of local, from function, is %p\n", &local);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
    void *p2 = malloc(128);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    printf ("Address of p2 is %p\n", p2);

    print_local ();

    void *chunk1 = malloc(32);
    void *chunk2 = malloc(32);
    printf ("Address of chunk1 is %p\n", chunk1);
    printf ("Address of chunk2 is %p\n", chunk2);

    return 0;
}
