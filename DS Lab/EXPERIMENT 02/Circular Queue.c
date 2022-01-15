/*
Implement a circular queue using arrays with the operations:
1.Insert an element to the queue.
2.Delete an elements from the queue.
3.Display the contents of the queue after each operation.
*/

#include <stdio.h>
#define MAX 5

int cQ[MAX], front = -1, rear = -1;

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow\n");
    }
    while (i != rear)
    {
        printf("%d ", cQ[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", cQ[rear]);
}

void enqueue(int item)
{
    if ((rear + 1) % MAX == front)
    {
        printf("\nQueue overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        cQ[rear] = item;
        printf("Circular Queue : ");
        display();
    }
    else
    {
        rear = (rear + 1) % MAX;
        cQ[rear] = item;
        printf("Circular Queue : ");
        display();
    }
}

void pop()
{
    int del;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow\n");
    }
    else if (front == rear)
    {
        del = cQ[front];
        printf("The element removed is %d\n", del);
        front = rear = -1;
        printf("Circular Queue : ");
        display();
    }
    else
    {
        del = cQ[front];
        printf("The element removed is %d\n", del);
        front = (front + 1) % MAX;
        printf("Circular Queue : ");
        display();
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation\n");
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
            pop();
            break;
        case 3:
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (ch < 3);
}
