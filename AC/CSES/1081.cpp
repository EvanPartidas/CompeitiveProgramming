#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
typedef unsigned long long ll;
 
const int MAXX= 1e6+5;
const int MAXN = 2e5+5;
 
int SPF[MAXX];
bool seen[MAXX];
set<int,greater<int>> factors;
vector<int> toins;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int j=2;j<=MAXX;j++){
		if(SPF[j])
			continue;
		for (int i = j*2; i <=MAXX; i += j){
			SPF[i] = j;
		}
		SPF[j]=j;
	}
	int N;
	cin>>N;
	int gcd=1;
	while(N-->0){
		int X;
		cin>>X;
		if(X<gcd)
			continue;
		if(seen[X]){
			gcd = max(gcd,X);
			continue;
		}
		factors.clear();
		factors.insert(1);
		while(X>1){
			toins.clear();
			for(auto it = factors.begin();it!=factors.end();it++)
				toins.push_back(SPF[X]*(*it));
			factors.insert(toins.begin(),toins.end());
			X/=SPF[X];
		}
		for(int i:factors){
			if(i<=gcd) break;
			if(seen[i]){
				gcd = max(gcd,i);
				break;
			}
			seen[i]=1;
		}
		seen[X]=1;
	}
	cout<<gcd<<endl;
	return 0;
}
