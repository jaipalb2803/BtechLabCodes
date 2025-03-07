import java.util.*;

public class HillCipher {
    public static  String TEXT="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void readMatrix(int[][] K,int n,Scanner sc){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                 K[i][j]=sc.nextInt();
    }
    public static void matrixMul(int[][] P,int[][] K,int[][] C,int n){
        for(int i=0;i<n;i++){
            C[i][0]=0;
            for(int k=0;k<n;k++)
                 C[i][0]+=K[i][k]*P[k][0];
            C[i][0]%=26; 
        }
    }
    public static String processText(int[][] K,String text,int n)
    {
           StringBuilder sb=new StringBuilder();
           for(int i=0;i<text.length();i+=n)
           {
              int[][] P=new int[n][1],C=new int[n][1];
              for(int j=0;j<n;j++)
                 P[j][0]=TEXT.indexOf(text.charAt(i+j));
              matrixMul(P,K,C,n);
              for(int j=0;j<n;j++) 
                sb.append(TEXT.charAt(C[j][0]));    
           }
           return sb.toString();
    }
    public static void main(String[] args) { 
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Matrix size=");
        int n=sc.nextInt();

        int[][] K=new int[n][n];
        System.out.println("Enter the key Matrix:");
        readMatrix(K,n,sc);
 
        System.out.print("Enter the plainText:");
        String P=sc.next().toUpperCase();

        if(P.length()%n==0){
            String C=processText(K,P,n);
            System.out.println("Encrypted Text:"+C);
            System.out.println("Enter the key inverse Matrix:");
            readMatrix(K,n,sc);
            System.out.println("Decrypted Text:"+processText(K,C,n));
        }else{
            System.out.print("ERROR");
        }

    }    

}
