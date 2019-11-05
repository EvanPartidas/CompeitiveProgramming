#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 100005;
const int MAXM = 100005;

int set[MAXN+MAXM];
int count[MAXN+MAXM];
int map[MAXN];
long long sum[MAXN+MAXM];


int N,M,SIZE;

int find(int node){
	if(set[node]==node)
		return node;
	set[node] = find(set[node]);
	return set[node];
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	set[b]=a;
	count[a]+=count[b];
	sum[a]+=sum[b];
}

void remove(int node){
	int root = find(map[node]);
	count[root]--;
	sum[root]-=node;
	map[node]=SIZE;
	set[SIZE]=SIZE;
	SIZE++;
	count[map[node]]=1;
	sum[map[node]]=node;
}

int main(){

	while(!cin.eof()){
		cin>>N>>M;
		SIZE = N+1;
		for(int i=0;i<=N;i++){
			count[i]=1;
			set[i]=i;
			sum[i]=i;
			map[i]=i;
		}
		int type,p,q;
		while(M-->0){
			cin>>type>>p;
			switch(type){
				case 1:{
					cin>>q;
					if(find(map[p])==find(map[q]))
						break;
					merge(map[p],map[q]);
					break;
				}
				case 2:{
					cin>>q;
					if(find(map[p])==find(map[q]))
						break;
					remove(p);
					merge(map[p],map[q]);
					break;
				}
				case 3:{
					p = find(map[p]);
					cout<<count[p]<<" "<<sum[p]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
