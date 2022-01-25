/*Write a program to write a string to a file, read the string from the file and check whether it is a palindrome or not. Write the output to another file*/

import java.util.Scanner;
import java.io.*;

class PalindromeFile{
	public static void main(String []args) throws IOException{
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the String : ");
		String s1 = sc.nextLine();
		FileWriter fw = null;
		FileReader fr = null;
		int i;
		try{
			fw = new FileWriter("first.txt");
			fr = new FileReader("first.txt");
			fw.write(s1); 
			System.out.println("\nfirst.txt file is created!");
			fw.close();
			
			System.out.print("Data in first.txt : ");
			while((i = fr.read())!=-1){
				System.out.print((char)i);
			}
			System.out.println();
			fr.close();
		}
		catch(FileNotFoundException e){
			System.out.println("File creation failed!");
		}

		String s2 ="" ;
		for(i = s1.length()-1 ;i >= 0 ;i--){
			s2 = s2 + s1.charAt(i);
		}

		try{
			fw = new FileWriter("second.txt");
			fr = new FileReader("second.txt");			
			if(s1.equals(s2)){
				fw.write(s1 + " is Palindrome");
			}
			else{
				fw.write(s1 + " is not a Palindrome");
			}
			System.out.println("\nsecond.txt file is created!");
			fw.close();
			System.out.print("Data in second.txt : ");
			while((i = fr.read())!=-1){
				System.out.print((char)i);
			}
			System.out.println();
			fr.close();	
		}
		catch(FileNotFoundException e){
			System.out.println("File creation failed!");
		}
	}
}
