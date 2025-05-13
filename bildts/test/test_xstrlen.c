// Auto-created test file for altstrlen
#include <stdio.h>
#include "strlen.h"

void testStrlen(const char* str) {
    size_t result = altstrlen(str);
    printf("[altstrlen test] Input: \"%s\"\nResult: %zu\n\n", str, result);
}


int main() {
    const char test1[] = "";
    const char test2[] = "hello";
    const char test3[] = "with spaces";
    const char test4[] = "123\0hidden";
    const char test5[] = "👋🌍"; // Multibyte, optional
    
    testStrlen(test1);
    testStrlen(test2);
    testStrlen(test3);
    testStrlen(test4);
    testStrlen(test5);

    return 0;
}
