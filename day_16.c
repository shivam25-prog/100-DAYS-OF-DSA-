// Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++)
    {
        int count = 1;
        int alreadyCounted = 0;

        // check if this element was counted before
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                alreadyCounted = 1;
                break;
            }
        }

        if(alreadyCounted)
            continue;

        // count frequency
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }

        printf("%d %d\n", arr[i], count);
    }

    return 0;
}
