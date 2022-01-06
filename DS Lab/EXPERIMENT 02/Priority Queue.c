/*
Implement a Priority Queue using arrays with the operations:
1.Insert elements to the Priority Queue.
2.Delete elements from the Priority Queue.
3.Display the contents of the Priority Queue after each operation.
*/

#include <stdio.h>
#define MAX 5
int pQueue[MAX], rear = -1, front = -1;

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", pQueue[i]);
        }
    }
}

void enqueue(int item)
{
    int pos;
    if (rear == MAX - 1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        pos = rear;
        rear = rear + 1;
        while (pos >= 0 && pQueue[pos] > item)
        {
            pQueue[pos + 1] = pQueue[pos];
            pos = pos - 1;
        }
    }
    pQueue[pos + 1] = item;
    if (front == -1)
    {
        front = front + 1;
    }
    printf("Priority Queue : ");
    display();
}
void dequeue()
{
    int del;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow");
    }
    else if (front == rear)
    {
        del = pQueue[front];
        printf("The element removed is %d\n", del);
        front = rear = -1;
        printf("Priority Queue : ");
        display();
    }
    else
    {
        del = pQueue[front++];
        printf("The element removed is %d\n", del);
        printf("Priority Queue : ");
        display();
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (ch < 3);
}
