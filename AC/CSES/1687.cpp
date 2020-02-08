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

void fillAnc(int n,int p){
	for(int j=1;j<LOG&&anc[n][j-1]>0;j++)
		anc[n][j]=anc[anc[n][j-1]][j-1];
	for(auto dest:graph[n]){
		if(dest==p) continue;
		anc[dest][0]=n;
		fillAnc(dest,n);
	}
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
	
	fillAnc(1,1);
	while(q-->0){
		int x,k;
		cin>>x>>k;
		for(int L = 1<<LOG,i=LOG;L;L>>=1,i--){
			if(k&L){
				x = anc[x][i];
				if(x<0)
					break;
				k&=~L;//Remove the bit (I could have just subtracted L)
			}
		}
		cout<<x<<endl;
	}
	return 0;
}
