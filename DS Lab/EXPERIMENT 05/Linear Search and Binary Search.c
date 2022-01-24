/*Write a program to find a particular number using
1. Linear search
2. Binary search*/

#include <stdio.h>

void linearSearch()
{
    int key, i, n, count = 0;

    printf("\nEnter the no. of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the number to search for: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("\nYour number %d is found at location %d", key, i + 1);
            count++;
            break;
        }
    }
    if (count == 0)
    {
        printf("\nYour Number %d is not found!", key);
    }
}

void binarySearch()
{
    int i, key, n, l, u, mid, a[100], count = 0;

    printf("\nEnter the number of elements : ");
    scanf("%d", &n);
    printf("\nEnter the elements in ascending order : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter element to be searched: ");
    scanf("%d", &key);

    l = 0;
    u = n - 1;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (key == a[mid])
        {
            printf("\n\nYour number %d is found at location %d", key, mid + 1);
            count = 1;
            break;
        }
        else if (key < a[mid])
        {
            u = mid - 1;
        }
        else if (key > a[mid])
        {
            l = mid + 1;
        }
    }
    if (count == 0)
    {
        printf("\nYour Number %d is not found!", key);
    }
}

void main()
{
    int ch;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Linear Search");
        printf("\n2.Binary Search");
        printf("\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            linearSearch();
            break;
        case 2:
            binarySearch();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch < 3);
}
