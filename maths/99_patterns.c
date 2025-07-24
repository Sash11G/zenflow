#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void table(int n)
{
    int i;
    for (i=1;i<1000;i++)
    {
        printf("%d\n", n*i);
    }
}


int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    getchar();
    table(n);

    return 0;
}

