#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 100005;

vector<int> graph[MAXN];
vector<int> prints;
bitset<MAXN> visited;
int id[MAXN];
int N;

void DFS(int node){//Runs a sort of floodfill to create a bipartite graph
	for(int n: graph[node]){
		if(!visited[n]){
			visited.set(n);
			id[n]=1^id[node];
			DFS(n);
		}
	}
}

int main(){
	
	cin>>N;
	int a,b;
	for(int i=1;i<N;i++){
		cin>>a>>b;
		prints.push_back(a);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	id[1]=0;
	DFS(1);
	for(int a:prints){
		cout<<id[a]<<endl;
	}
	return 0;
}
