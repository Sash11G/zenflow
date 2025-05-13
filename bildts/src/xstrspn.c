#include <stdio.h>
#include <string.h>

size_t xstrspn(const char* str, const char* set)
{
    size_t i, j;
    
    for (i = 0; str[i]; i++) {
        for (j = 0; set[j]; j++) {
            if (str[i] == set[j]) {
                break;
            }
        }
        if (!set[j]) {
            break;
        }
    }
    
    return i;
}

int main(void)
{

    char buff[] = "12345abcdef";
    char cset[] = "1234568790";
    size_t i = xstrspn(buff, cset);
    printf("%zu\n", i);

    return 0;
}
