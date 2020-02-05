import java.util.Scanner;

public class autori {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System .in);
        String[] str = scan.nextLine().split("-");
        for(String s:str){
            System.out.print(s.charAt(0));
        }
        scan.close();
    }
}
