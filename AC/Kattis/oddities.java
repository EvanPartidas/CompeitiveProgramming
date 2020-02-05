import java.util.*;
public class oddities {
    
    public static void main(String [] args){
        Scanner scan = new Scanner (System.in);
        int t = scan.nextInt ();
        while(t-->0){
            int lol = scan.nextInt();
            System.out.println(lol+(lol%2==0?" is even":" is odd"));
        }
        scan.close();
    }
    
}
