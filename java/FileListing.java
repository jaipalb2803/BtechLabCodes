import java.io.File;

public class FileListing {
    public static void listFiles(String Path) {
        File dir = new File(Path);

        // Get all files and directories inside the specified directory
        File[] files = dir.listFiles();

        if (files != null) {
            for (File file : files) {
                if (file.isFile()) {
                    System.out.println("File: " + file.getAbsolutePath());
                } else if (file.isDirectory()) {
                    System.out.println("Directory: " + file.getAbsolutePath());
                    listFiles(file.getAbsolutePath()); // Recursively list files in subdirectories
                }
            }
        }
    }

    public static void main(String[] args) {
        String directoryPath = "C:\\Documents"; // Provide the path to your directory

        listFiles(directoryPath);
    }
}
