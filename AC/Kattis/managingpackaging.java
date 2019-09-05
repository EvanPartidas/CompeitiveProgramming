import java.io.*;
import java.util.*;

public class managingpackaging {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t,size,i;
        PriorityQueue<Node> order;
        LinkedList<Node> fin;
        while((t=Integer.parseInt(br.readLine()))!=0){
            size = t;
            HashMap<String,Node> map = new HashMap<>();
            while(t-->0){
                String[] ln = br.readLine().split(" ");
                if(!map.containsKey(ln[0])){
                    map.put(ln[0],new Node(ln[0]));
                }
                for(i=1;i<ln.length;i++){
                    if(!map.containsKey(ln[i]))
                        map.put(ln[i],new Node(ln[i]));
                    map.get(ln[i]).packages.add(map.get(ln[0]));
                    map.get(ln[0]).inedges++;
                }
                
            }
            order = new PriorityQueue<>();
            fin = new LinkedList<>();
            for(String s:map.keySet()){
                if(map.get(s).inedges<1)
                    order.add(map.get(s));
            }
            
            /*
            Now we run Topsort. (Topological Sort)
            Essentially Djikstra's algorithm run on the number of inedges a node has
            */
            while(!order.isEmpty()){
                Node n = order.remove();
                for(Node a:n.packages){
                    a.inedges--;
                    if(a.inedges<1)
                        order.add(a);
                }
                fin.add(n);
            }
            if(fin.size()>=size)
                for(Node n:fin){
                    bw.write(n.me);
                    bw.newLine();
                }
            else{
                bw.write("cannot be ordered");
                bw.newLine();
            }
            bw.newLine();
            bw.flush();
        }
    }
}
class Node implements Comparable<Node>{
    public int inedges;
    public HashSet<Node> packages;
    public String me;
    public Node(String o){
        packages = new HashSet();
        me = o;
        inedges = 0;
    }
    public String toString(){
        return me;
    }
    public int compareTo(Node n){
        int a = inedges-n.inedges;
        return a==0?me.compareTo(n.me):a;
    }
}