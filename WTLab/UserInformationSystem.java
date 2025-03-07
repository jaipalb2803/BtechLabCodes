import java.io.*;
import java.util.*;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;
import org.w3c.dom.*;

public class UserInformationSystem {

    private static final String FILENAME = "usersInfo.xml";
    private static Map<Integer, User> users = new HashMap<>();

    public static void main(String[] args) throws Exception {
        File xmlFile = new File(FILENAME);
        if (!xmlFile.exists()) {
            getUserInputAndWriteToXML();
        } else {
            readFromXML(xmlFile);
        }

        // Reading user details based on ID
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an ID to get user details:");
        int id = scanner.nextInt();
        User user = users.get(id);
        if (user != null) {
            System.out.println("User Found: " + user);
        } else {
            System.out.println("User not found with ID: " + id);
        }
        scanner.close();
    }

    private static void getUserInputAndWriteToXML() throws Exception {
        Scanner scanner = new Scanner(System.in);

        // Taking user input for 10 users
        for (int i = 0; i < 2; i++) {
            System.out.println("Enter User ID, Name, Age, and Email for user " + (i + 1) + ":");
            int id = scanner.nextInt();
            String name = scanner.next();
            int age = scanner.nextInt();
            String email = scanner.next();

            users.put(id, new User(id, name, age, email));
        }
        writeToXML();
    }

    private static void readFromXML(File xmlFile) throws Exception {
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.parse(xmlFile);
        doc.getDocumentElement().normalize();

        NodeList nList = doc.getElementsByTagName("userInfo");

        for (int temp = 0; temp < nList.getLength(); temp++) {
            Node nNode = nList.item(temp);

            if (nNode.getNodeType() == Node.ELEMENT_NODE) {
                Element eElement = (Element) nNode;
                int id = Integer.parseInt(eElement.getAttribute("id"));
                String name = eElement.getElementsByTagName("name").item(0).getTextContent();
                int age = Integer.parseInt(eElement.getElementsByTagName("age").item(0).getTextContent());
                String email = eElement.getElementsByTagName("email").item(0).getTextContent();

                users.put(id, new User(id, name, age, email));
            }
        }
    }

    private static void writeToXML() throws Exception {
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.newDocument();

        // root element
        Element rootElement = doc.createElement("usersInfo");
        doc.appendChild(rootElement);

        for (User user : users.values()) {
            Element userElement = doc.createElement("usersInfo");
            userElement.setAttribute("id", String.valueOf(user.id));
            rootElement.appendChild(createUserElement(doc, "name", user.name));
            rootElement.appendChild(createUserElement(doc, "age", String.valueOf(user.age)));
            rootElement.appendChild(createUserElement(doc, "email", user.email));
        }

        // Write the content into XML file
        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        DOMSource source = new DOMSource(doc);
        StreamResult result = new StreamResult(new File(FILENAME));

        transformer.transform(source, result);
    }

    private static Node createUserElement(Document doc, String name, String value) {
        Element node = doc.createElement(name);
        node.appendChild(doc.createTextNode(value));
        return node;
    }

    static class User {
        int id;
        String name;
        int age;
        String email;

        User(int id, String name, int age, String email) {
            this.id = id;
            this.name = name;
            this.age = age;
            this.email = email;
        }

        @Override
        public String toString() {
            return "ID: " + id + ", Name: " + name + ", Age: " + age + ", Email: " + email;
        }
    }
}
