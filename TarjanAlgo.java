import java.io.*;
import java.util.*;

class Graph{

    private LinkedList<Integer> adj[];
    private int n;
    private int count;
    private int myAns;

    Graph(int n){
        this.n = n;
        this.count = 0;
        this.myAns = 0;
        adj = new LinkedList[n];
        for(int i = 0; i < n; i++){
            adj[i] = new LinkedList<Integer>();
        }

    }

    void addEdge(int u,int v){
        adj[u].add(v);
    }

    void dfs(Stack<Integer> st,int[] disc,int[] low,int index){

        disc[index] = this.count;
        low[index] = this.count;

        Iterator<Integer> itr = this.adj[index].iterator();
       
        while(itr.hasNext()){
            int ele = itr.next();
            if(disc[ele] == -1){
                
                this.count = this.count + 1;
                dfs(st,disc,low,ele);
                if(low[ele] < low[index]){
                    low[index] = low[ele];
                }
                
            }else{
                low[index] = (disc[ele] < low[index])?(disc[ele]):(low[index]);
            }
        }

        st.push(index);

        if(low[index] == disc[index]){
            while( (st.empty() == false)  && (low[st.peek()] == low[index])){
                int ele = (int)st.pop();
                System.out.print(ele + " ");
            }
            System.out.println();
            this.myAns++;
        }
        
    }

    int tarjanAlgorithm(){
        int n1 = this.n;
        Stack<Integer> st = new Stack<Integer>();
        int[] disc = new int[n1];
        int[] low = new int[n1];
        for(int i = 0; i < n1; i++){
           
            disc[i] = -1;
            low[i] = -1;
        }

        for(int i = 0; i < n1; i++){
            if(disc[i] == -1){
                dfs(st,disc,low,i);
            }
        }

        return this.myAns;
    }

}

public class TarjanAlgo{

    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int vert,e;
        vert = scn.nextInt();
        e = scn.nextInt();
        Graph obj = new Graph(vert);
        for(int i = 0; i < e; i++){
            int u,v;
            u = scn.nextInt();
            v = scn.nextInt();
            obj.addEdge(u,v);
        }

        int ans = obj.tarjanAlgorithm();
        System.out.println("there are " + ans + " SSC's ");

    }
}