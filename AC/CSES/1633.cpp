#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

long long dp[MAXN];

int main(){
	
	int N;
	cin>>N;
	for(int i=1;i<=6;i++){
		dp[i]=1;
	}
	for(int i=0;i<=N;i++){
		for(int j=1;j<=6;j++){
			if(i-j>0){
				dp[i]+=dp[i-j];
				dp[i]%=MOD;
			}
			else
				break;
		}
	}
	cout<<dp[N];
	return 0;
}
