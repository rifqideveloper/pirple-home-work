
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author zombi
 */
class file {
    static String this_file = "data.todo";
    static String[] load() {
        String[] data = new String[100];
        
        try {
            try (BufferedReader br = new BufferedReader(new FileReader(this_file))) {
                String line;
                int i = 0;
                while ((line = br.readLine()) != null) {
                    data[i] = line;
                    i++;
                }
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        }
        return data;
    }

    static void deleteline() {
        try {          
            RandomAccessFile raf = new RandomAccessFile(this_file, "rw");
            long writePosition = raf.getFilePointer();
                raf.readLine();                                                       
            // Shift the next lines upwards.                                      
            long readPosition = raf.getFilePointer();
                byte[] buff = new byte[1024];                                         
            int n;                                                                
            while (-1 != (n = raf.read(buff))) {                                  
                raf.seek(writePosition);                                          
                raf.write(buff, 0, n);                                            
                readPosition += n;                                                
                writePosition += n;                                               
                raf.seek(readPosition);                                           
            }                                                                     
            raf.setLength(writePosition);                                         
            raf.close();                                                          
        } catch (FileNotFoundException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        }
                                                       
    }

    static void arrange(int i) {
        String[] text = load();
        try {
            PrintWriter writer = new PrintWriter(new File(this_file));
            writer.flush();
            
            for(int x = 1;x < text.length;x++){
                if(text[x] != null)
                    writer.write(text[x]+'\n');
            }
            writer.write(text[0]+'\n');
            writer.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}
