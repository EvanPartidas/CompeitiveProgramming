#include <iostream>

using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;
const ll MOD = 1e9+7;
ll dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	dp[0]=1;
	for(ll i=1;i<=N;i++){
		dp[i]=i*dp[i-1]+(i%2?-1:1);
		dp[i]%=MOD;
	}
	cout<<dp[N];
	return 0;
}
