import java.util.Scanner;

public class spavanac {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner scan = new Scanner(System.in);
        int h = scan.nextInt();
        int m = scan.nextInt();
        int sub=0;
        if(m<45){
            m=m+60-45;
            sub++;
        }
        else
            m-=45;
        if(h<sub){
            h=h+24-sub;
        }
        else
            h-=sub;
        System.out.println(h+" "+m);
        scan.close();
    }

}
