#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;

const int MAXC = 100005;

int edges[MAXC],topsort[MAXC],topsize,depth[MAXC];

unordered_map<int,vector<int>> graph;
vector<int> roots;

int C,L;

bool cmp(int a,int b){
	return depth[a]>depth[b];
}

int main(){

	cin>>C>>L;
	int i,a,b;
	for(i=0;i<C;i++){
		edges[i]=0;
		depth[i]=0;
	}
	for(i=0;i<L;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		edges[a]++;
		edges[b]++;
	}
	topsize = 0;
	for(i=0;i<C;i++){
		depth[i]=0;
		if(edges[i]==1){
			topsort[topsize++] = i;
		}
		else if(edges[i]==0){
			roots.push_back(i);
		}
	}
	i=-1;
	while(++i<topsize){
//		printf("%d Value:%d\n",i,topsort[i]);
		if(edges[topsort[i]]==0){
				roots.push_back(topsort[i]);
				continue;
		}
		for(int dest:graph[topsort[i]]){
//			printf("Source:%d Node:%d Edges:%d\n",topsort[i],dest,edges[dest]);
			if(depth[dest]){//If we have relaxed the node already, skip it
				edges[dest]--;
				continue;
			}
			if(--edges[dest]==1){
				depth[dest] = 1+depth[topsort[i]];
				topsort[topsize++] = dest;
			}
		}
		
	}
	
//	for(i=0;i<roots.size();i++){
//		printf("Root:%d Depth:%d\n",roots[i],depth[roots[i]]);
//	}
	sort(roots.begin(),roots.end(),cmp);
	if(roots.size()==1){
		cout<<depth[roots[0]]<<endl;
	}
	else{
		cout<<depth[roots[0]] + depth[roots[1]] + 1<<endl;
	}
	return 0;
}
