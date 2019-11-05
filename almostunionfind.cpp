#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 100005;
const int MAXM = 100005;

int set[MAXN+MAXM];
int count[MAXN];
int map[MAXN];
long long sum[MAXN];


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
	map[node]=SIZE;
	set[SIZE]=SIZE;
	SIZE++;
	count[node]=1;
	sum[node]=node;
}

int main(){

	while(!cin.eof()){
		cin>>N>>M;
		SIZE = N;
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
