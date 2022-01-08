import java.util.*;



// max sum pair 
// problem: it states that you have to make a dataStructure 
// that perform to operations 
// 1. insert(Key,Value)  2. Sum(prefix)
// and we have to return the sum of all values of the keys of hashmap 
// whose key start with the prefix String.


public class Main{

    // creating trie node
    static class TrieNode{
        int sum;
        TrieNode[] children = new TrieNode[26];
        TrieNode(){
            this.sum = 0;
            for(int i = 0 ; i < 26; i++){
                this.children[i] = null;
            }
        }
    }

    // this function inserts the value of key to the all
    // nodes and if we get a duplicate String then 
    // we reduce the effect of previous string ont to 
    // the all nodes....

    public static void insert(String key,int value){
        if(hm.containsKey(key)){
            int ans = hm.get(key);
            hm.put(key,value);
            value -= ans;
        }
        TrieNode temp = root;
        int len = key.length();
        for(int i = 0; i<len ; i++){
            int index = key.charAt(i) - 'a';
            if(temp.children[index] == null)
                temp.children[index] = new TrieNode();
            temp.sum += value;
            temp = temp.children[index];
        }
        temp.sum += value;
    }

// find the value from the map whose key start with the key string prefix
    public static int Sum(String prefix){
        int len = prefix.length();
        TrieNode temp = root;
        for(int i = 0; i<len ; i++){
            int index = prefix.charAt(i) - 'a';
            if(temp.children[index] == null)
                return 0;
            temp = temp.children[index];
        }
        return temp.sum;
    }

    static TrieNode root;
    static HashMap<String,Integer> hm;
    
    public static void main(String[] args){
        root = new TrieNode();
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        hm = new HashMap<String,Integer>();
        String []str = new String[n];
        int []value = new int[n];
        for(int i=0; i<n ; i++){
           String Str = scn.next();
           Integer integer = scn.nextInt();
           insert(Str,integer);
        }

        System.out.println(" how much query you want to perform on the map : ");
        int no = scn.nextInt();
        for(int i=0;i<no;i++){
            String prefix = scn.next();
            int ans = Sum(prefix);
            System.out.println(" sum of prefix "+ans+ " string is : "+ans);
        }
    }
}











/*

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



*/







// import java.util.*;

// public class Main{

//     static class TrieNode{
//         TrieNode[] child = new TrieNode[26];
//         boolean end;
//         TrieNode(){
//             this.end = false;
//             for(int i=0;i<26;i++){
//                 this.child[i] = null;
//             }
//         }
//     };

//     static TrieNode root;
//     static void Insert(String str){
//         TrieNode temp = root;
//         int len = str.length();
//         for(int i=0;i<len;i++){
//             int index = str.charAt(i) - 'a';
//             if(temp.child[index] == null){
//                 temp.child[index] = new TrieNode();
//             }
//             temp = temp.child[index];
//         }
//         temp.end = true;
//     }

//     static boolean search(String str){
//         if(root == null){
//             return false;
//         }
//         TrieNode temp = root;
//         int n = str.length();
//         for(int i=0;i<n;i++){
//             int index = str.charAt(i) - 'a';
//             if(temp.child[index] == null){
//                 return false;
//             }
//             temp = temp.child[index];
//         }
//         return (temp.end == true)?true:false;
//     }

//     static void Display(TrieNode temp , String asf){
//         if(root == null)
//         return;
//         if(temp.end == true){
            
//             System.out.println(asf);
//         }
//         // System.out.println(asf);
//         for(int i=0;i<26;i++){
        
//             if(temp.child[i] != null){
//                 Display(temp.child[i],asf+(char)(i+97));
//             }
//         }
//     }

//     static int minimumWordBreak(String str,Map<String,Integer> map){
        
//         return 0;
//     }

//     public static void main(String[] args){
//         Scanner scn = new Scanner(System.in);
//         int n = scn.nextInt();
         
//         Map<String,boolean> hm = new HashMap<String,boolean>();

//         String[] arr = new String[n];
//         for(int i=0;i<n;i++){
//             arr[i] = scn.next();
//             hm.put(arr[i],false);
//         }

      
//         root = new TrieNode();
//         for(int i=0;i<n;i++){
//               Insert(arr[i]);
//         }
//         // Display(root,"");
//         boolean res = search("cat");
//         if(res){
//             System.out.println("cat is found in the trie ");
//         }else{
//             System.out.println("cat is not found in the trie");
//         }
//         System.out.println("enter the string : ");
//         String str = scn.next();
//         int ans = minimumWordBreak(str,hm);
//         System.out.println("minimum word required are : " + ans);
//     }

// }