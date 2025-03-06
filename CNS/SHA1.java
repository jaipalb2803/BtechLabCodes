import java.security.MessageDigest;

public class SHA1 {
     public static void main(String args[])
     {
        try{
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter the plainText:");
            String pT=sc.nextLine();

            MessageDigest sha1=MessageDigest.getInstance("SHA-1");
            byte[] hash=sha1.digest(pT.getBytes());

            StringBuilder hexString=new StringBuilder();
            for(byte b:hash){
                String hex=Integer.toHexString(0xff & b);
                if(hex.length()==1)
                    hexString.append('0');
                hexString.append(hex);
            }

            System.out.println("Original data="+pT);
            System.out.println("Hashed data="+hexString.toString());
        }
        catch(Exception e){
            e.printStackTrace();
        }


    }
}
