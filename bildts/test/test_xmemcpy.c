// Auto-created test file for altmemcpy
#include <stdio.h>
#include "memcpy.h"


int main() {
    printf("Test altmemcpy\n"); 

    const int arr[4] = {1,3,5,7};
    int buff[4] = {0};

    memCop(buff, arr, 4 * sizeof(int));

    for (int i = 0; i < 4; i++) {
        printf("%d ", buff[i]);
    }
    printf("\n");
    return 0;
}
