#include <iostream>

using namespace std;

const int MAXW = 65;
const int MAXH = 25;

int block[MAXW][MAXH];

int W,H;

int dp[MAXW][MAXH];

int sol[MAXH];

int main(){

	ios_base::sync_with_stdio(false);

	while(1){
		int i,j;
		cin>>H>>W;
		char c;

		if(H<1)
			break;

		for(j=0;j<H;j++)
			for(i=0;i<W;i++){
				cin>>c;
				block[i][j]=c-'0';
			}
		for(i=0;i<W;i++)
			dp[i][0] = block[i][0];
		int mindex;
		//Bottom-Up DP
		for(j=0;j<H;j++){
			mindex=0;
			for(i=0;i<W;i++){
				int tmin = dp[i][j-1];
				if(i>0)
					tmin = min(tmin,dp[i-1][j-1]);
				if(i<W-1)
					tmin = min(tmin,dp[i+1][j-1]);
				dp[i][j] = tmin+block[i][j];
				if(dp[i][j]<dp[mindex][j])
					mindex=i;
			}
			sol[j]=mindex;
		}

		for(j=H-2;j>=0;j--){
			int pos = sol[j+1];
			mindex=pos;
			if(pos>0&&dp[pos-1][j]<dp[mindex][j])
				mindex = pos-1;
			if(pos<W-1&&dp[pos+1][j]<dp[mindex][j])
				mindex = pos+1;
			sol[j]=mindex;
		}


		for(j=0;j<H;j++){
			for(i=0;i<W;i++){
				if(sol[j]!=i)
					cout<<block[i][j];
				else
					cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
