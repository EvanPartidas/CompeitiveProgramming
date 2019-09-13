import java.io.*;
import java.util.*;

public class BlockCrusher {

	int dist[][];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		while(true){
			int rows=0, cols=0;
			{
				String[] ln = br.readLine().split(" ");
				rows = Integer.parseInt(ln[0]);
				cols = Integer.parseInt(ln[1]);
			}
			if(rows<1){
				break;
			}
			dist = new int[rows][cols];
			PriorityQueue<Point> queue = new PriorityQueue<Point>();
	 			int[][] map = new int[rows][cols];
		       for(int i=0;i<map.length;i++){
				String ln = br.readLine();
				for(int j=0;j<map[0].length;j++){
					map[i][j]=Integer.parseInt(""+ln.charAt(j));
					if(i<1){
						queue.add(new Point(i,j,map[i][j]));
				        }
				}
		        }
                	Point end;
			while((end=emptyQueue(queue,map))==null){}
			while(end!=null){
				map[end.x][end.y]=-1;
				end = end.prev;
			}
			for(int i=0;i<map.length;i++){
				for(int j=0;j<map[0].length;j++){
					bw.write(map[i][j]>-1?Integer.toString(map[i][j]):" ");
				}
				bw.newLine();
				bw.flush();
			}
			bw.newLine();
            }
            bw.close();
	}

	//WORKING ON THIS FUNCTION
	public static Point emptyQueue(PriorityQueue<Point> queue, int[][] map){
		Point p = queue.remove();
		int x=p.x,y=p.y;
		if(x+1>=map.length)
			return p;
		if(goTo(map,x+1,y-1)){
			queue.add(new Point(x+1,y-1,map[x+1][y-1]+p.cost,p));
		}
		if(goTo(map,x+1,y)){
		 	queue.add(new Point(x+1,y,map[x+1][y]+p.cost,p));
		}
		if(goTo(map,x+1,y+1)){
			queue.add(new Point(x+1,y+1,map[x+1][y+1]+p.cost,p));
		}
		if(goTo(map,x,y+1)){
			queue.add(new Point(x,y+1,map[x][y+1]+p.cost,p));
		}
		if(goTo(map,x,y+1)){
			queue.add(new Point(x,y+1,map[x][y+1]+p.cost,p));
		}
		return null;
	}
	

    public static boolean goTo(int[][] map, int x, int y){
        try{
            @SuppressWarnings("unused")
            int a = map[x][y];
            return true;
        }catch(Exception e){return false;}
    }
    public static class Point implements Comparable<Point>, Cloneable{
        int x,y,cost;
        Point prev;
        public Point(int x,int y,int cost){
            this.x=x;
            this.y=y;
            this.cost=cost;
            prev = null;
        }
        @SuppressWarnings("unchecked")
        public Point(int x,int y,int cost,Point p){
            this.x=x;
            this.y=y;
            this.cost=cost;
            prev = p;
        }
        @Override
        public int compareTo(Point o) {
            return cost-o.cost;
        }
    }
}
