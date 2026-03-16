#include <stdio.h>

int main()
{
    int arr[]={6,3,-1,-3,4,-2,2,4,6,-12,-7};
    int n=11;
    int count=0;

    for(int i=0;i<n;i++)
    {
        int sum=0;

        for(int j=i;j<n;j++)
        {
            sum += arr[j];

            if(sum == 0)
                count++;
        }
    }

    printf("Total subarrays = %d",count);
}
