/*Implement a Queue using arrays with the operations:
1.Insert elements to the Queue.
2.Delete elements from the Queue.
3.Display the contents of the Queue after each operation.*/

#include <stdio.h>

int queue[100], n, front = -1, rear = -1;

void display()
{
    printf("\nQueue : ");
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
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
    if (rear == n - 1)
    {
        printf("\nQueue overflow");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear++;
        queue[rear] = item;
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
        printf("\nThe element removed is %d\n", del);
        front = rear = -1;
    }
    else
    {
        del = queue[front++];
        printf("\nThe element removed is %d\n", del);
    }
}
int main()
{
    int ch, element;
    printf("\nEnter the size of queue : ");
    scanf("%d", &n);
    int queue[n];
    do
    {
        printf("\n\nChoose operation");
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


