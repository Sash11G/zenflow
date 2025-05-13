#include <stddef.h>
#include <stdio.h>
#include <string.h>

char* xstrstr(const char* haystack, const char* needle) 
{
    if (!*needle) return (char*)haystack;
    
    while (*haystack) {
        const char* a = haystack;
        const char* b = needle;

        while (*a && *b && (*a == *b)) {
            a++;
            b++;
        }

        if (!*b) {
            return (char*)haystack; 
        }

        haystack++;
    }
    return NULL;

}

int printf(const char* str, ...);


int main(void) 
{
    char mystr[3][50];
        
    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                printf("Enter haystack: ");
                break;
            case 1:
                printf("Enter needle #1: ");
                break;
            case 2:
                printf("Enter needle #2: ");
                break;
            default:
                break;
        }

        fgets(mystr[i], 50, stdin);
        mystr[i][strcspn(mystr[i], "\n")] = '\0';        
    }

    char* a = xstrstr(mystr[0], mystr[1]);
    char* b = xstrstr(mystr[0], mystr[2]);
    
    printf("%s\n", mystr[0]);
    printf("%s -> %s\n", mystr[1], a ? "true" : "false");
    printf("%s -> %s\n", mystr[2], b ? "true" : "false");
    
    return 0;
}   






