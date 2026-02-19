#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int l = 0, r = n - 1;
    int min_sum = 2147483647;
    int x = 0, y = 0;

    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            x = arr[l];
            y = arr[r];
        }

        if (sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", x, y);
    return 0;
}