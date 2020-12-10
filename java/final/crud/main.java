package crud;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class main {

    public static void main(String[] args) {

        crud("data.xml", "title");
    }

    private static void crud(String file, String title) {
        try {
            boolean file_exists = Files.exists(Path.of(file));
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = docfile(dBuilder, file_exists, file);
            //
            if (!file_exists) {
                Element rootElement = doc.createElement(title);
                new Thread(() -> doc.appendChild(rootElement)).start();
            }
            //
            String help =
                    "-------------------------------------------------------------------------------\n" +
                            "how to use this program:\n\t" +
                            "a. help    = print help manual for example { <<help }\n\t" +
                            "b. create  = creating new element for example { <<create test testing }\n\t" +
                            "c. read    = reading element for example { <<read element_name }\n\t" +
                            "d. update  = updating old element for example { <<update element new_value }\n\t" +
                            "e. delete  = deleting element for example { <<delete element_name }\n" +
                            "-------------------------------------------------------------------------------\n";
            final String choice1 = "exit",
                    choice2 = "create",
                    choice3 = "update",
                    choice4 = "delete",
                    choice5 = "help",
                    choice6 = "read";

            final String[] print = {"<<", "exit program", "done"};
            System.out.print(help);
            String[] input;
            label:
            while (true) {
                System.out.print(print[0]);
                input = new Scanner(System.in).nextLine().toLowerCase().split(" ");
                switch (input[0]) {
                    case choice1:
                        System.out.println(print[1]);
                        break label;
                    case choice2:
                        //creating new element
                        try {
                            addElement(doc, input[1], input[2], title);
                            System.out.println(print[2]);
                        } catch (Exception e) {
                            System.out.println("error");
                        }

                        break;
                    case choice3:
                        //update ElementValue
                        try {
                            updateElementValue(doc, input[1], input[2]);
                            System.out.println(print[2]);
                        } catch (Exception e) {
                            System.out.println("error");
                        }

                        break;
                    case choice4:
                        //deleting element
                        try {
                            deleteElement(doc, title, input[1]);
                            System.out.println(print[2]);
                        } catch (Exception e) {
                            System.out.println("error");
                        }

                        break;
                    case choice5:
                        //print help
                        System.out.println(help);
                        break;
                    case choice6:
                        //reading
                        try {
                            read(input[1], doc);
                        } catch (Exception e) {
                            System.out.println("error");
                        }
                        break;
                    default:
                        try {
                            System.out.print("invalid input { <<");
                            for (String s : input) {
                                System.out.print(s + " ");
                            }
                            System.out.print("}\n" + help);
                        } catch (Exception e) {
                            System.out.println("error");
                        }

                }
            }
            //
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer;
            transformer = transformerFactory.newTransformer();
            transformer.setOutputProperty(OutputKeys.INDENT, "yes");
            DOMSource source = new DOMSource(doc);
            StreamResult result = new StreamResult(new File(file));
            transformer.transform(source, result);
        } catch (ParserConfigurationException | TransformerConfigurationException e) {
            e.printStackTrace();
        } catch (TransformerException e) {
            e.printStackTrace();
        } catch (SAXException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void read(String s, Document doc) {
        try {
            System.out.println(doc.getElementsByTagName(s).item(0).getTextContent().trim());
        } catch (Exception e) {
            System.out.println("error");
        }
    }

    static Document docfile(DocumentBuilder a, boolean file, String files) throws IOException, SAXException {
        if (!file) {
            return a.newDocument();
        }
        File data = new File(files);
        return a.parse(data);
    }

    private static void deleteElement(Document doc, String title, String del) {
        NodeList users = doc.getElementsByTagName(title);
        Element user;
        // loop for each user
        for (int i = 0; i < users.getLength(); i++) {
            user = (Element) users.item(i);
            Node genderNode = user.getElementsByTagName(del).item(0);
            user.removeChild(genderNode);
        }

    }

    private static void addElement(Document doc, String tag, String data, String title) {
        if (doc.getElementsByTagName(data) != null) {
            System.out.println("element already exists");
        } else {
            NodeList users = doc.getElementsByTagName(title);
            Element emp;
            // loop for each user
            for (int i = 0; i < users.getLength(); i++) {
                emp = (Element) users.item(i);
                Element salaryElement = doc.createElement(tag);
                salaryElement.appendChild(doc.createTextNode(data));
                emp.appendChild(salaryElement);
            }
        }


    }

    private static void updateElementValue(Document doc, String element, String new_) {
        doc.getElementsByTagName(element).item(0).setTextContent(new_);
    }
}



