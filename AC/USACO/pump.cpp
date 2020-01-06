#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

typedef unsigned long long ll;

using namespace std;

const int MAXN = 1005;
const int MAXM = 1005;
const ll mult = 1e6;

int N,M;

ll cost[MAXM],flow[MAXM];
vector<pair<int,int>> graph[MAXN];
bitset<MAXN> visited;

bool DFS(int node, ll sum, ll minFlow, ll x){
	if(minFlow<sum)
		return false;
	if(node==N){
		return minFlow>=sum;
	}
	for(auto p:graph[node]){
		int n = p.first;
		if(visited[n])
			continue;
		visited.set(n);
		if(DFS(n,sum+x*cost[p.second],min(minFlow,flow[p.second]),x))
			return true;
		visited.reset(n);
	}
	return false;
	
}

int main(){
	ifstream in;
	ofstream out;
	in.open("pump.in");
	out.open("pump.out");
	in>>N>>M;
	
	for(int i=0;i<M;i++){
		int a,b,c,d;
		in>>a>>b>>c>>d;
		graph[a].push_back({b,i});
		graph[b].push_back({a,i});
		cost[i]=c;
		flow[i]=d*mult;
	}
	
	ll hi = 1e7;
	ll lo = 0;
	while(lo+1<hi){
		ll x = (lo+hi)/2;
		visited.reset();
		visited.set(1);
		if(DFS(1,0,1e15,x)){
			lo = x;
		}else{
			hi = x;
		}
	}
	out<<lo<<endl;
	cout<<lo<<endl;
	return 0;
}
