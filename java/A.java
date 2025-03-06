import java.util.*;

class A {
    private static int[] res=null;
    private static boolean backtrack(int index,int[] arr,boolean[] used,int n)
    {
        if(res!=null)
            return true;
        if(index>=arr.length){
            res=arr.clone();
            return true;
        }
        if (arr[index]!=0)
            return backtrack(index+1,arr,used,n);
        for(int i=n;i>=1;i--)
        {
            if(!used[i])
                continue;
            if(i==1||(index+i<arr.length && arr[index+i]==0))
            {
                arr[index]=i;
                if(i>1) arr[index+i]=i;
                used[i]=false;

                if(backtrack(index+1,arr,used,n))
                    return true;
                arr[index]=0;
                if(i>1)
                    arr[index+i]=i;
                used[i]=true;
            }
        }
        return  false;
    }
    public static int[] ConstructDistanceSequence(int n)
    {
        res=null;
        int[] arr=new int[2*n-1];
        boolean[] used=new boolean[n+1];
        Arrays.fill(used,true);
        backtrack(0,arr,used,n);
        return res;
    } 
    public static void main (String args[])
    {      
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number-");
        int n=sc.nextInt();
        int[] arr=new int[2*n-1];
        arr=ConstructDistanceSequence(n);
        for(int i=0;i<2*n-1;i++)
        System.out.print(arr[i]);      
    }
}
