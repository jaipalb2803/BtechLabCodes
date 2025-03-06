import javax.crypto.*;
import java.util.*;

public class DES {
    try{
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the plainText:");
        String pT=sc.nextLine();

        SecretKey sk=KeyGenerator.getInstance("DES").generateKey();
        Cipher c=Cipher.getInstance("DES");
        System.out.println("Generated key"+Base64.getEncoder().encodeToString(sk.getEncoded()));

        //Encrypt
        c.init(Cipher.ENCRYPT_MODE,sk);
        String eT=Base64.getEncoder().encodeToString(c.doFinal(pT.getBytes()));
        System.out.println("Encrypted Text="+eT);

        //Decrypt
        c.init(Cipher.DECRYPT_MODE,sk);
        String dT=new String(c.doFinal(Base64.getDecoder().decode(eT)));
        System.out.println("Decrypted Text="+dT);
    }catch(Exception e){
        e.printStackTrace();
    }
  }
}
