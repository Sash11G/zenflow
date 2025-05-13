#include <stddef.h>

void* xmemset(void* buffer, int value, size_t len)
{
    unsigned char* a = buffer;
    while (len--) {
        *a++ = value;
    }
    return buffer;
}

int printf(const char*, ...);

int main(void)
{
    char buffer[0xff];
    xmemset(buffer, 'A', 10);
    xmemset(buffer + 10, 'B', 10);
    printf("%s\n", buffer);

    return 0;
}
