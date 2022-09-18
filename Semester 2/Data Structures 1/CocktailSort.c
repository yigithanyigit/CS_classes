#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringSwap(char *a, char *b)
{
    //printf("%s %s ", *a, *b);
    char *temp = *a; 
    *a = *b; 
    *b = temp;
    //printf("%s %s", *a, *b);
   
}

void integerSwap(int *a, int *b)
{
    // printf("%d %d ", a, b);
    int *temp = *a;
    *a = *b;
    *b = temp;
    // printf("%d %d  ", a, b);
}

void cocktailSortForStrings(char **arr, int size)
{
    int i, swapped = 1;
    int ctr = 0;
    while (swapped)
    {
        swapped = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (strcmp(arr[i], arr[i + 1]) > 0)
            {
                stringSwap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (strcmp(arr[i], arr[i - 1]) < 0)
            {
                stringSwap(&arr[i], &arr[i - 1]);
                swapped = 1;
            }
        }
        ctr++;
    }
}

void cocktailSortForIntegers(int *arr, int size)
{
    int i, ctr = 0;
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                integerSwap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        for (i = size - 1; i > 0; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                integerSwap(&arr[i], &arr[i - 1]);
                swapped = 1;
            }
        }
        ctr += 1;
    }
}

int main()
{
    //int arr[] = {3, 2, 5, 8, 15, 3, 8, 6, 4, 8, 2, 9, 4, 1, 2, 5, 6};
    //int arr[] = {1,2,3,4,5};
    //int size = sizeof(arr) / sizeof(int);
    char *arr[] = {"deneme", "hahahah", "abc", "emre", "ahmet", "mehmet","vural"};
    int size = sizeof(arr) / sizeof(char*);
    //cocktailSortForIntegers(arr, size);
    cocktailSortForStrings(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%s ", arr[i]);
    }
}