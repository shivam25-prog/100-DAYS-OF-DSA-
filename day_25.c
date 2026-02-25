#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int countOccurrences(struct Node *head, int key)
{
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
            count++;

        temp = temp->next;
    }

    return count;
}

int main()
{
    int n, i, value, key;
    struct Node *head = NULL, *newNode, *temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    scanf("%d", &key);

    printf("%d", countOccurrences(head, key));

    return 0;
}