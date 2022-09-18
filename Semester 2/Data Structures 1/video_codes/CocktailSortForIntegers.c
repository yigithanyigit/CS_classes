#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void cocktailSort(int *arr, int size);

int main()
{
    // ->
    int arr[] = {3,5,2,1,4,8,9,6,15,35,1,7,8};
    int size = sizeof(arr) / sizeof(int);
    cocktailSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void swap(int *a, int *b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void cocktailSort(int *arr, int size)
{
    int swapped = 1;
    int i;
    while (swapped)
    {
        swapped = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(&arr[i], &arr[i - 1]);
                swapped = 1;
            }
        }
        
    }
}