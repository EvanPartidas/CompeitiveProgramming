#include <iostream>
#include <string.h>

using namespace std;

int dp[505][505];
bool visit[505][505];

int help(int a,int b){
	if(a==b)
		return 0;
	if(visit[a][b])
		return dp[a][b];
	int ret = 2e9;
	for(int sub =1;sub<=max(a,b)/2;sub++){
		if(a>sub)
			ret = min(ret,1+help(a-sub,b)+help(sub,b));
		if(b>sub)
			ret = min(ret,1+help(a,b-sub)+help(a,sub));
	}
	visit[a][b] = 1;
	return dp[a][b]=ret;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<help(a,b);
	return 0;
}
