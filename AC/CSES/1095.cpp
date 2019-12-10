#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD= 1e9+7;

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
	ll a=0;
	ll b=0;
	cin>>N;
	while(N-->0){
		cin>>a>>b;
		cout<<modPow(a,b,MOD)<<endl;
	}
	return 0;
}

