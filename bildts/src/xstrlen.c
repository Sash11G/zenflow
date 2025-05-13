#include <stddef.h>
#include "strlen.h"

size_t altstrlen(const char* str) {
    size_t i;
    for (i = 0; str[i]; i++);
    return i;
}
