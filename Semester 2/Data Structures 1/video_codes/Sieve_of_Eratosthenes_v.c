#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE = 400000000;
#define STARTING_INDEX 2

void fillArray(int arr[])
{
    for (int i = STARTING_INDEX; i < ARRAY_SIZE; i++)
    {
        arr[i] = i;
    }
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

int main(void)
{

    int *arr = malloc(ARRAY_SIZE * sizeof(int));
    fillArray(arr);

    clock_t t;
    t = clock();

    for (int i = STARTING_INDEX; i < ARRAY_SIZE; i++)
    {
        solve(arr, i);
        // if(arr[i] != 0)printf("%d\n", arr[i]);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("The program took %f seconds to execute", time_taken);

    return 0;
}