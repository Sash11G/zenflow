#include <stddef.h>

int myMemcmp(const void* s1, const void* s2, size_t len)
{
    const unsigned char* a = s1;
    const unsigned char* b = s2;

    while (len--) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return 0;
}
