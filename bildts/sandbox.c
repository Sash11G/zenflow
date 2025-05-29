// Auto-created test file for altmemcpy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/xatoi.h"


int main() {

    char *arr = malloc(sizeof(char) * 4);
    int num;
    char buff[50];
    printf("%zu\n", sizeof(char));
    for (int i = 0; i < sizeof(arr); i++) {
        fgets(buff, 50, stdin);
        num = atoi(buff);
        printf("%d\n", num);
        arr[i] = num;
    }
    num = 0;
    while (*arr) {
        printf("%d -> ", *arr);
        arr++;
        num++;
    }    
    printf("NULL\n");
    arr -= num;
    printf("curr: %d\n\n", *arr);
    while (*arr) {
        printf("%d -> ", *arr);
        arr++;
        num++;
    }
    printf("NULL\n");
    

    return 0;
}
