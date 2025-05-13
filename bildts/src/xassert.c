#include <stdio.h>
#include <stdlib.h>
#ifndef NDEBUG
#define xassert(expr) do {\
    if (!(expr)) {\
        printf(\
            "%s, file %s, function %s, line %d\n",\
            #expr,\
            __FILE__,\
            __func__,\
            __LINE__\
        );\
        abort();\
    }\
} while(0);
#else 
#define xassert(expr) ((void)0)
#endif

int main() {
    xassert(1 + 1 != 2);
    xassert(1 + 1 == 2);
    return 0;
} 
