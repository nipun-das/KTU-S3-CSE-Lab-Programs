//Write a Java program that shows thread synchronization.

class Five extends Thread {
    int x;

    Five(int x) {
        this.x = x;
    }

    public void run() {
        Table t = new Table(x);
        t.tableCalc();
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            System.out.println("Interruption occurred");
        }
    }
}

class Hundred extends Thread {
    int x;

    Hundred(int x) {
        this.x = x;
    }

    public void run() {
        Table t = new Table(x);
        t.tableCalc();
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            System.out.println("Interruption occurred");
        }
    }
}

class Table {
    int x;

    Table(int x) {
        this.x = x;
    }

    synchronized void tableCalc() {
        System.out.println("MULTIPLICATION TABLE OF " + x);
        for (int i = 1; i <= 10; i++) {
            System.out.println(x + " x " + i + " = " + (x * i));
        }
        System.out.println();
    }
}

public class MultiplicationTable {
    public static void main(String[] args) {
        Five f = new Five(5);
        f.start();
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            System.out.println("Interruption occurred");
        }

        Hundred h = new Hundred(100);
        h.start();
        try {
            Thread.sleep(600);
        } catch (InterruptedException e) {
            System.out.println("Interruption occurred");
        }
    }
}
