#include <stdio.h>

int main()
{
    int arr[] = {1,2,2,3,3,3};
    int n = 6;

    for(int i=0;i<n;i++)
    {
        int count = 1;
        int flag = 0;

        for(int k=0;k<i;k++)
        {
            if(arr[i]==arr[k])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            continue;

        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
                count++;
        }

        printf("%d occurs %d times\n",arr[i],count);
    }
}
