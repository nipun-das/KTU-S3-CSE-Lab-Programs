#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = 0;

void display()
{
    printf("\nStack : ");
    struct node *temp;
    temp = top;
    if (top == 0)
        printf("Stack is empty.");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct
                                           node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Popped element is %d", top->data);
        top = top->next;
        free(temp);
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