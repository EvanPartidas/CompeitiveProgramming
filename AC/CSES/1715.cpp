#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
const int MAXN = 1e6+5;

ll prefix[MAXN];
ll inv[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	prefix[1]=1;
	inv[0]=1;
	inv[1]=1;
	for(int i=2;i<MAXN;i++)inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=2;i<MAXN;i++){
		prefix[i] = prefix[i-1]*i;
		prefix[i]%=MOD;
		inv[i]*=inv[i-1];
		inv[i]%=MOD;
	}
	string str;
	cin>>str;
	int arr[26];
	for(int i=0;i<26;i++)
		arr[i]=0;
	for(int i=0;i<str.length();i++)
		arr[str[i]-'a']++;
	ll ret = prefix[(int)str.length()];
	for(int i=0;i<26;i++){
		ret*=inv[arr[i]];
		ret%=MOD;
	}
	cout<<ret<<endl;	
	return 0;
}
