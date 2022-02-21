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
        Node current = head, newNext;
        if (head.item == x) {
            head = current.next;
            head.previous = null;
            return;
        }
        while (current.next.item != x) {
            current = current.next;
        }
        if (current.next.next == null)
            current.next = null;
        else {
            newNext = current.next.next;
            current.next = newNext;
            newNext.previous = current;
        }
    }

    public void displayNode() {
        Node current = head;
        if (head == null) {
            System.out.println("List is Empty!");
        } else {
            while (current != null) {
                System.out.print(current.item + " ");
                current = current.next;
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