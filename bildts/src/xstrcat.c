#include <stddef.h>

void* xstrcat(void* dst, const char* src)
{
    char* a = dst;

    while (*a) {
        a++;
    }

    while (*src) {
        *a++ = *src++;
    }
    *a = 0;

}

int printf(const char*, ...);

int main() 
{
    char buff[0xff] = "Hello";
    char str[] = " World!";
    
    xstrcat(buff, str);
    printf("%s\n", buff);

    xstrcat(buff, " Wtf... Unexpected.");
    printf("%s\n", buff);

   return 0;
}
