#include <iostream>
#include <fstream>
#include <math.h>
 
using namespace std;
typedef unsigned long long ll;

const ll MOD = 1e9+7;

ll base[2][2] = {{1,1},{1,0}};

void mult(ll m1[2][2],ll m2[2][2]){
	ll a = (m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])%MOD;
	ll b = (m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1])%MOD;
	ll c = (m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0])%MOD;
	ll d = (m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1])%MOD;
	m1[0][0]=a;
	m1[0][1]=b;
	m1[1][0]=c;
	m1[1][1]=d;
}

ll power(ll N,ll mtx[2][2]){
	if(N<=1)
		return 1;
	power(N/2,mtx);
	mult(mtx,mtx);
	if(N%2)
		mult(mtx,base);
	return mtx[0][0];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll m[2][2] = {{1,1},{1,0}};
	ll N;
	cin>>N;
	if(N==0)
		cout<<0<<endl;
	else
		cout<<power(N-1,m);
	return 0;
}
