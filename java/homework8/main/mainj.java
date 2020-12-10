package main;

public class mainj {

    public static void main(String[] args) {
        timeAdder test1 = new timeAdder(60, "minute", 30, "minutes");
        test1.print();
        timeAdder test2 = new timeAdder(60, "hours", 30, "minutes");
        test2.print();
        timeAdder test3 = new timeAdder(60, "seconds", 30, "minutes");
        test3.print();
        timeAdder test4 = new timeAdder(60, "day", 90, "hours");
        test4.print();
    }

}

