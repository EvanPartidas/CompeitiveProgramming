#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;

vector<int> graph[MAXN];

int dp[MAXN][2];

int help(int node,int parent,bool useable){
	if(dp[node][useable])
		return dp[node][useable]-1;
	int m1=0,m2=1;
	for(int dest:graph[node]){
		if(dest==parent) continue;
		m1 += help(dest,node,1);
		if(useable)
			m2 += help(dest,node,0);
	}
	if(!useable)
		m2=0;
	return (dp[node][useable] = (max(m1,m2)+1))-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	for(int i=1;i<N;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout<<help(1,1,1);
	return 0;
}
