#include <iostream>
#include <set>
using namespace std;
const int MAXN = 1e6+5;
typedef long long ll;
const ll MOD = 998244353;
ll toys[MAXN];
ll cnt[MAXN];
set<int> nums;
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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll N;
	cin>>N;
	ll bruh=0;
	for(int kid=0;kid<N;kid++){
		ll k;
		cin>>k;
		ll add = invMod(N*k,MOD);
		for(int i=0;i<k;i++){
			int t;
			cin>>t;
			toys[t]+=add;
			toys[t]%=MOD;
			cnt[t]++;
			nums.insert(t);
		}
	}
	for(int t:nums){
		bruh+=toys[t]*cnt[t]%MOD*invMod(N,MOD);
		bruh%=MOD;
	}
	cout<<bruh;
	return 0;
}
