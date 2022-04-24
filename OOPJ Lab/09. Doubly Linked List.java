/*Write a Java program for the following: ** 1) Create a doubly linked list of
elements. 2) Delete a given element from the above list. 3) Display the contents
of the list after deletion.*/
import java.util.Scanner;

class List {
    class Node {
        int item;
        Node previous;
        Node next;

        Node(int item) {
            this.item = item;
        }
    }

    Node head, tail = null;

    public void addNode(int item) {
        Node newNode = new Node(item);
        if (head == null) {
            head = tail = newNode;
            head.previous = null;
            head.next = null;
        } else {
            newNode.next = null;
            newNode.previous = tail;
            tail.next = newNode;
            tail = newNode;
        }
    }

    public void delNode(int x) {
        int f = 0;
        Node temp = head, newNext;
        if (head.item == x) {
            head = temp.next;
            head.previous = null;
            return;
        }
        while (temp.next.item != x) {
            temp = temp.next;
        }
        if (temp.next.next == null)
            temp.next = null;
        else {
            newNext = temp.next.next;
            temp.next = newNext;
            newNext.previous = temp;
        }
    }

    public void displayNode() {
        Node temp = head;
        if (head == null) {
            System.out.println("List is Empty!");
        } else {
            while (temp != null) {
                System.out.print(temp.item + " ");
                temp = temp.next;
            }
        }
        System.out.println();
    }
}

class DoublyLinkedList {
    public static void main(String []args) {
        int n, it, ch, del;
        List l = new List();
        Scanner s = new Scanner(System.in);
        do {
            System.out.println("\nChoose Operation");
            System.out.println("1.Push");
            System.out.println("2.Pop");
            System.out.println("3.Display");
            System.out.println("4.Exit");
            ch = s.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("Enter the no. of elements : ");
                    n = s.nextInt();
                    System.out.println();
                    System.out.print("Enter the elements : ");
                    for (int i = 0; i < n; i++) {
                        it = s.nextInt();
                        l.addNode(it);
                    }
                    break;
                case 2:
                    System.out.print("Enter the item to be deleted : ");
                    del = s.nextInt();
                    l.delNode(del);
                    break;
                case 3:
                    System.out.print("DLL : ");
                    l.displayNode();
                    break;
                case 4:
                    break;
            }
        } while (ch < 4);
    }
}
