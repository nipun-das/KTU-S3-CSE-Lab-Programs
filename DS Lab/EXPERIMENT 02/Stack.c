/*
Implement a Stack using arrays with the operations:
1.Pushing elements to the Stack.
2.Popping elements from the Stack
3.Display the contents of the Stack after each operation.
*/

#include <stdio.h>

int stack[100], n, top = -1;

void display()
{

    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack : ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}
void push(int item)
{
    if (top == n - 1)
    {
        printf("\nStack overflow");
    }
    else
    {
        stack[++top] = item;
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
    }
}
int main()
{
    int ch, element;
    printf("\nEnter the size of stack ");
    scanf("%d", &n);
    int stack[n];
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit\n");
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
