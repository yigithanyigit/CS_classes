#include <stdio.h>

int solve(int arr[], int size)
{
    int tmp, lmax, qmax, i, j, m = (size / 2) - 1;
    for (i = m, tmp = 0, lmax = arr[m]; i >= 0; i--)
    {
        tmp += arr[i];
        if (tmp > lmax)
        {
            lmax = tmp;
        }
        else
        {
            lmax = lmax;
        }
    }
    for (j = m + 1, tmp = 0, qmax = arr[m + 1]; j < size; j++)
    {

        tmp += arr[j];
        if (tmp > qmax)
        {
            qmax = tmp;
        }
        else
        {
            qmax = qmax;
        }
    }
    return lmax + qmax;
}

int maxSubArray(int *nums, int numsSize)
{
    int l, r, c, max, m = numsSize / 2;

    if (numsSize == 1)
        return *nums;

    l = maxSubArray(nums, m);
    r = maxSubArray(nums + m, numsSize - m);
    c = solve(nums, numsSize);

    if (l > r)
        max = l;
    else
        max = r;

    if (max > c)
        max = max;
    else
        max = c;

    return max;
}

int main()
{
    int *nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = 9;
    printf("%d\n", maxSubArray(nums, numsSize));
    // printf("%d\n",nums[0]);
}