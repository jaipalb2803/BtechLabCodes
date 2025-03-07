import javax.crypto.*;
import java.util.*;

public class RC4 {
     public static byte[] encryptRC4(String text,String key)
     {
        byte[] S=new byte[256],T=key.getBytes(),data=text.getBytes();
        for(int i=0,j=0;i<256;i++)
        {
            S[i]=(byte)i;
            j=(j+S[i]+T[i%T.length])&0xFF;
            byte temp=S[i];
            S[i]=S[j];
            S[j]=temp;
        }
        for(int i=0,j=0,k=0;k<data.length;k++)
        {
            i=(i+1)&0xFF;
            j=(j+S[i])&0xFF;
            byte temp=S[i];
            S[i]=S[j];
            S[j]=temp;
            data[k]^=S[(S[i]+S[j])&0xFF];
        } 
        return data;   
     }
     public static byte[] encryptBlowfish(String text,SecretKey key) throws Exception
     {
        Cipher cipher=Cipher.getInstance("Blowfish");
        cipher.init(Cipher.ENCRYPT_MODE,key);
        return cipher.doFinal(text.getBytes());
     } 
     public static void main(String args[])
     {
        try{
            String rc4Text="hello",rc4key="key";
            System.out.println("RC4 Encrypt="+new String(encryptRC4(rc4Text,rc4key)));

            SecretKey blowfishKey=KeyGenerator.getInstance("Blowfish").generateKey();
            System.out.println("Blowfish Encrypted="+new String(encryptBlowfish(rc4Text,blowfishKey)));
        }
        catch(Exception e){
            e.printStackTrace();
        }


     }
}
