#include <stdio.h>

typedef struct {
    int sqrFeet;
    int numBed;
    int numBath;
} House;

int GetHousePrice(House *pHouse)
{
    return pHouse->sqrFeet * 1000 + pHouse->numBed * 10000 + pHouse->numBath * 5000;
}

int main()
{
    House aptoForum = {45, 2, 1};
    int arr[] = {1,2,3,4,5,6};
    size_t len = sizeof(arr) / sizeof(int);
    int *pArr = arr;
    for (size_t i; i < len; i++) {
        if (i == 0) {
            printf("{");
        }
        printf("%d, ", arr[i]);
    }

    if (sizeof(arr) > 0) {
        printf("\b\b}\n");
    }
    
    while ((pArr - arr) < len) {
        if ((pArr - arr) == 0) {
            printf("{");
        }
        printf("%d, ", *pArr++);
    }

    if (sizeof(arr) > 0) {
        printf("\b\b}\n");
    }
    House *pHouse = &aptoForum;
    printf("Sqr: %d, bed: %d, bath: %d TOTAL = %d\n", pHouse->sqrFeet,\
            pHouse->numBed,\
            pHouse->numBath,\
            GetHousePrice(pHouse));
    return 0;
}
