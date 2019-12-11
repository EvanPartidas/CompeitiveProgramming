#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e5+5;

int endtimes[MAXN],vals[MAXN];
map<int,vector<int>> tree;
map<int,ll> dp;

int N;

ll help(int start){
	if(dp.find(start)!=dp.end())
		return dp[start];
	ll ret = 0;
	auto it = tree.upper_bound(start);
	if(it!=tree.end())
		ret = max(ret,help((*it).first));
	for(int ind:tree[start]){
		it = tree.upper_bound(endtimes[ind]);
		if(it!=tree.end())
			ret = max(ret,vals[ind]+help((*it).first));
		else
			ret = max(ret,(ll)vals[ind]);	
	}
	return dp[start]=ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	int a,b,c;
	for(int i=0;i<N;i++){
		cin>>a>>b>>c;
		tree[a].push_back(i);
		endtimes[i]=b;
		vals[i]=c;
	}
	cout<<help(0);
	return 0;
}
