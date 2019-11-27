#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MAXX = 1e5+5;

int dp[MAXN][MAXX];
int cost[MAXN],pages[MAXN];

int N,X;

int main(){

	cin>>N>>X;
	for(int i=1;i<=N;i++){
		cin>>cost[i];		
	}
	for(int i=1;i<=N;i++){
		cin>>pages[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<=X;j++){
			if(j>=cost[i])
				dp[i][j] = max(dp[i-1][j], pages[i] + dp[i-1][j-cost[i]]);
			else
				dp[i][j]=dp[i-1][j];
		} 
	}
	cout<<dp[N][X];
	return 0;
}
