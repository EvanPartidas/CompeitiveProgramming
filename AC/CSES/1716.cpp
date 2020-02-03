#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAX = 2e6+5;

ll prefix[MAX];
ll inv[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	prefix[1]=1;
	prefix[0]=1;
	inv[1]=1;
	inv[0]=1;
	for(int i=2;i<MAX;i++)inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=2;i<MAX;i++){
		prefix[i] = prefix[i-1]*i;
		prefix[i]%=MOD;
		inv[i]*=inv[i-1];
		inv[i]%=MOD;
	}	
	ll a,b;
	cin>>a>>b;
	ll t = a+b-1;
	ll ret = prefix[t]*inv[b]%MOD*inv[t-b]%MOD;
	cout<<ret;
	return 0;
}
