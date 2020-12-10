package main;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class mainj {

    public static void main(String[] args) {
        readers data = new readers();
        try {
            BufferedWriter outfile = new BufferedWriter(new FileWriter("infile/fifa-tab.tsv"));
            outfile.write(data.file("infile/data.csv").replace(',', '\t'));
            outfile.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}

