#include <stdio.h>
#include <stdlib.h>

void solve(char *arr, char pattern[]);
int size();
void get_array_with_size(char *arr, int size);
void get_array(char **arr);

int main()
{

    char arr1[] = "10101101011011000101010111010101101100010101011111011010110110001010101011011000101010111101111000101010111010011120101011010110110001010101110101011011000101010111110110101101100010101010110110001010101111011110001010101110111200121010110101101100010101011101010110110001010101111101101011011000101010101101100010101011110111100010101011101";
    char pattern[] = "101011011000101010111";

    /*
    *
    * Char by char initialize block
    *
    /*
    int size1 = size();
    char *arr = (char *)malloc(size1);
    get_array_with_size(arr, size1);
    */

    /*
    *
    *
    * String initiliaze
    * 
    * */
    int i;
    char *arr = (char *)malloc(10);
    get_array(&arr);
    printf("%u", &arr1);
    solve(arr1, pattern);

    for (i = 0; arr1[i] != '\0'; i++)
    {
        printf("%c", arr1[i]);
    }
    printf(" %d ", i);
    free(arr);
}

/*
*
*   Get Char by Char
*
*
/*
int size()
{

    FILE *ptr;
    char ch;

    int counter = 0;

    ptr = fopen("pattern.txt", "r");

    if (NULL == ptr)
    {
        printf(" - 1 file can not open");
        return -1;
    }

    while (ch != EOF)
    {
        ch = fgetc(ptr);
        counter++;
    }
    fclose(ptr);
    free(ptr);
    return counter;
}

void get_array_with_size(char *arr, int size)
{

    FILE *ptr;
    char ch;
    int i;

    ptr = fopen("pattern.txt", "r");

    if (NULL == ptr)
    {
        printf(" - 2 file can not open");
        return -1;
    }

    arr[size - 1] = '\0';

    for (i = 0; i < size - 1; i++)
    {
        ch = fgetc(ptr);
        // printf("%c", ch);
        // printf("//");
        // if(ch == '\0')printf("%d ", i);
        arr[i] = ch;
    }

    fclose(ptr);
}
*/

/*
 *
 *
 * Get all data by fgets() from .txt with string format
 *
 *
 */

void get_array(char **arr)
{

    FILE *ptr;
    char ch;
    int counter;

    ptr = fopen("pattern.txt", "r");

    if (NULL == ptr)
    {
        printf("-2 file can not open");
    }

    // Count size of data
    fseek(ptr, 0, SEEK_END);
    counter = ftell(ptr);

    ptr = fopen("pattern.txt", "r");

    *arr = (char *)realloc(*arr, counter + 1);

    while (fgets(*arr, counter + 1, ptr) != NULL)
    {
        //printf("%s ", *arr);
    }
    fclose(ptr);
}

/* Referenced from
 *
 * https://www.geeksforgeeks.org/check-string-substring-another/
 *
 *
 *
 */
void solve(char *arr, char pattern[])
{

    int i = 0;

    // General loop for traverse whole string
    for (; arr[i] != '\0'; i++)
    {
        // printf("%c ", arr[i]);
        int j;
        // Traversing and comparing one by one
        for (j = 0; pattern[j] != '\0'; j++)
        {
            if (arr[i + j] != pattern[j])
            {
                break;
            }
        }

        // Checking to found or not found
        if (pattern[j] == '\0')
        {
            int q;
            // Extracting elements and binding the new ones
            for (q = i; arr[q] != '\0'; q++)
            {
                arr[q] = arr[q + j];
            }
            // Put end of the string so we can shorten the array
            arr[q] = '\0';
            solve(arr, pattern);
        }
    }
}