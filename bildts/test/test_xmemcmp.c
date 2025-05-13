#include <stdio.h>
#include "memcmp.h"

void testMemcmp(const char* label, const void* s1, const void* s2, size_t len) {
    int result = myMemcmp(s1, s2, len);
    printf("%s: myMemcmp returned: %d\n", label, result);
}

int main() {
    const char s1[] = "hello";
    const char s2[] = "hello";
    const char s3[] = "hellq";
    const char s4[] = "hellp";
    const char s5[] = "hel";

    testMemcmp("Test 1 - Equal", s1, s2, sizeof(s1));
    testMemcmp("Test 2 - s1 > s3", s1, s3, sizeof(s1));
    testMemcmp("Test 3 - s3 < s1", s3, s1, sizeof(s1));
    testMemcmp("Test 4 - s1 > s4", s1, s4, sizeof(s1));
    testMemcmp("Test 5 - s5 shorter", s1, s5, sizeof(s5));

    return 0;
}
