#include <stddef.h>

void* xmemmove(void* dst, const void* src, size_t len) 
{
    unsigned char* a = dst;
    const unsigned char* b = src;
    if (a < b) {
        while (len--) {
            *a++ = *b++;
        }
    } else {
        while (len--) {
            a[len] = b[len];
        }
    }
    return dst;
}
