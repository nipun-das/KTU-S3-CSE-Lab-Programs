/*
Implement a Stack using arrays with the operations:
1.Pushing elements to the Stack.
2.Popping elements from the Stack
3.Display the contents of the Stack after each operation.
*/
#include <stdio.h>
#define MAX 8

int stack[MAX], top = -1;

void display()
{
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow");
    }
    else
    {
        stack[++top] = item;
        printf("Stack : ");
        display();
    }
}

void pop()
{
    int del;
    if (top == -1)
    {
        printf("\nStack underflow");
    }
    else
    {
        del = stack[top--];
        printf("\nDeleted: %d\n", del);
        printf("Stack : ");
        display();
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &element);
            push(element);
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
