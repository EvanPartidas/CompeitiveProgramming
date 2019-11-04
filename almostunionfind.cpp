#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 100005;

int set[MAXN];
int count[MAXN];
long long sum[MAXN];
unordered_set<int> children[MAXN];


int find(int node){
	if(set[node]==node)
		return node;
	int parent = set[node];
	set[node] = find(set[node]);
	if(set[node]!=parent)
		children[parent].erase(node);
	return set[node];
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	set[b]=a;
	children[a].insert(b);
	count[a]+=count[b];
	sum[a]+=sum[b];
}

void remove(int node){
	int root = find(node);
	if(root==node){
		bool first= true;
		for(int child:children[node]){
			if(first){
				set[node]=child;
				root = child;
				count[root]= count[node]-1;
				sum[root]=sum[node]-node;
				first = false;
			}
			find(child);
		}
	}
	else{
		for(int child:children[node]){
			find(child);
		}
		count[root]--;
		sum[root]-= node;
	}
	count[node]= 1;
	sum[node]= node;
	set[node]= node;
}

int N,M;
int main(){

	while(!cin.eof()){
		cin>>N>>M;
		for(int i=0;i<=N;i++){
			count[i]=1;
			set[i]=i;
			sum[i]=i;
			children[i].clear();
		}
		int type,p,q;
		while(M-->0){
			cin>>type>>p;
			switch(type){
				case 1:{
					cin>>q;
					merge(p,q);
					break;
				}
				case 2:{
					cin>>q;
					if(find(p)==find(q))
						break;
					remove(p);
					merge(p,q);
					break;
				}
				case 3:{
					p = find(p);
					cout<<count[p]<<" "<<sum[p]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
