/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* Returns an array of size SIZE where the value at each index is 42

   Returning array gives you the warning "Function returns address of local variable".
   Inside the function foo, you're allocating memory on the stack -- and the stack will
   be unwound when the function returns, so the local variable array won't be safe
   for the caller to access.
*/
int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	   array[i] = 42;
    }
    return array;
}

/* Creates but does not return an array of size SIZE where
   the value at each index is the index
*/
void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	   array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    /* Experiment 3 (with print statements):
       The two printf("%p\n", array); statements result in the same address. This
       means that foo and bar are using the same memory to store array.

       Naively, you'd expect the for loop below to print the number 42 five times
       -- but the variable array inside of the function foo is allocated on the
       stack and unwound when foo returns, so the memory at address array can be
       overwritten by the next function call. In this case, the next function call
       is bar, and the memory in array is overwritten to hold [0, 1, 2, 3, 4].
    */

    /* Experiment 4 (without print statements):
       I'm trying to figure out why this happens as it does -- it looks to me like if
       you're printing in foo or in bar or in both, you get the behavior described in
       Experiment 3, but if you're printing in neither, you get a list of numbers
       which isn't [42, 42, 42, 42, 42] or [0, 1, 2, 3, 4]. In fact, it's not the same
       list every time you compile & run.

       My guess is that if you're printf-ing the address of the array which foo and bar
       both use, the compiled assembly code loads that address into a register and
       jumps to the printf function and jumps back -- and the compiler which generates
       assembly tries to be "safe" about the address so it's not used internally
       for something else before the printf jump, but if you're never printf-ing
       the address, the compiler is willing to reuse the address for anything.
    */
    for (i=0; i<SIZE; i++) {
	   printf("%d\n", array[i]);
    }

    return 0;
}
