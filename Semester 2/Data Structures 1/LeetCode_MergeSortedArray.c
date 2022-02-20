#include <stdio.h>
/*
*
* 8 ms Submission
*
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int *temp_arr = (int*) malloc((m + n) * sizeof(int));
    while (i < m && j < n)
    {
        if (nums1[i] >= nums2[j])
        {
            temp_arr[k] = nums2[j];
            j++;
        }
        else
        {
            temp_arr[k] = nums1[i];
            i++;
        }
        k++;
    }

    while (i < m)
    {
        temp_arr[k] = nums1[i];
        i++;
        k++;
    }

    while (j < n)
    {
        temp_arr[k] = nums2[j];
        j++;
        k++;

    }

    for (int i = 0; i < nums1Size; i++)
    {
        nums1[i] = temp_arr[i];
    }

    return nums1;
}
*/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = m - 1;
    int l = n - 1;
    int size = nums1Size - 1;

    if (m == 0 && l >= 0)
    {
        nums1[l] = nums2[l];
        l--;
    }

    while (size >= 0 && l >= 0 && i >= 0)
    {
        
        nums1[size] = nums1[i] >= nums2[l] && i >= 0 ? nums1[i--] : nums2[l--];
        printf("%d ", size);
        size--;
    }
}

int main()
{
    int nums1[] = {2,0};
    int m = 1;
    int nums1Size = 2;
    int nums2[] = {1};
    int n = 1;
    int nums2Size = 1;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for (int i = 0; i < nums1Size; i++)
    {
        printf("index: %d -> ", i);
        printf("%d ", nums1[i]);
    }
}
