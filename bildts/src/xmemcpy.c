#include <stddef.h>

void* xmemcpy(void* dst, const void* src, size_t n)
{
    char* a = dst;
    const char* b = src;

    while (n--) {
        *a++ = *b++;
    }
    return dst;
    
}

