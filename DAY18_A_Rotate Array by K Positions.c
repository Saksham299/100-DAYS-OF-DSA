#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int k = 2;

    for(int r=0;r<k;r++)
    {
        int temp = arr[0];

        for(int i=0;i<n-1;i++)
            arr[i] = arr[i+1];

        arr[n-1] = temp;
    }

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
