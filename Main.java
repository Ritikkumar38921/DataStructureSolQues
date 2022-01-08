import java.util.*;

//THIS PROBLEM IS ABOUT FINDING NUMBER OF PAIRS FROM THE ARRAY 
//THAT HAVE THE XOR VALUE LIE IN THE LOW AND UPPER range
//means find the pairs from the array whose xor is >= low AND
//whose xor should be equal to or less than high.

public class Main{

    static class Node{
        int child;
        Node left;
        Node right;
        Node(){
            this.left = this.right = null;
        }
    }

    public static void insert(int val , Node root){    
        for(int i = 14;i >= 0;i--){
            int bit = (1 << i) & 1;
            if(bit == 0){
                if(root.left == null)
                    root.left = new Node();
                root.child++;
                root = root.left;
            }else{
                if(root.right == null)
                    root.right = new Node();
                root.child++;
                root = root.right;
            }   
        }
    }

    public static int findChild(Node root){
        return (root == null)?0:root.child;
    }

    public static int Query(Node root,int value,int high,int Max_Bit){
        if(root == null){
            return 0;
        }
        if(Max_Bit == -1){
            return 1;
        }
        int bitV = (1 << Max_Bit) & value;
        int bitH = (1 << Max_Bit) & high;
        if(bitV == 0){
            if(bitH == 0){
                return Query(root.left,value,high,Max_Bit - 1);
            }else{
                return findChild(root.left) + Query(root.right,value,high,Max_Bit - 1);
            }
        }else{
            if(bitH == 0){
                return Query(root.right,value,high,Max_Bit - 1);
            }else{
                return findChild(root.right) + Query(root.left,value,high,Max_Bit - 1);
            }
        }
    }

    public static int countPairs(int []arr,int n,int low,int high){
        int count = 0;
        Node root = new Node();
        int i;
        for(i=0;i<n;i++){
            int a = Query(root,arr[i],high,14);
            int b = Query(root,arr[i],low-1,14);
            count = count + (a - b);
            insert(arr[i],root);
        }
        return count;
    }

    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = scn.nextInt();
        }
        int low,high;
        low = scn.nextInt();
        high = scn.nextInt();

        int res = countPairs(arr,n,low,high); 
        System.out.println("no. of pairs in the array lie in the range "+low+ " to "+high+" is : "+res);
    }
}











