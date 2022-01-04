#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;


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
            printf("%d ", queue[i]);
        }
    }
    
}

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("\nQueue overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
        printf("Queue : ");
        display();
    }
    else
    {
        rear++;
        queue[rear] = item;
        printf("Queue : ");
        display();
    }
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
        del = queue[front];
        printf("The element removed is %d\n", del);
        front = rear = -1;
        printf("Queue : ");
        display();
    }
    else
    {
        del = queue[front++];
        printf("The element removed is %d\n", del);
        printf("Queue : ");
        display();
    }
}



int main()
{
    int ch, element;
    do
    {
        printf("\nChoose operation");
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