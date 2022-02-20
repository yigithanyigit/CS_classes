#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int arr[3][2] = {{5,2}};
    arr[1][0] = 8;
    arr[1][1] = 4;
    printf("%d", arr[1][0]);
    return 0;
}