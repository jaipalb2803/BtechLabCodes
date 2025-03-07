import java.security.MessageDigest;

public class MD5 {
     public static void main(String args[])
     {
        try{
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter the plainText:");
            String pT=sc.nextLine();

            MessageDigest md5=MessageDigest.getInstance("MD5");
            byte[] hash=md5.digest(pT.getBytes());

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
