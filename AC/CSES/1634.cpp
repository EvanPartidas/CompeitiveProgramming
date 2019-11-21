#include <iostream>

using namespace std;

const int MAXN = 105;
const int MAXX = 2e6+5;
const int INF = 2e9;
int dp[MAXX];
int coins[MAXN];

int main(){
	int N,X;
	cin>>N>>X;
	for(int i=0;i<N;i++){
		cin>>coins[i];
	}
	for(int i=1;i<=X;i++){
		dp[i]=INF;
	}
	int j;
	for(int i=0;i<X;i++){
		for(j=0;j<N;j++)
			dp[coins[j]+i]=min(dp[coins[j]+i],dp[i]+1);
	}
	if(dp[X]==INF)
		cout<<-1;
	else
		cout<<dp[X];
	return 0;
}
