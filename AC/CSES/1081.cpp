#include <iostream>
#include <map>
#include <math.h>
using namespace std;
typedef unsigned long long ll;

const int MAXX= 1e6+5;
const int MAXN = 2e5+5;

int SPF[MAXX];
int ticks[MAXX];
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
	int gcd=1;
	while(N-->0){// O(N)
		int X;
		cin>>X;
		while(X>1){//O(log X)
			ticks[SPF[X]]++;
			if(ticks[SPF[X]]>1)
				gcd = max(gcd,SPF[X]);
			X/=SPF[X];
		}
	}
	cout<<gcd<<endl;
	return 0;
}
