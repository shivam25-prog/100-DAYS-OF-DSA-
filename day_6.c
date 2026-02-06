// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int main()
{
    int n;              // user se n lena
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(n == 0)
        return 0;

    int j = 0;   // last unique element ka index

    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    // unique elements print karo
    for(int i = 0; i <= j; i++)
        printf("%d ", arr[i]);

    return 0;
}
