#include <stdio.h>
#define MAX 5

int cQueue[MAX], front = -1, rear = -1;

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow\n");
    }
    while (i != rear)
    {
        printf("%d ", cQueue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", cQueue[rear]);
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
        cQueue[rear] = item;
        printf("Circular Queue : ");
        display();
    }
    else
    {
        rear = (rear + 1) % MAX;
        cQueue[rear] = item;
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
        del = cQueue[front];
        printf("The element removed is %d\n", del);
        front = rear = -1;
        printf("Circular Queue : ");
        display();
    }
    else
    {
        del = cQueue[front];
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
        printf("\nChoose operation\n");
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