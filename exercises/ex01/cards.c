/*
   Questions:
   - is it kosher to use the word "string" in C documentation?
     I know they're really char arrays, but "string" is a useful
     abstraction of a word.
   - what naming conventions do you prefer we use, if any?
*/


#include <stdio.h>
#include <stdlib.h>

/* Reads command line input into a buffer.
   *prompt: pointer to the input prompt string
   *format: pointer to the input formatting string
   *buffer: pointer to the array which holds the input
*/
void read_input(char *prompt, char *format, char *buffer) {
    puts(prompt);
    scanf(format, buffer);
}

/* Gets the value associated with a card name
   *card_name points to a string representing card name
   returns an integer representing the value of the card
*/
int get_card_value(char *card_name) {
    int val = 0;
    switch (card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            break;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
            }
    }
    return val;
}

/* Updates a card count based on card value
   card_value represents the integer value of a card
   *count is a pointer to the counter the function updates
*/
void update_card_count(int card_value, int *count) {
    if ((card_value > 2) && (card_value < 7)) {
        *count = *count + 1;
    } else if (card_value == 10) {
        *count = *count - 1;
    }
    printf("Current count: %i\n", *count);
}

/* Performs card counting upon user input
*/
int main() {
    char card_name[3]; /* buffer which is reused for user input */
    int val; /* reused to store card values */
    int count = 0; /* used to track card count */
    do {
        read_input("Enter the card name: ", "%2s", card_name);
        val = get_card_value(card_name);
        update_card_count(val, &count);
    } while (card_name[0] != 'X');
    return 0;
}
