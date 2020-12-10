package Homework4;

import java.util.ArrayList;

public class homework4 {
    public static void main(String[] args) {
        ArrayList<String> genre = new ArrayList<>();
        genre.add("Heal The World");
        genre.add("Michael Jackson");
        genre.add("1992");
        genre.add("pop");
        genre.add("390");
        for (char i = 0; i < 5; i++) {
            System.out.println(genre.get(i));
        }

    }
}
