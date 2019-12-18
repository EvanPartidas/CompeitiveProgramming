#include <iostream>

using namespace std;

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
	int x;
	cin>>x;
	cout<<modPow(2,(ll)x,(ll)(1e9+7));
	return 0;
}
