package main;

public class mainj {
    public static void main(String[] args) {
        Cars ferrari = new Cars("ferrari", "488", 2010, 1380, 20);
        Cars tesla = new Cars("tesla", "X", 2019, 1000, 0);
        Cars BMW = new Cars("BMW", "X5", 2008, 1000, 98);
        tesla.Drive();
        tesla.Drive();
        tesla.Drive();
        tesla.Drive();
        tesla.Drive();
        tesla.print();
        ferrari.print();
        ferrari.Drive();
        ferrari.Drive();
        ferrari.Drive();
        BMW.Drive();
        BMW.Drive();
        BMW.Drive();
        BMW.print();
        BMW.Repair();
    }

}

