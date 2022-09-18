#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b);
void cocktailSort(char **arr, int size);

int main()
{
    char *arr[] = {"cocktail", "sort", "acne", "computer", "jake", "wifi"};
    int size = sizeof(arr) / sizeof(char*);
    cocktailSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%s ", arr[i]);
    }
    return 0;
}

void swap(char *a, char *b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void cocktailSort(char **arr, int size)
{
    int swapped = 1;
    int i;
    while (swapped)
    {
        swapped = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (strcmp(arr[i], arr[i + 1]) > 0)
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (strcmp(arr[i], arr[i - 1]) < 0)
            {
                swap(&arr[i], &arr[i - 1]);
                swapped = 1;
            }
        }
    }
}