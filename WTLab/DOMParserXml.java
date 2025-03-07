import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.util.Scanner;

class DOMParserXML {

  public static void main(String[] args) 
  {

    try {
      DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
      DocumentBuilder builder = factory.newDocumentBuilder();
      Document document = builder.parse("users.xml");
      document.getDocumentElement().normalize();
      
      NodeList userList = document.getElementsByTagName("user");
      Scanner scanner = new Scanner(System.in);
      System.out.print("Enter the User Id: ");
      int userId = scanner.nextInt();
     
      boolean found = false;
      
      for (int i = 0; i < userList.getLength(); i++) {
        Node userNode = userList.item(i);
        if (userNode.getNodeType() == Node.ELEMENT_NODE) {
          Element userElement = (Element) userNode;
          String id = userElement.getAttribute("id");
          int idNum = Integer.parseInt(id);
          if (userId == idNum) {
            found = true;
            System.out.println("User details:");

            NodeList nameList = userElement.getElementsByTagName("name");
            String name = nameList.item(0).getTextContent();
            System.out.println("Name: " + name);

            NodeList emailList = userElement.getElementsByTagName("email");
            String email = emailList.item(0).getTextContent();
            System.out.println("Email: " + email);
            
            NodeList passwordList = userElement.getElementsByTagName("password");
            String password = passwordList.item(0).getTextContent();
            System.out.println("Password: " + password);

            NodeList creditCardList = userElement.getElementsByTagName("credit_card");
            String creditCard = creditCardList.item(0).getTextContent();
            System.out.println("Credit card: " + creditCard);
            break;
          }
        }
      }
      if (!found) {
        System.out.println("User Id not found");
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}