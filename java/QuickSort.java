import java.util.*;

public class QuickSort{
    public static int partition(String[] a, int l, int h) {
        String pivot = a[h];
        int i = l - 1;

        for (int j = l; j < h; j++) {
            if (a[j].compareTo(pivot) < 0) {
                i++;
                swap(a, i, j);
            }
        }

        swap(a, i + 1, h);
        return i + 1;
    }

    public static void swap(String[] a, int i, int j) {
        String temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    public static void printArray(String[] arr) {
        for (String value : arr) {
            System.out.print(value + "\t");
        }
        System.out.println();
    }
    public static void quickSort(String[] a, int low, int high) {
        if (low < high) {
            int pivot= partition(a, low, high);
            quickSort(a, low, pivot - 1);
            quickSort(a, pivot + 1, high);
        }
    }
    public static void readStrings(String a[],int n,Scanner sc)
    {
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter the name-"+(i+1)+" :");
            a[i]=sc.nextLine();
        }
    }
    public static void main(String[] args) {

        System.out.print("Enter the no of names=");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        
        String[] names;
        names=new String[n];
        readStrings(names,n,sc);
        System.out.println("Before sorting:");
        printArray(names);

        quickSort(names, 0, n- 1);

        System.out.println("After sorting:");
        printArray(names);
    }
}
