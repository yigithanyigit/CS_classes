#include <stdio.h>
#include <stdlib.h>

/*
 *
 *
 * YOU CAN NOT DEFINE NEW ARRAY
 *
 */

void solve(char *arr, char pattern[]);
void get_array(char **arr);

int main()
{
    char arr1[] = "1010110101101100010101011101010110110001010101111101101011011000101010101101100010101011110111100010101011101"; // 110
    char pattern[] = "101011011000101010111";
    int i;

    char *arr = (char *) malloc(20);
    get_array(&arr);

    solve(arr, pattern);
    for (i = 0; arr[i] != '\0'; i++)
    {
        printf("%c", arr[i]);
    }
    printf(" %d ", i);
}

void get_array(char **arr)
{
    FILE *ptr;
    char ch;
    int counter;

    ptr = fopen("pattern.txt", "r");

    if (NULL == ptr)
    {
        printf("File can not open");
    }

    fseek(ptr, 0, SEEK_END);
    counter = ftell(ptr);
    printf("%d ", counter);

    ptr = fopen("pattern.txt", "r");

    *arr = (char *)realloc(*arr, counter + 1);

    while (fgets(*arr, counter + 1, ptr) != NULL)
    {
        // printf("%s ", *arr);
    }
    fclose(ptr);
}

void solve(char *arr, char pattern[])
{
    int i = 0;

    for (; arr[i] != '\0'; i++)
    {
        int j;
        for (j = 0; pattern[j] != '\0'; j++)
        {
            if (arr[i + j] != pattern[j])
            {
                break;
            }
        }

        if (pattern[j] == '\0')
        {
            int q;
            for (q = i; arr[q] != '\0'; q++)
            {
                arr[q] = arr[q + j];
            }
            arr[q] = '\0';
            solve(arr, pattern);
        }
    }
}