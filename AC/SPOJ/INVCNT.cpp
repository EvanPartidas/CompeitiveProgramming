#include <iostream>
#include <fstream>
#include <math.h>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;

ll fen[MAXN];
int arr[MAXN];

void add(int ind,int delta){
	while(ind<MAXN){
		fen[ind]+=delta;
		ind+=ind&-ind;
	}
}

ll sum(int ind){
	ll ret = 0;
	while(ind>0){
		ret+=fen[ind];
		ind-=ind&-ind;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T-->0){
		int N;
		cin>>N;
		set<int> tree;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			tree.insert(arr[i]);
		}
		map<int,int> rank;
		int r = 1;
		for(int a:tree){
			if(rank.find(a)==rank.end())
				rank[a] =r++;
		}
		for(int i=0;i<N;i++){
			arr[i]=rank[arr[i]];
			add(arr[i],1);
		}
		ll out=0;
		for(int i=0;i<N;i++){
			out+=sum(arr[i]-1);
			add(arr[i],-1);
		}
		cout<<out<<endl;
	}
	return 0;
}
