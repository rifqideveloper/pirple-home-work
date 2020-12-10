package main;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;


public class readers {
    static void loading(long i, long x) {
        System.out.println(i + "/" + x);
    }

    public static void cvstoxml(String s, String fifa) {
        String[] Format = {" ", "", ",", "no", "yes"};
        String xmlfile = "infile/" + fifa + ".xml";
        try {

            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.newDocument();
            //

            //
            Element rootElement = doc.createElement(fifa);
            new Thread(() -> doc.appendChild(rootElement)).start();
            //
            BufferedReader csv = new BufferedReader(new FileReader(s));
            String[] data0 = csv.readLine().replace(Format[0], Format[1]).split(Format[2]);
            //
            long line = countln(s), i = 0;
            while (i < line) {
                String[] data1 = csv.readLine().replace(Format[0], Format[1]).split(Format[2]);
                Element num = doc.createElement(Format[3].concat(String.valueOf(i)));
                new Thread(() -> rootElement.appendChild(num)).start();
                Thread t0 = new Thread(() -> {
                    for (int x = 1; x < 89; x++) {
                        Element pdata = doc.createElement(data0[x]);
                        try {
                            pdata.setTextContent(data1[x]);
                        } catch (ArrayIndexOutOfBoundsException e) {
                            //
                        } finally {
                            num.appendChild(pdata);
                        }


                    }
                });
                // Write xml to file
                Thread t1 = new Thread(() -> {
                    TransformerFactory transformerFactory = TransformerFactory.newInstance();
                    Transformer transformer;
                    try {

                        transformer = transformerFactory.newTransformer();
                        transformer.setOutputProperty(OutputKeys.INDENT, Format[4]);
                        DOMSource source = new DOMSource(doc);
                        StreamResult result = new StreamResult(new File(xmlfile));
                        transformer.transform(source, result);
                    } catch (TransformerException e) {
                        e.printStackTrace();
                    }

                });
                t0.start();
                t1.start();
                t0.join();
                t1.join();
                long finalI = i;
                new Thread(() -> loading(line, finalI)).start();
                i++;
            }


        } catch (ParserConfigurationException | IOException | InterruptedException e) {
            e.printStackTrace();
        }

    }


    private static long countln(String s) {
        Path path = Paths.get(s);
        long lines = 0;
        try {
            lines = Files.lines(path).count();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return lines;
    }

    public String file(String s) {
        try {
            return Files.readString(Paths.get(s), StandardCharsets.UTF_8);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;

    }


}
