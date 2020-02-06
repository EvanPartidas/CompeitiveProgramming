import java.util.Scanner;
public class bijele {

    public static void main(String[] args) {
        int[] pieces = {1,1,2,2,2,8};
        Scanner scan = new Scanner(System.in);
        for (int i=0;i<6;i++) {
            
            System.out.print((pieces[i] - scan.nextInt())+" ");
            
        }
        scan.close();
    }

}
