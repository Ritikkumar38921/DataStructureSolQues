import java.util.*;
import java.io.*;


class Graph{
    int n;
    private LinkedList<Integer> adj[];

    Graph(int n){
        this.n = n;
        adj = new LinkedList[n];
        for(int i = 0; i < n; i++){
            adj[i] = new LinkedList<Integer>();
        }
    }

    void addEdge(int u,int v){
        adj[u].add(v);
    }

    void dfs(boolean[] visited,Stack<Integer> st,int i){

        visited[i] = true;

        Iterator<Integer> itr = this.adj[i].iterator();

        while(itr.hasNext()){
            int ele = itr.next();
            if(visited[ele] == false){
                dfs(visited,st,ele);
            }
        }
        st.push(i);

    }

    void dfsUntil(boolean[] visited,LinkedList<Integer> list[],int ele){

        visited[ele] = true;

        System.out.print(ele + " ");

        Iterator<Integer> it = list[ele].iterator();

        while(it.hasNext()){
            int val = it.next();
            if(visited[val] == false){
                dfsUntil(visited,list,val);
            }
        }
        
    }

    int kosaraju_algo(){
        int n1 = this.n;
        Stack<Integer> st = new Stack<Integer>();
        boolean visited[] = new boolean[n1];

        for(int i = 0; i < n1; i++){
            visited[i] = false;
        }

        // do dfs according to finishing time of the visited node
        for(int i = 0; i < n1; i++){
            if(visited[i] == false){
                dfs(visited,st,i);
            }
        }
       
        LinkedList<Integer> reverse[];
        reverse = new LinkedList[n1];


        for(int i = 0; i < n1; i++){
            reverse[i] = new LinkedList<Integer>();
        }

        // transpose of the graph
        for(int i = 0; i < n1; i++){
            Iterator<Integer> it = this.adj[i].iterator();
            visited[i] = false;
            while(it.hasNext()){
                int ele = it.next();
                reverse[ele].add(i);
            }
        }

        int count = 0;

        // do dfs and finding the strongly connected components

        for(int i = 0; i < n1; i++){
            int top = (int)st.pop();
            if(visited[top] == false){
                dfsUntil(visited,reverse,top);
                System.out.println();
                count++;
            }
        }

        return count;

    }

}


public class KosarajuAlgo{

    public static void main(String[] args) throws Exception{
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

        int ans = obj.kosaraju_algo();
        System.out.println("there will be total " + ans + " SSC's");

    }
}