#include <iostream>

using namespace std;

const int MOD = 1e9+7;

typedef long long ll;

ll modPow(ll x, ll p, ll m){
	if(p==0)
		return 1;
	if(p==1)
		return x;
	ll ret = modPow(x,p/2,m);
	ret = (ret*ret)%m;
	if(p%2==1)
		ret*=x;
	return ret%m;
}

int main(){
	int N;
	cin>>N;
	while(N-->0){
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<(modPow(a,modPow(b,c,MOD-1),MOD))<<endl;
	}
	return 0;
}
