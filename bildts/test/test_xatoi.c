// Auto-created test file for altatoi
#include <stdio.h>
#include <string.h>
#include "xatoi.h"


int main() {
    char buff[0xff];
    int res;
    while (1) {
        printf("Type a number (Ctr+C to quit): ");
        fgets(buff, sizeof(buff), stdin); 
        buff[strcspn(buff, "\n")] = '\0';

        res = xatoi(buff);
        printf("String: %s\tInteger: %d\n", buff, res);
    }
    return 0;
}
