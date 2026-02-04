//  Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

int main()
{
    int n, i;
    int a[100];
    int start, end, temp;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = 0;
    end = n - 1;

    while(start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array is:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
