import java.io.*;
import java.util.Scanner;

public class FileHandlingPalindromeReadAndWrite {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        FileWriter fw = null;
        FileReader fr = null;
        String s1, s2 = "";
        System.out.println("Enter the string : ");
        s1 = sc.nextLine();
        try {
            fw = new FileWriter("first.txt");
            for (int i = 0; i < s1.length(); i++) {
                fw.write(s1.charAt(i));
            }
            fw.close();
            System.out.println("Write successful!");
            fr = new FileReader("first.txt");
            Scanner sr = new Scanner(fr);
            while (sr.hasNextLine()) {
                String c = sr.nextLine();
                System.out.println("Contents of first.txt is " + c);
            }
            fr.close();
        } catch (FileNotFoundException e) {
            System.out.println("File is not found!");
        }
        for (int i = s1.length() - 1; i >= 0; i--) {
            s2 = s2 + s1.charAt(i);
        }
        try {
            fw = new FileWriter("second.txt");
            if (s1.equals(s2)) {
                fw.write(s1 + " is palindrome");
            } else {
                fw.write(s1 + " is not a palindrome");
            }
            fw.close();
            fr = new FileReader("second.txt");
            Scanner sr = new Scanner(fr);
            while (sr.hasNextLine()) {
                String d = sr.nextLine();
                System.out.println("Contents of second.txt is : " + d);
            }
            fr.close();
        } catch (FileNotFoundException e) {
            System.out.println("File is not found!");
        }
    }
}
