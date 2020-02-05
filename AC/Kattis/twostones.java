import java.util.Scanner;
public class twostones{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println(scan.nextInt()%2==1?"Alice":"Bob");
        scan.close();
    }
}
