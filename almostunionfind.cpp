#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int set[MAXN];
int size[MAXN];
int sum[MAXN];
vector<int> children[MAXN];


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
	size[a]+=size[b];
	sum[a]+=sum[b];
}

int N,M;
int main(){

	while(!cin.eof()){
		cin>>N>>M;
		int type,p,q;
		cin>>type>>p;
		switch(type){
			case 1:{
				cin>>q;
				merge(p,q);
				break;
			}
			case 2:{
				cin>>q;
				merge(p,q);
				break;
			}
			case 3:{
				printf("%d %d\n",size[p],sum[p]);
				break;
			}
		}
	}
	return 0;
}
