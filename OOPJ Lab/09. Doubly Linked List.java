/*Write a Java program for the following: ** 1) Create a doubly linked list of
elements. 2) Delete a given element from the above list. 3) Display the contents
of the list after deletion.*/

import java.util.Scanner;


class List {
    class Node {
        int item;
        Node prev;
        Node next;

        Node(int item) {
            this.item = item;
        }
    }

    Node head, tail = null;

    public void addNode(int x) {
        Node newNode = new Node(x);
        if (head == null) {
            head = tail = newNode;
            newNode.next = null;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
            newNode.next = null;
        }
    }

    public void delNode(int x) {
        Node temp = head;
        if (head.item == x) {
            head = temp.next;
            head.prev = null;
            return;
        }
        while (temp.next.item != x) {
            temp = temp.next;
        }
        if (temp.next.next == null) {
            temp.next = null;
        } else {
            temp.next = temp.next.next;
            temp.next.next.prev = temp;
        }
    }

    public void displayNode() {
        Node temp = head;
        if (head == null) {
            System.out.println("empty!!");
        } else {
            while (temp != null) {
                System.out.print(temp.item+" ");
                temp = temp.next;
            }
        }
    }
}

class DoublyLinkedList {
    public static void main(String[] args) {
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
                    System.out.print("Enter the element to insert : ");
                    it = s.nextInt();
                    l.addNode(it);

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
