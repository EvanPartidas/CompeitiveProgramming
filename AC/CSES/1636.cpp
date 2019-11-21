#include <iostream>

using namespace std;

const int MAXN = 105;
const int MAXX = 2e6+5;
const int MOD = 1e9+7;

int coins[MAXN];
long long dp[MAXX];

int main(){

	int N,X;
	cin>>N>>X;
	for(int i=0;i<N;i++)
		cin>>coins[i];
	dp[0]=1;
	for(int j=0;j<N;j++){
		for(int i=0;i<X;i++){
				dp[i+coins[j]] += dp[i];
				dp[i+coins[j]] %= MOD;
		}
	}
	cout<<dp[X];
	return 0;
}
