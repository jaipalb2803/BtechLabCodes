import java.util.*;

public class BubbleSort {
    public static void bubbleSortDescending(int[] arr) {
        int n = arr.length;
        int swaps = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swaps++;
                }
            }
        }

        System.out.println("Number of Interchanges: " + swaps);
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
    public static void readEle(int[] a,int n,Scanner sc)
    {
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter the number-"+(i+1)+" :");
            a[i]=sc.nextInt();
        }
    }
    public static void main(String[] args) {
        
        System.out.print("Enter no of ele=");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] a;
        a=new int[n];
        readEle(a,n,sc);
        bubbleSortDescending(a);

        System.out.println("After sorting:");
        printArray(a);
    }
}
