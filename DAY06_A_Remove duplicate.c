#include <stdio.h>

int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int j = 0;  // index for unique elements

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j] = arr[i];
            j++;
        }
    }

    arr[j] = arr[n - 1];
    return j + 1;   // new size of array
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
