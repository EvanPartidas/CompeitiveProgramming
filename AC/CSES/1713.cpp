#include <iostream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long ll;

const int MAXX= 1e6+5;

int SPF[MAXX];
bool v[MAXX];


int main(){
	for(int i=2;i<MAXX;i+=2) SPF[i]=2;
	for (ll i = 3; i < MAXX; i += 2){
		if (!v[i]){
			SPF[i] = i;
			for (ll j = i; (j*i) < MAXX; j += 2){
				if (!v[j*i]){
					v[j*i] = true, SPF[j*i] = i;
				}
			}
		}
	}
	int N;
	cin>>N;
	while(N-->0){
		int X;
		cin>>X;
		map<int,int> tree;
		while(X>1){
			auto it = tree.find(SPF[X]);
			if(it==tree.end())
				tree[SPF[X]] = 2;
			else
				(*it).second++;
			X/=SPF[X];
		}
		ll num = 1;
		for(auto it=tree.begin();it!=tree.end();it++){
			num *= (*it).second;
		}
		cout<<num<<endl;
	}
	return 0;
}
