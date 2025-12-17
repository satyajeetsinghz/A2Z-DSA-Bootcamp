import java.util.*;

public class ans{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter size: ");
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<arr.length;i++){
            System.out.print("Enter element: ");
            arr[i]=sc.nextInt();
        }

        System.out.println("IsPresent: "+ isTwoSUm(arr, 4));

    }

    public static boolean isTwoSUm(int arr[],int element){
        Set<Integer> st=new HashSet<>();
        for(int x:arr){
            if(st.contains(element-x))return true;
            else st.add(x);
        }
        return false;
    }
}