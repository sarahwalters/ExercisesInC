## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages commonly have dynamic typing, while compiled languages are usually limited to static types.

2) Name two advantages of static typing over dynamic typing.

- Static typing helps the programmer find errors more efficiently -- type errors are caught at compile time, not at run time.
- Static typing lets programs run faster -- once a program is running, it can assume that variables have the types they are declared to have, so typechecking while running isn't necessary. (Languages with dynamic typing have to typecheck at runtime).

3) Give an example of a static semantic error.

A static semantic error might tell you that a function is being called with the wrong number of arguments.

4) What are two reasons you might want to turn off code optimization?

- Code optimization takes time, so if you're developing code and iterating quickly by running the code frequently, your process will be faster if you don't have to wait for optimization to happen.
- The more code optimization you're asking for, the more the compiler is changing your code on its way to machine language. Optimization isn't supposed to alter the function of your code, but the more you're letting the optimization process change your code, the more likely it is that function is altered accidentally. ThinkOS recommends turning off optimization while you develop, then turning it on again at the end and making sure your tests still pass.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Running `gcc` with `-S` compiles to Assembly. `gcc` is usually configured to generate code for the architecture of the computer it's running on -- different architectures correspond to different flavors of Assembly.

6) If you spell a variable name wrong, or if you spell a function name wrong,
the error messages you get might look very different.  Why?

The compiler catches variable name misspellings, but the linker catches function name misspellings.

7) What is a segmentation fault?

A segmentation fault occurs when you try to operate on a memory location in a way that isn't allowed (e.g. you try to write to a constant).
