#include <stdio.h>
#include <stdlib.h>ß

// IMPORTING time.h for calculate elapsed time
#include <time.h>

#define ARRAY_SIZE 10
#define STARTING_INDEX 2

void fillArray(int arr[])
{
    for (int i = STARTING_INDEX; i < ARRAY_SIZE; i++)
    {
        arr[i] = i;
        //printf("%d ", arr[i]);
    }
    printf("ARRAY FILLED\n");
}

void solve(int arr[], int index)
{
    if (arr[index] != 0)
    {
        for (int i = index * 2; i < ARRAY_SIZE; i += index)
        {
            arr[i] = 0;
        }
    }
}

int main()
{
    int* arr = malloc(ARRAY_SIZE * sizeof(int));

    
    fillArray(arr);
    int *b = &arr + 2;
    printf("address : %d   normal : %d            %d  \n", arr + 2, &arr[2], *arr);
    arr += 3;
    printf("address : %d   normal : %d            %d  ", arr + 2, &arr, *arr);



    clock_t t;
    t = clock();

    for (int i = STARTING_INDEX; i < ARRAY_SIZE; i++)
    {
        solve(arr, i);
        if (arr[i] != 0)
        {
        }
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("The program took %f seconds to execute", time_taken);

    free(arr);

    return 0;
}