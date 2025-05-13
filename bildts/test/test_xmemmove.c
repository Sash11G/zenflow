#include <stdio.h>
#include "xmemmove.h"

int main() {

    char buff[0xff] = "HELLO      !";
    char buff2[0xff] = "      HOMER!";
    
    printf("Before:\n%s\n%s\n", buff, buff2);
    xmemmove(buff + 6, buff2 + 6, 5);
    xmemmove(buff2, buff, 5);
    printf("After:\n%s\n%s\n", buff, buff2);

    return 0; 
}
