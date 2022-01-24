/*
Implement a circular queue using arrays with the operations:
1.Insert an element to the queue.
2.Delete an elements from the queue.
3.Display the contents of the queue after each operation.
*/

#include <stdio.h>

int cQ[100], front = -1, n, rear = -1;

void display()
{
    printf("\nCircular Queue : ");
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    while (i != rear)
    {
        printf("%d ", cQ[i]);
        i = (i + 1) % n;
    }
    printf("%d ", cQ[rear]);
}
void enqueue(int item)
{
    if ((rear + 1) % n == front)
    {
        printf("\nQueue overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        cQ[rear] = item;
    }
    else
    {
        rear = (rear + 1) % n;
        cQ[rear] = item;
    }
}
void dequeue()
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
    }
    else
    {
        del = cQ[front];
        printf("The element removed is %d\n", del);
        front = (front + 1) % n;
    }
}
int main()
{
    int ch, element;
    printf("\nEnter the size of the circular queue : ");
    scanf("%d", &n);
    int cQ[n];
    do
    {
        printf("\n\nChoose operation\n");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit\n");
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
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (ch < 4);
}
