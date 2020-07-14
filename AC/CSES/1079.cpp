#include <iostream>
#include <map>
#include <math.h>
#include <set>
using namespace std;
typedef unsigned long long ll;

const ll MOD = 1e9 + 7;
const int MAX = 1e6+5;

ll prefix[MAX];
ll inv[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	prefix[0]=1;
	inv[0]=1;
	prefix[1]=1;
	inv[1]=1;
	for(int i=2;i<MAX;i++)inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=2;i<MAX;i++){
		prefix[i] = prefix[i-1]*i;
		prefix[i]%=MOD;
		inv[i]*=inv[i-1];
		inv[i]%=MOD;
	}
	int N;
	cin>>N;
	while(N-->0){
		int a,b;
		cin>>a>>b;
		cout<<((prefix[a]*inv[b]%MOD*inv[a-b])%MOD)<<endl;
	}
	
	return 0;
}
