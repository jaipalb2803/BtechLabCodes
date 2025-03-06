import java.util.*;

public class ceaserCipher{
           public static final  String TEXT="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
           public static String encryption(String data,int key){
                      data=data.toUpperCase();
                      StringBuilder sb=new StringBuilder(data);
                      for(int i=0;i<data.length();i++){
		                int pos=TEXT.indexOf(data.charAt(i));
		                int shift=(pos+key)%26;
		                sb.setCharAt(i,TEXT.charAt(shift));
		      }
		      return sb.toString();	
           }
          public static String decryption(String data,int key){
                     data=data.toUpperCase();
                     StringBuilder sb=new StringBuilder(data);
                      for(int i=0;i<data.length();i++){
		                int pos=TEXT.indexOf(data.charAt(i));
		                int shift=(pos-key)%26;
		                sb.setCharAt(i,TEXT.charAt(shift));
		      }
		      return sb.toString();	 
           }
          public static void main(String[] args){
		    Scanner sc=new Scanner(System.in);
		    System.out.print("Enter the Text=");
		    String data=sc.nextLine();
		    System.out.print("Enter the key=");
		    int key=sc.nextInt();
	        System.out.println("Encrypted Text="+(data=encryption(data,key)));
	        System.out.println("Decrypted Text="+decryption(data,key));
		                                 
          }
}