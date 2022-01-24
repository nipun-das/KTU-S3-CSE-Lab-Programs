/*Implement a Priority Queue using arrays with the operations:
1.Insert elements to the Priority Queue.
2.Delete elements from the Priority Queue.
3.Display the contents of the Priority Queue after each operation.*/

#include <stdio.h>

int pQ[100], n, rear = -1, front = -1;

void display()
{
    printf("\nPriority Queue : ");
    if (front == -1 && rear == -1)
    {
        printf("\nPriority queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", pQ[i]);
        }
    }
}
void enqueue(int item)
{
    int pos;
    if (rear == n - 1)
    {
        printf("\nQueue overflow\n");
    }
    else
    {
        pos = rear;
        rear = rear + 1;
        while (pos >= 0 && pQ[pos] > item)
        {
            pQ[pos + 1] = pQ[pos];
            pos = pos - 1;
        }
    }
    pQ[pos + 1] = item;
    if (front == -1)
    {
        front = front + 1;
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
        del = pQ[front];
        printf("\nThe element removed is %d\n", del);
        front = rear = -1;
    }
    else
    {
        del = pQ[front++];
        printf("\nThe element removed is %d\n", del);
    }
}
int main()
{
    int ch, element;
    printf("\nEnter the size of the priority queue : ");
    scanf("%d", &n);
    int pQ[n];
    do
    {
        printf("\n\nChoose operation : ");
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
