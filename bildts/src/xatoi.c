#include <stddef.h>
#include <string.h>
#include <stdio.h>

int xatoi(const char* str) {
    int result = 0;
    int sign = 1;

    while ((*str < '0') | (*str > '9')) {
        if (*str == '-') break;
        str++;
    } 

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = (result * 10) + (*str - '0');
        str++;
    }
    return result * sign;
}


