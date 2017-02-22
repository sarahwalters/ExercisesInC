## Reflection 2 -- second sprint

### Sprint Reflection
We had a bit of trouble scheduling work this sprint -- most of the solving work depended on the ability to "try" Rubik's cube rotations in C, but we didn't realize as much until late in the sprint. It only took me a couple hours the day we identified the problem to write a connector library which provides the rotation functions to the C logic -- but it would've been a more productive sprint if we'd realized where the sticking point was earlier on. Our kaizen for the sprint has to do with figuring out which work is on the critical path and scheduling that work so we're each being maximally useful & so we're not blocking ourselves.

I'm not sure I articulated this goal early on, but one of my goals for the class is to get comfortable developing & debugging & using existing libraries/code in a C environment. I've been doing most of the integration work for the project with that goal of mine in mind, and I'm feeling much more comfortable than I did initially -- in particular, I feel like I understand how makefiles work and why they're used. Our makefile is a little more complicated than some because we're using the Google gtest library to test our code, and I started from gtest's sample makefile, figured out what it was doing and why, and modified it to suit our project.

### Head First C exercises
I worked on Head First C chapters 2.5, 3 & 4 in this sprint.
- [Chapter 2.5 exercises](../exercises/ex02.5)
- [Chapter 3 exercises](../exercises/ex03)
- [Chapter 4 exercises](../exercises/ex04)

### Think OS Reading Questions
I worked on Think OS chapters 3 & 4 in this sprint.
- [Chapter 3 reading questions](../reading_questions/chapter3.md)
- [Chapter 4 reading questions](../reading_questions/chapter4.md)

### Exam Question & Solution

Q: Assume that a block pointer takes up 4 bytes, that block size is 8 KiB, and that an inode has 12 block pointers, one indirection block pointer, one double indirection block pointer, and one triple indirection block pointer. How big of a file can one inode represent?

A:
Firstly: one block is 8 KiB, or 8 * 2^10 = 2^13 bytes. A block pointer takes up 4 bytes, so a block dedicated entirely to block pointers can store 2^11 block pointers.

The inode can reference 12 blocks because of direct block pointers.

The inode has one pointer to an indirection block which can reference 2^11 blocks.

The inode has one pointer to a double indirection block which can reference 2^11 indirection blocks, each of which can reference 2^11 blocks -- so, the double indirection block can reference 2^11 * 2^11 blocks.

The inode has one pointer to a triple indirection block which can reference 2^11 double indirection blocks, each of which can reference 2^11 indirection blocks, each of which can reference 2^11 blocks -- so, the triple indirection block can reference 2^11 * 2^11 * 2^11 blocks.

So, all told, the inode can reference 12 + 2^11 + 2^22 + 2^33 blocks -- which is precisely 8,594,130,956 blocks, but the 2^33 term dominates so I'm going to use it for the sake of estimation.

Assuming a block is 8 KiB, the inode can reference about 2^33 blocks * (8 * 2^10) bytes/block -- or, 2^33 * 2^13 = 2^46 bytes. 2^46 bytes is 2^6 * (2^10)^4 = **64 TiB**. (impractically large!)

[Checking my 2^33 approximation with a calculator: 8,594,130,956 blocks * (8 * 2^10) bytes/block = 7.04 * 10^13 bytes. Sure enough -- 64 TiB is 7.04 * 10^13 bytes].
