/*Implement a Double-Ended Queue (DEQUEUE) with the operations:
8.1.Insert elements to the Front of the queue.
8.2.Insert elements to the Rear of the queue
8.3.Delete elements from the Front of the queue.
8.4.Delete elements from the Rear of the queue.
8.5.Display the queue after each operation.*/

#include <stdio.h>

int DQ[100], n, front = -1, rear = -1;

void display()
{
    printf("\nDEQUEUE : ");
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow\n");
    }
    while (i != rear)
    {
        printf("%d ", DQ[i]);
        i = (i + 1) % n;
    }
    printf("%d ", DQ[rear]);
}

void enqueueFront(int item)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("\nQueue overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        DQ[front] = item;
    }
    else if (front == 0)
    {
        front = n - 1;
        DQ[front] = item;
    }
    else
    {
        front--;
        DQ[front] = item;
    }
}

void enqueueRear(int item)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("\nQueue overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        DQ[rear] = item;
    }
    else if (rear == n - 1)
    {
        rear = 0;
        DQ[rear] = item;
    }
    else
    {
        rear++;
        DQ[rear] = item;
    }
}

void dequeueFront()
{
    int del;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow");
    }
    else if (front == rear)
    {
        del = DQ[front];
        printf("\nThe element removed is %d\n", del);
        front = rear = -1;
    }
    else if (front == n - 1)
    {
        del = DQ[front];
        printf("\nThe element removed is %d\n", del);
        front = 0;
    }
    else
    {
        del = DQ[front];
        printf("The element removed is %d\n", del);
        front++;
    }
}

void dequeueRear()
{
    int del;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow");
    }
    else if (front == rear)
    {
        del = DQ[front];
        printf("\nThe element removed is %d\n", del);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        del = DQ[rear];
        printf("\nThe element removed is %d\n", del);
        rear = n - 1;
    }
    else
    {
        del = DQ[rear];
        printf("\nThe element removed is %d\n", del);
        rear--;
    }
}
int main()
{
    int ch, element;
    printf("\nEnter the size of the DEQUEUE : ");
    scanf("%d", &n);
    int DQ[n];
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue Front");
        printf("\n2.Enqueue Rear");
        printf("\n3.Dequeue Front");
        printf("\n4.Dequeue Rear");
        printf("\n5.Display");
        printf("\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert at front : ");
            scanf("%d", &element);
            enqueueFront(element);
            break;
        case 2:
            printf("\nEnter element to insert at rear : ");
            scanf("%d", &element);
            enqueueRear(element);
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (ch < 6);
}
