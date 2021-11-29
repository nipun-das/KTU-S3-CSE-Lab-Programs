package com.company;

import java.util.Scanner;

public class StringCharFreq {
    public static void main(String[] args) {
        int opt;
        do {
            Scanner s = new Scanner(System.in);
            int i, l, count = 0, f = 0;
            String str;
            char ch;
            System.out.println("Enter the string : ");
            str = s.nextLine();
            System.out.println("Enter the character to check : ");
            ch = s.next().charAt(0);
            l = str.length();
            for (i = 0; i < l; i++) {
                if (ch == str.charAt(i)) {
                    f = 1;
                    count++;
                }
            }
            if (f == 1) {
                System.out.println("the frequency of the character " + ch + " is " + count);
            } else {
                System.out.println("Not found");
            }
            System.out.println("Continue?(1/0)");
            opt = s.nextInt();
        } while (opt == 1);
    }
}
