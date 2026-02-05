#include <stdio.h>

int main()
{
    int n1, n2;

    printf("Enter size of first log: ");
    scanf("%d", &n1);

    printf("Enter size of second log: ");
    scanf("%d", &n2);

    int log1[n1], log2[n2], merged[n1 + n2];

    printf("Enter elements of first log (sorted):\n");
    for(int i = 0; i < n1; i++)
        scanf("%d", &log1[i]);

    printf("Enter elements of second log (sorted):\n");
    for(int i = 0; i < n2; i++)
        scanf("%d", &log2[i]);

    int i = 0, j = 0, k = 0;

    // Merge both logs
    while(i < n1 && j < n2)
    {
        if(log1[i] <= log2[j])
            merged[k++] = log1[i++];
        else
            merged[k++] = log2[j++];
    }

    // Copy remaining elements
    while(i < n1)
        merged[k++] = log1[i++];

    while(j < n2)
        merged[k++] = log2[j++];

    printf("Merged chronological log:\n");
    for(int x = 0; x < n1 + n2; x++)
        printf("%d ", merged[x]);

    return 0;
}
