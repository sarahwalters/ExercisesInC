## Reflection 1 -- first sprint

### Sprint Reflection
We're following eduScrum closely and finding that it's working pretty well for us. Our kaizen for Sprint 1 is to make sure that everyone leaves every meeting with a defined project task to work on. Especially towards the beginning of the first sprint we weren't particularly formal about this, which meant that there were a couple between-class stretches during which I wanted to work on the project but didn't know what would be useful to do. Since our Sprint 1 retrospective, we've been paying attention to the kaizen and things have been better.

Our goal for Sprint 1 was to put together a solid basis to build on top of -- we were worried about integrating graphics with a Rubik's cube API written in C++ with solving algorithms written in C, so we approached integration first. We met our goal -- as of the end of sprint 1, we have:
- a nice OpenGL graphical display of a cube which the user can spin in space using arrow keys.
- an API, written in C++, which controls the state of the graphical display. Right now, the cube manipulation commands e.g. "spin the right face clockwise" are just hooked up to keyboard events; eventually we'll call them from the C logic.
- a placeholder logic function, written in C, which can be called from the C++ main method.
- a workflow which includes a Makefile, a test suite, and a linter.

We're starting to work on cube-solving algorithms, and we don't think a MVP cube-solving algorithm will take us the rest of the project time, so we might have at least part of a sprint to extend our project past MVP. We have a few ideas for extensions: we could implement several logic algorithms & compare them, or we could generalize to solve N x N cubes instead of just 3 x 3 cubes. Per Ben's suggestion, I think we should start setting up to approach those extensions during Sprint 2 instead of waiting for the MVP to be done or for Sprint 3 to start.


### Head First C exercises
I worked on Head First C chapters 1 & 2 in this sprint.
- [Chapter 1 exercises](../exercises/ex01)
- [Chapter 2 exercises](../exercises/ex02)


### Think OS Reading Questions
I worked on Think OS chapters 1 & 2 in this sprint.
- [Chapter 1 reading questions](../reading_questions/chapter1.md)
- [Chapter 2 reading questions](../reading_questions/chapter2.md)


### Exam Question & Solution

(Draws on Head First C chapter 2)

Q: The following functions are intended to read user input into a buffer.

```
void read_input_1(char *prompt, char *format, char *buffer) {
    puts(prompt);
    scanf(format, buffer);
}
```

```
char *read_input_2(char *prompt, char *format) {
    char buffer[3];
    puts(prompt);
    scanf(format, buffer);
    return buffer;
}
```

Which is the better implementation? Why?

A: `read_input_1` is a better implementation, for two reasons.
- `read_input_1` lets the user specify both the formatting string `*format` and the buffer to read into `*buffer`. It's on the user to make sure that the formatting string prevents buffer overflow. By contrast, `read_input_2` specifies a buffer of length 3, but lets the user specify the formatting string -- it isn't clear to the user (especially without documentation) that the formatting string has to match the buffer.
- `read_input_2` instantiates a local variable `buffer` which is allocated using stack memory -- then it returns that variable. It's unsafe to return a local variable which is in stack memory because the stack will be unwound when the function returns, so the caller isn't guaranteed access to the intended return value.
