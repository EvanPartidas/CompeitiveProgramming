#include <iostream>

using namespace std;

const int INF = 2e9;
const int MAXN = 1e6+5;
int dp[MAXN];

int method(int n){
	if(!n)
		return 0;
	if(dp[n])
		return dp[n];
	int ret = INF;
	int tmp=n;
	while(tmp){
		if(tmp%10>0)
			ret = min(ret,1+method(n-(tmp%10)));
		tmp/=10;
	}
	return dp[n]=ret;
}

int main(){
	int N;
	cin>>N;
	cout<<method(N);
	return 0;
}
