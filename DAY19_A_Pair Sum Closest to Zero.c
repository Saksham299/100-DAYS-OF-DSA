#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int arr[] = {-8,-3,1,4,7};
    int n = 5;

    qsort(arr,n,sizeof(int),cmp);

    int l = 0, r = n-1;
    int min_sum = 100000;
    int x,y;

    while(l<r)
    {
        int sum = arr[l] + arr[r];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            x = arr[l];
            y = arr[r];
        }

        if(sum < 0)
            l++;
        else
            r--;
    }

    printf("Pair: %d %d",x,y);
}
