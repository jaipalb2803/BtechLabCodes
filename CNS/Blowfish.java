import javax.crypto.*;
import java.util.*;


public class Blowfish {
    public static void main(String[] args) {
        try {
            SecretKey secretKey = KeyGenerator.getInstance("Blowfish").generateKey(); // Generate Key
            Cipher cipher = Cipher.getInstance("Blowfish");

            System.out.println("Generated Key: " + Base64.getEncoder().encodeToString(secretKey.getEncoded()));
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the plainText: ");
            String plainText = sc.nextLine();

            // Encrypt
            cipher.init(Cipher.ENCRYPT_MODE, secretKey);
            String encryptedText = Base64.getEncoder().encodeToString(cipher.doFinal(plainText.getBytes()));
            System.out.println("Encrypted Text: " + encryptedText);

            // Decrypt
            cipher.init(Cipher.DECRYPT_MODE, secretKey);
            String decryptedText = new String(cipher.doFinal(Base64.getDecoder().decode(encryptedText)));
            System.out.println("Decrypted Text: " + decryptedText);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}