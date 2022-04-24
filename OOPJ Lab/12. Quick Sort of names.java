import java.util.Scanner;

public class QuickSort {

    int partition(String A[], int lb, int ub) { //rt int
        String pivot, temp;
        int start, end;

        pivot = A[lb];
        start = lb;
        end = ub;
        while (start < end) {
            while (A[start].compareTo(pivot) <= 0 && start < ub) {
                start++;
            }
            while (A[end].compareTo(pivot) > 0) {
                end--;
            }
            if (start < end) {
                temp = A[start];
                A[start] = A[end];
                A[end] = temp;
            }
        }
        A[lb] = A[end];
        A[end] = pivot;
        return end;
    }

    void quickSort(String A[], int lb, int ub) {
        int loc;
        if (lb < ub) {
            loc = partition(A, lb, ub);
            quickSort(A, lb, loc - 1);
            quickSort(A, loc + 1, ub);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i;
        System.out.print("Enter the number of the names: ");
        int n = sc.nextInt();
        String A[] = new String[n];
        System.out.print("Enter the " + n + " names: ");
        for (i = 0; i < n; i++) {
            A[i] = sc.next();
        }
        QuickSort obj = new QuickSort();
        obj.quickSort(A, 0, n - 1);
        System.out.print("The Sorted Names are :  ");
        for (i = 0; i < n; i++) {
            System.out.print(A[i] + "  ");
        }
    }
}
