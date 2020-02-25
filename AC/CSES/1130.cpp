#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;

vector<int> edges[MAXN];
int edge[MAXN][2];

int dp[MAXN][2];

int help(int e,int parent,bool useable){
	if(dp[e][useable])
		return dp[e][useable]-1;
	int d = edge[e][0]==parent?1:0;
	int n = edge[e][d];
	int sum = 0,m=0;
	for(int toedge:edges[n]){
		if(toedge==e) continue;
		sum+=help(toedge,n,0);
	}
	if(useable)
		m = sum+1;
	for(int toedge:edges[n]){
		if(toedge==e) continue;
		m=max(sum-help(toedge,n,0)+help(toedge,n,1),m);	
	}
	return (dp[e][useable]=1+max(m,sum))-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	for(int i=1;i<N;i++){
		int a,b;
		cin>>a>>b;
		edge[i][0]=a;
		edge[i][1]=b;
		edges[a].push_back(i);
		edges[b].push_back(i);
	}
	edge[0][0]=0;
	edge[0][1]=1;
	cout<<help(0,0,0);
	return 0;
}
