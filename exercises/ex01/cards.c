#include <stdio.h>
#include <stdlib.h>

void readInput(char *prompt, char *format, char *buffer) {
    puts(prompt);
    scanf(format, buffer);
}

int getValue(char *card_name) {
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

void updateCount(int val, int *count) {
    if ((val > 2) && (val < 7)) {
        *count = *count + 1;
    } else if (val == 10) {
        *count = *count - 1;
    }
    printf("Current count: %i\n", *count);
}

int main() {
    char card_name[3]; // buffer for user input
    int count = 0;
    do {
        readInput("Enter the card name: ", "%2s", card_name);
        int val = getValue(card_name);
        updateCount(val, &count);
    } while (card_name[0] != 'X');
    return 0;
}
