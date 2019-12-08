#include <iostream>

using namespace std;

const int MAXN = 5e3+5;

long long arr[MAXN];

long long dp[MAXN][MAXN];
bool visited[MAXN][MAXN];

long long help(int l,int r){
	if(l==r)
		return 0;
	if(visited[l][r])
		return dp[l][r];
	long long ret = max(arr[r]-arr[r-1]+help(l,r-1),arr[l]-arr[l-1]+help(l+1,r));
	visited[l][r]=1;
	return dp[l][r]=(arr[r] - arr[l-1] - ret);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	
	cout<<(arr[N]-help(1,N));
	
	return 0;
}
