#include <iostream>

using namespace std;

typedef long long ll;

ll invMod(ll x, ll M) 
{
	ll inv = 1;
	ll y = 0;
	ll tmp;
	ll m=M;
	while(x>1){
		tmp =inv;
		inv = y - inv*(m/x);
		y = tmp;
		tmp = x;
		x = m%x;
		m = tmp;
	}
	return (inv+M)%M;
}

ll gcd(ll a,ll b){
	if(a==0||b==0)
		return max(a,b);
	return gcd(max(a,b)%min(a,b),min(a,b));
}

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
	ll a,b;
	a = 17;
	b = 43;
	
	printf("Inverse of %lld mod %lld = %lld\n",a,b,invMod(a,b));
	printf("GCD of %lld and %lld = %lld\n",a,b,gcd(a,b));
	a = 168;
	b = 2796;
	printf("GCD of %lld and %lld = %lld\n",a,b,gcd(a,b));
	printf("%lld to the power of %lld mod %lld = %lld\n",a,b,(ll)1e9,modPow(a,b,(ll)1e9));
	return 0;
}
