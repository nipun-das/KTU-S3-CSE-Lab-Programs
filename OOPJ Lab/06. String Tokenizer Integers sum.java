import java.util.Scanner;
import java.util.StringTokenizer;

public class StringTokenizerIntegers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, sum = 0;
        System.out.print("Enter integers : ");
        String num = sc.nextLine();
        StringTokenizer st = new StringTokenizer(num, " ");
        System.out.print("Entered integers are : ");
        while (st.hasMoreTokens()) {
            a = Integer.parseInt(st.nextToken());
            System.out.print(a + " ");
            sum = sum + a;
        }
        System.out.println("\nSum of integers = " + sum);
    }
}