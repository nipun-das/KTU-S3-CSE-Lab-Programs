import java.util.Scanner;

public class ExceptionHandlingDivideArrays {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of first array : ");
        int m = sc.nextInt();
        System.out.println("Enter the size of second array : ");
        int n = sc.nextInt();
        int a[] = new int[m];
        int b[] = new int[n];
        System.out.print("Enter the first array : ");
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
        }
        System.out.print("Enter the second array : ");
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        System.out.println("Division : ");
        for (int i = 0; i < m; i++) {
            try {
                int result = a[i] / b[i];
                System.out.println(result);
            } catch (ArithmeticException e) {
                System.out.println("Division by zero ");
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Index Out of Bounds");
            }
        }
    }
}