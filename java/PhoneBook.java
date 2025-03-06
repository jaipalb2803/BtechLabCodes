import java.io.*;
import java.util.*;

public class PhoneBook {
    public static void main(String[] args) {
        Map<String, String> phoneBook = new HashMap<>();
        try {
            // Read data from the text file and populate the phoneBook HashMap
            BufferedReader br= new BufferedReader(new FileReader( "phonebook.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2)
                    phoneBook.put(parts[0], parts[1]);    
            }
            br.close();

            // Input from the user
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter a name or phone number to look up: ");
            String ui= sc.nextLine();
            // Search for the query in the phoneBook
            if (phoneBook.containsKey(ui)) {
                System.out.println("Name: " +ui+"\tPhNo:"+phoneBook.get(ui));
            }
            else if(phoneBook.containsValue(ui))
            {
                for (Map.Entry<String, String> e: phoneBook.entrySet()) {
                    if (e.getValue().equals(ui)) 
                        System.out.println("Name: " + e.getKey()+"\tPhNo:"+ui);
                }  
            }
            else {
                System.out.println("Entry not found in the phone book.");
            }
            sc.close();
        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }
}
