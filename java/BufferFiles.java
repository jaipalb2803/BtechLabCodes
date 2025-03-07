
import java.io.*;

class BufferFiles
{
     public static void main(String... argv){
          
          try
          {
               BufferedReader br=new BufferedReader(new FileReader("DisplayFiles.java"));
               BufferedWriter bw=new BufferedWriter(new FileWriter("sample.txt",false));
               String line=br.readLine();

               while(line!=null)
               {     
                    bw.write(line);
                    bw.newLine();
                    line=br.readLine();
                   
               }
               bw.flush();
               bw.close();
               br.close();

          }
          catch (IOException e)
          {
                System.out.println(e.getMessage());
          }

     }

}