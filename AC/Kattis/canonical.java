import java.util.Scanner;

public class canonical {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt(),i;
		int[] coins = new int[size];
		for(i=0;i<size;i++){
			coins[i] = scan.nextInt();
		}
		boolean can=true;
		size = coins[size-1]+coins[size-2];
		int[] dp = new int[size+1];
		for(i=1;i<dp.length;i++){
			int min=Integer.MAX_VALUE;
			for(int coin:coins){
				if(coin>i)
					break;
				min=Math.min(dp[i-coin]+1, min);
			}
			dp[i]=min;
			
			int count=0,coin=i,j;
			while(coin>0){
				for(j=coins.length-1;j>=0;j--){
					if(coins[j]<=coin)
						break;
				}
				count+=coin/coins[j];
				coin%=coins[j];
			}
			if(min!=count){
				can=false;
				break;
			}
		}
		System.out.println(can?"canonical":"non-canonical");
		scan.close();
	}
}
