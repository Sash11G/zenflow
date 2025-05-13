#include "xstrtok.h"
#include <stddef.h>

char* alttok(char** strptr, const char* delim) {
    char* str = *strptr;
    if (str) {
        size_t i, j;
        for (i = 0; str[i]; i++) {
            for (j = 0; delim[j]; j++) {
                if (str[i] == delim[j]) {
                    str[i] = 0;
                    *strptr = str + i + 1;
                    return str;
                }
            }
        }

        if (*str) {
            *strptr = NULL;
            return str;
        }
    }
    return NULL;
}
