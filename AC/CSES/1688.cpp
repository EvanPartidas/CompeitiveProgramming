#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
 
using namespace std;
typedef long long ll;
 
const int MAXN = 2e5+5;
const int LOG = 1+log(MAXN)/log(2);
 
int anc[MAXN][LOG];
 
vector<int> graph[MAXN];
int lev[MAXN];
 
void fillAnc(int n,int p){
	for(int j=1;j<LOG&&anc[n][j-1]>0;j++)
		anc[n][j]=anc[anc[n][j-1]][j-1];
	for(auto dest:graph[n]){
		if(dest==p) continue;
		anc[dest][0]=n;
		lev[dest]=lev[n]+1;
		fillAnc(dest,n);
	}
}

int getKth(int x,int k){
	for(int L = 1<<LOG,i=LOG;L;L>>=1,i--){
		if(k&L){
			x = anc[x][i];
			if(x<0)
				break;
			k&=~L;//Remove the bit (I could have just subtracted L)
		}
	}
	return x;
}

int lca(int a,int b){
	
	if(lev[a]<lev[b])
		swap(a,b);
		
	int k = lev[a]-lev[b];
	a = getKth(a,k);
	if(a==b)
		return a;
	//Find largest parent they don't share
	for(int i=LOG-1;i>=0;i--){
		if(anc[a][i]!=anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	
	
	return anc[a][0];
	
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		graph[a].push_back(i);
	}
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<LOG;j++)
			anc[i][j]=-1;
	lev[1]=1;
	fillAnc(1,1);
	while(q-->0){
		int x,k;
		cin>>x>>k;
		cout<<lca(x,k)<<endl;
	}
	return 0;
}
