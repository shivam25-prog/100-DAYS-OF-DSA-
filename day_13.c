// You are given a rectangular matrix of integers. Starting from the outer boundary,
// traverse the matrix in a clockwise manner and continue moving inward layer by layer
// until all elements are visited.
#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("Spiral order:\n");

    while(top <= bottom && left <= right)
    {
        // left to right
        for(int i = left; i <= right; i++)
            printf("%d ", a[top][i]);
        top++;

        // top to bottom
        for(int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // right to left
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
                printf("%d ", a[bottom][i]);
            bottom--;
        }

        // bottom to top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}

