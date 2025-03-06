
import java.io.*;

class FilesReader_Writer
{
     public static void main(String... argv){
          
          try
          {
               FileReader fr=new FileReader(new File("DisplayFiles.java"));
               FileWriter fw=new FileWriter(new File("sample.txt"),true);
               int ch=fr.read();
               fw.write("\n");
               while(ch!=-1)
               {     
                    fw.write(ch);
                    //bw.newLine();
                    ch=fr.read();
                   
               }
               fw.flush();
               fw.close();
               fr.close();

          }
          catch (IOException e)
          {
                System.out.println(e.getMessage());
          }

     }

}