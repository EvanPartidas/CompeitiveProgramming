import java.util.*;
import java.io.*;

public class Main {
    
    static HashMap<String,ArrayList<String>> graph = new HashMap<>();
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int N;
        N = scan.nextInt();
        //Take in input
        for(int i=0;i<N;i++){
            String main = scan.next();
            String[] ln = scan.nextLine().trim().split(" ");//Trim gets rid of whitespace on the ends
            if(!graph.containsKey(main))
                graph.put(main, new ArrayList<>());
            for(String stat : ln){
                if(!graph.containsKey(stat))
                    graph.put(stat, new ArrayList<>());
                graph.get(stat).add(main);
                graph.get(main).add(stat);
            }
        }
        String start = scan.next();
        String end = scan.next();
        ArrayDeque<String> queue = new ArrayDeque<>();//Queue for BFS, stack for DFS
        HashMap<String,String> path = new HashMap<>();
        queue.add(start);
        path.put(start,start);
        //Start BFS
        while(!queue.isEmpty()){
            String point = queue.removeFirst();
            //System.out.println(point);
            if(graph.containsKey(point))
            for(String dest:graph.get(point)){
                if(!path.containsKey(dest)){
                    path.put(dest,point);
                    queue.add(dest);
                }
            }
        }
        
        if(path.containsKey(end)){
            Stack<String> ret = new Stack<>();
            String node = end;
            //Reconstruct the path, it is in reverse order so reverse it with a Stack
            while(true){
                ret.push(node);
                if(path.get(node).equals(node))
                    break;
                node = path.get(node);
            }
            while(!ret.isEmpty())
                System.out.print(ret.pop()+" ");
        }else{
            System.out.println("no route found");
        }
    }
}
