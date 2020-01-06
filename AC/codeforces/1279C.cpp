#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 10e5+5;
int pls[MAXN],ols[MAXN],omap[MAXN];
bitset<MAXN> used;
set<int> tree;

int M,N;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		cin>>N>>M;
		used.reset();
		tree.clear();
		int i;
		for(i=0;i<N;i++){
			cin>>pls[i];
		}
		for(i=0;i<M;i++){
			cin>>ols[i];
			omap[ols[i]]=i;
			used.set(ols[i]);
		}
		int penalty=0;
		ll time=0;
		int next = 0;
		for(i=0;i<N&&next<M;i++){
			if(used[pls[i]]){
				if(next==omap[pls[i]]){
					time+=(penalty+tree.size())*2+1;
					next++;
				}
				else
					tree.insert(omap[pls[i]]);
				while((*(tree.begin()))==next){
					tree.erase(next);
					time++;
					next++;
				}
			}
			else
				penalty++;
		}
		cout<<time<<endl;
	}
	return 0;
}
