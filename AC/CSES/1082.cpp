#include <iostream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long ll;

const ll MOD = 1e9 + 7;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N;
	cin >> N;
	ll cumsum = 0;
	ll sq = sqrt(N);
	sq = sq * (sq + 1) / 2;
	sq%=MOD;
	for (ll i = 1; i * i <= N; i++)
	{
		cumsum += (i * (N / i))%MOD;
		cumsum %= MOD;
		ll x = N / i;
		cumsum += ((x%MOD)*((x + 1)%MOD) / 2 - sq)%MOD;
		cumsum %= MOD;
	}
	cumsum %= MOD;
	cout << cumsum << endl;
	return 0;
}
