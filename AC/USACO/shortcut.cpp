#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 10005;
const int MAXM = 50005;
const int MAXT = 10005;

unordered_map<int,long long> graph[MAXN];//The input graph

long long cows[MAXN];//Number of cows at each point

long long dist[MAXN];//Min Distance from field one

int dest[MAXN];

int pointers[MAXN];//Topsort order of the residual graph

long long N,M,T;

bool cmp(int a,int b){
	return dist[a]>dist[b];
}

struct edge
{
	int dest;
	int start;
	long long weight;
	bool operator<(const edge& rhs) const
	{
		if(weight==rhs.weight)
			return start>rhs.start;
		return weight>rhs.weight;
	}
};

int main(){
	long long i,a,b,t;
	ifstream in;
	ofstream out;
	in.open("shortcut.in");
	out.open("shortcut.out");
	
	in>>N>>M>>T;

	for(i=0;i<N;i++){
		in>>cows[i];
		pointers[i]=i;
	}

	for(i=0;i<M;i++){
		in>>a>>b>>t;
		if(graph[a-1].find(b-1)==graph[a-1].end()){
			graph[a-1][b-1]=t;
			graph[b-1][a-1]=t;
		}
		else{
			graph[a-1][b-1]=min(graph[a-1][b-1],t);
			graph[b-1][a-1]=min(graph[b-1][a-1],t);
		}
	}

	priority_queue<edge> queue;
	
	for(auto p:graph[0]){
		queue.push(edge{p.first,0,p.second});
		//cout<<"W:"<<p.second<<" D:"<<p.first<<endl;
	}
	
	edge e;
	while(queue.size()>0){//Run Dijkstra's from field 1
		e = queue.top();
		queue.pop();
		//cout<<"W:"<<e.weight<<" D:"<<e.dest<<" S:"<<e.start<<endl;
		
		if(dist[e.dest]==0){
			for(auto p:graph[e.dest]){
				if(dist[p.first]||p.first==0)
					continue;
				queue.push(edge{p.first,e.dest,p.second+e.weight});
			}
			dist[e.dest] = e.weight;
			dest[e.dest] = e.start;
		}
		else if(dist[e.dest]==e.weight)
			dest[e.dest]=min(dest[e.dest],e.start);
	}
	//for(i=0;i<N;i++){
	//	cout<<dist[i]<<" ";
	//}
	
	//cout<<endl;
	
	//Construct implicit residual graph (Topsort)
	sort(pointers,pointers+N,cmp);
	
	
	long long maxSavings=0;
	int field;
	for(i=0;i<N;i++){
		field = pointers[i];
		maxSavings = max(maxSavings,cows[field]*(dist[field]-T));
		//cout<<dist[field]<<endl;
		cows[dest[field]]+=cows[field];
	}
	cout<<maxSavings;
	out<<maxSavings;
	return 0;
}
