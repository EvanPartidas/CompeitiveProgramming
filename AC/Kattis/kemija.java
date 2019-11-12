import java.io.*;

public class Kemija {

    static long[] N,A,fin;
    static int n;
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int i;
        N = new long[n];
        A = new long[n]; //First two slots are empty
        fin = new long[n];

        for(i=0;i<n;i++){
            N[i] = Long.parseLong(br.readLine());
        }
        long minA =0,minB=0;
        for(i=2;i<n;i++){
            A[i] = N[i-1] - A[i-1] - A[i-2];
            if(i%3==0)
                minA = Math.min(minA, A[i]);
            if(i%3==1)
                minB = Math.min(minB, A[i]);
        }

        switch(n%3){
        case 0:{fin[0] = Math.abs(minA);fin[1]=Math.abs(minB);break;}
        case 1:{mod1();break;}
        case 2:{mod2();break;}
        }

        for(i=2;i<n;i++){
            fin[i] = N[i-1] - fin[i-1] - fin[i-2];
        }

        for(i=0;i<n;i++){
            System.out.println(fin[i]);
        }
        
        br.close();
    }

    public static void mod1(){
        long alpha = N[n-1]-A[n-1]-A[n-2],
                beta = N[0] - A[n-1];
        fin[0] = Math.abs((alpha+beta)/3);
//      System.out.printf("Alpha:%d\nBeta:%d\n",alpha,beta);
        fin[1] = Math.abs((alpha+beta)/3 - alpha);
        
    }

    public static void mod2(){
        long alpha = N[n-1]-A[n-1]-A[n-2],
                beta = N[0] - A[n-1];
        long tmp = (alpha+beta)/3;
//      System.out.printf("Alpha:%d\nBeta:%d\nTmp:%d\n",alpha,beta,tmp);
        fin[0] = Math.abs(alpha - tmp);
        fin[1] = Math.abs(beta - tmp);
    }
}
