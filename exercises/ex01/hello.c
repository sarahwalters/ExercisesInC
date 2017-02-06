/* Sarah Walters
   Exercises in C 01 Solution
   Software Systems Spring 2017
*/


#include <stdio.h>
#include <stdlib.h>

/* Experiment 11
   This is the segment of Assembly I think is relevant to the
   declaration of x:
    movl    $5, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, %esi
   It takes three instructions to get 5 into %esi (which is where
   I think it ends up).
*/

/* Experiment 12
   With optimization, this is the segment of Assembly I think is
   relevant to the declaration of x:
    movl    $5, %edx
   It takes 1 instruction to get 5 into %edx (which is where I
   think it ends up).
*/

/* Experiment 13
   Without optimization, the line of Assembly which prints x is
    call    printf

   With optimization, the line of Assembly which prints x is
    jmp __printf_chk

   I think the optimized version recognizes that the printf is the
   last thing that happens in the main method, so using the call
   stack to make sure that the program counter can return to the
   line after the function call isn't strictly necessary -- it's
   okay to just jump directly to the print function.
*/

/* Experiment 14
   Without optimization, the lines of Assembly which set y are:
    movl    $5, -8(%rbp)
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, %esi
   It takes 6 instructions to move 5 into the proper register, then
   to add 1 and move the result into the proper register.

   With optimization, the line of Assembly which sets y is:
    movl    $6, %edx
   The optimization process recognizes that 5+1 is 6 and handles
   the arithmetic.

   I can conclude that the optimization process can recognize when
   a value is used solely to produce another value and can handle
   that computation at compile-time instead of waiting for runtime.
*/

int main() {
    int x = 5;
    int y = x + 1;
    printf("%i\n", y);
}
