#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 20005;
const int MAXM = 30005;
vector<pair<int,int>> res;//Residual Graph
struct EDGE{
	long long weight;
	int start;
	int end;
	bool operator<(const EDGE &c)const{
		return weight>c.weight;
	}
};

int set[MAXN];//Disjoint Set
int subsize[MAXN];//Size of tree
int find(int node){
	if(set[node]==node)
		return node;
	int tmp = find(set[node]);
	set[node] = tmp;
	return tmp;
}
void merge(int a,int b){
	a = find(a);
	b = find(b);
	set[a]=b;
	subsize[b]+=subsize[a];
}

int N,M;
int main(){
	int i;
	priority_queue<EDGE> q;
	while(true){
		cin>>N>>M;
		if(N==0)	
				break;
		for(i=0;i<N;i++){
			subsize[i]=1;
			set[i]=i;
		}
		res.clear();
		for(i=0;i<M;i++){
			int a,b,w;
			cin>>a>>b>>w;
			if(a<b)
				q.push(EDGE{w,a,b});
			else
				q.push(EDGE{w,b,a});
		}
		long long sum=0;
		while(!q.empty()){
			auto edge = q.top();
			q.pop();
			if(find(edge.start)==find(edge.end))
				continue;
			merge(edge.start,edge.end);
			res.push_back(make_pair(edge.start,edge.end));
			sum+=edge.weight;
		}
		if(subsize[find(0)]<N)
			puts("Impossible");
		else{
			cout<<sum<<endl;
			sort(res.begin(),res.end());
			for(auto ed:res)
				printf("%d %d\n",ed.first,ed.second);
		}
	}
	return 0;
}
