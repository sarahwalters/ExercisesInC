## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

5 bits can only specify 2^5 = 32 letters, so 6 bits are needed to specify a letter in the Georgian alphabet.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits. Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 (4,294,967,296) characters can be represented.

3) What is the difference between "memory" and "storage" as defined in Think OS?

Memory is volatile and storage is non-volatile (i.e. storage persists when a computer is turned off; memory does not).

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is 2^30 = 1,073,741,824 bits; a GB is 10^9 bits. A GiB is just over 7% larger than a GB.

5) How does the virtual memory system help isolate processes from each other?

Instead of accessing physical addresses directly, processes access virtual addresses which are translated into physical addresses by the memory management unit. The virtualization provides each process with the illusion that it has its own consecutive address space, even if behind the scenes the memory management unit is sharing code between processes or interleaving addresses which are used by different processes.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

Both the stack and the heap expand. If they started at specific memory addresses and grew in the same direction, each would be individually bounded; if they start at opposite ends of the address space and grow towards each other, they're collectively rather than individually bounded. With the stack and the heap growing towards each other, you'll never encounter a case where the heap is out of room but the stack isn't using all of its space -- or vice versa.

7) What Python data structure would you use to represent a sparse array?

You could use a dictionary which maps from (coordinate tuple) to (value) to represent a sparse array -- making sure to keep track of the size of the sparse array using a couple extra variables.

8) What is a context switch?

A context switch involves the operating system interrupting a running process, saving its state, and then running another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

On my computer:
Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7ffcb8f67b54
Address of p is 0x179d010

On your computer:
Address of main is 0x40057c (almost the same as mine)
Address of global is 0x60104c (the same as mine)
Address of local is 0x7fffd26139c4 (similar to mine)
Address of p is 0x1c3b010 (similar to mine)

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).

I added a second call to `malloc`; the original pointer `p` has the address `0x1ffb010` and the new pointer has the address `0x1ffb0a0`. The heap does grow up, towards larger addresses.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.

I added a function which prints a local variable and called it from the main method. The local variable within `main` has the address `0x7fff1c0a8bac`; the local variable within the new method has the address `0x7fff1c0a8b8c`. The stack does grow down, towards smaller addresses.

3) Choose a random number between 1 and 32, and allocate two chunks with that size. How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

It looks to me like, when the number is between 1 and 24 inclusive, the space between them is 0x20, and when the number is between 25 and 32 inclusive, the space between them is 0x30. I'm not sure why that transition is where it is.
