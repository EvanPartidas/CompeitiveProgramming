#include <iostream>

using namespace std;

typedef long long ll;

ll modInverse(ll a, ll m) 
{
    ll y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    return abs(x);
}

int main(){

	ll n,m;
	puts("Gimme dat number tho... and that mod");
	cin>>n>>m;
	printf("Modular inverse: %d\n",modInverse(n,m));
	return 0;
}
