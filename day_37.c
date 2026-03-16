//Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>

#define MAX 100

int pq[MAX];
int rear = -1;

void insert(int value)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    rear++;
    pq[rear] = value;
}

void delete()
{
    if(rear == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int min = pq[0];
    int pos = 0;

    for(int i = 1; i <= rear; i++)
    {
        if(pq[i] < min)
        {
            min = pq[i];
            pos = i;
        }
    }

    for(int i = pos; i < rear; i++)
    {
        pq[i] = pq[i + 1];
    }

    rear--;
}

void display()
{
    for(int i = 0; i <= rear; i++)
    {
        printf("%d ", pq[i]);
    }
}

int main()
{
    int n, x, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        delete();
    }

    display();

    return 0;
}