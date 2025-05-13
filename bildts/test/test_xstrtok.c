// Auto-created test file for alttok
#include <stdio.h>
#include <string.h>
#include "xstrtok.h"

#define DELIMITERS " \t\n\r\v\f,.;:!?()[]{}<>-_+*/\\|&^%$#@~=~`"

int main() {
    char input[1024];
    char* ptr;
    char* token;
    int tokCount = 1;

    while (1) {
        printf("Write string to tokenize (Ctrl+C to exit): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        if (*input) {
            input[strcspn(input, "\n")] = '\0';
            ptr = input;
        }

        while ((token = alttok(&ptr, DELIMITERS)) != NULL) {
            if (*token) {
                printf("Token %d: %s\n", tokCount++, token);
            }
        }
        tokCount = 1;
    }

    return 0;
}
