/* Author: Sarah Walters
 *
 * TEE
 * Mimics the Unix "tee" command -- reads standard input and writes to
 * standard output as well as one or more files.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *file_mode = "w";

    // handle flags
    // -a & -i are valid flags; neither needs arguments
    int ch;
    while ((ch = getopt(argc, argv, "a")) != -1) {
        switch (ch) {
            // append output to end of file instead of writing over it
            case 'a':
                file_mode = "a";
                break;

            // ignore interrupts
            case 'i':
                printf("-i flag is not handled yet\n");
                break;
        }
    }

    // skip handled flags
    argc -= optind;
    argv += optind;

    // read a line from stdin
    char *buffer = NULL;
    int read;
    size_t len;
    read = getline(&buffer, &len, stdin);

    // tee buffered input (print & write to file(s))
    if (read != -1) {
        puts(buffer);

        int i;
        FILE *file;
        for (i=0; i<argc; i++) {
            file = fopen(argv[i], file_mode);
            fprintf(file, "%s\n", buffer);
            fclose(file);
        }
    } else {
        printf("No line read\n");
        return 1; // return error
    }

    printf("Size read: %d\nLen: %zu\n", read, len);
    free(buffer);
    return 0;
}

/* Question 3: Reflect
   I made a silly mistake which slowed me down -- ch == getopt(...) instead of
   ch = getopt(...). It looked like the while loop wrapping getopt was running forever.
   I printed ch & got varying numbers around 34000, which confused me -- so I examined
   the setting of ch more closely and noticed the == instead of =.

   I haven't figured out how to handle the reading of multiple lines from stdin -- looks
   like I'd need to understand malloc & calloc to do so without picking an arbitrary buffer size.
   I'll come back & add to this tool so it can read more than a single line from stdin
   once I understand those things.
 */

/* Question 4: Compare solution to the "real thing"
   - The "real thing" helps you if you use an option which isn't supported, by printing
     "usage: tee [-ai] [file ...]"
   - The "real thing" uses O_WRONLY / O_APPEND etc. constants instead of hard-coded strings
   - The "real thing" uses "warn" to signal errors, instead of printing error messages
   - The "real thing" solves the not-sure-how-much-input-you'll-get problem by defining
     a buffer and reading iteratively until there isn't more to read
 */

