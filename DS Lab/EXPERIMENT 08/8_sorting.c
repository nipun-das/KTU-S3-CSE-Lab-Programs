/*Experiment 8
Sorting Algorithms
18/02/2022
VML20CS066*/

#include <stdio.h>
#include <stdlib.h>

// Bubble sort
void bubbleSort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("\nThe Sorted Array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Insertion sort
void insertionSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
    printf("\nThe Sorted Array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Selection sort
void selectionSort(int A[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    printf("\nThe Sorted Array is: ");
    for (k = 0; k < n; k++)
    {
        printf("%d ", A[k]);
    }
    printf("\n");
}

// Quick sort
int partition(int A[], int lb, int ub)
{
    int pivot, start, end, temp;
    pivot = A[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (A[start] <= pivot)
        {
            start++;
        }
        while (A[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }
    A[lb] = A[end];
    A[end] = pivot;
    return end;
}
void quickSort(int A[], int lb, int ub)
{
    int i, loc;
    if (lb < ub)
    {
        loc = partition(A, lb, ub);
        quickSort(A, lb, loc - 1);
        quickSort(A, loc + 1, ub);
    }
}

// Merge sort
void merge(int A[], int lb, int mid, int ub)
{
    int i, j, k, B[100];
    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }

        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        A[k] = B[k];
    }
}
void mergeSort(int A[], int lb, int ub)
{
    int i, mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

// Heap sort
void heapify(int A[], int n, int i)
{
    int temp;
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[root])
        root = left;
    if (right < n && A[right] > A[root])
        root = right;
    if (root != i)
    {
        temp = A[i];
        A[i] = A[root];
        A[root] = temp;
        heapify(A, n, root);
    }
}
void heapSort(int A[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
    printf("\nThe Sorted Array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void main()
{
    int n, i, choice;
    do
    {
        printf("\nEnter the size of the array: ");
        scanf("%d", &n);
        int A[n], b[n];
        printf("Enter the elements of the array: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        printf("\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Quick Sort\n5.Merge Sort\n6.Heap Sort\n7.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubbleSort(A, n);
            break;
        case 2:
            insertionSort(A, n);
            break;
        case 3:
            selectionSort(A, n);
            break;
        case 4:
            quickSort(A, 0, n - 1);
            printf("\nThe Sorted Array is : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
            break;
        case 5:
            mergeSort(A, 0, n - 1);
            printf("\nThe Sorted Array is : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
            break;
        case 6:
            heapSort(A, n);
            break;
        case 7:
            break;
        default:
            printf("Invalid choice!");
        }

    } while (choice < 7);
}

/*OUTPUT

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4 

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 1

The Sorted Array is : 3 4 5 6 9 

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 2

The Sorted Array is: 3 4 5 6 9 

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 3

The Sorted Array is: 3 4 5 6 9

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 4

The Sorted Array is : 3 4 5 6 9

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 5

The Sorted Array is : 3 4 5 6 9

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 6

The Sorted Array is : 3 4 5 6 9

Enter the size of the array: 5
Enter the elements of the array: 5 3 6 9 4

1.Bubble Sort
2.Insertion Sort
3.Selection Sort
4.Quick Sort
5.Merge Sort
6.Heap Sort
7.Exit

Enter your choice: 7

*/