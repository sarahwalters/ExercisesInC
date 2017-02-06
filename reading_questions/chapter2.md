## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

Even though paper is clearly an expendable resource and it's possible to run out of it, the people who restock supplies at Olin present the illusion that the printers in the academic center never run out of paper -- there's almost always plenty of paper, and if there's not, anyone can send an email requesting more.

2) What is the difference between a program and a process?

A program is a collection of source code which can be run. A process is an abstraction which encapsulates running programs.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

Processes isolate programs from each other so that one running program doesn't accidentally impact other running programs. The process abstraction creates the illusion that each program is running on its own individual computer.

4) What is the kernel?

The kernel is the part of the operating system responsible for core capabilities -- it's the lowest level of software.

5) What is a daemon?

A daemon is a process which runs in the background instead of running interactively, facing the user.
