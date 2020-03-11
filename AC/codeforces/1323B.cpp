#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll N,M,K;
	cin>>N>>M>>K;
	const int MAX = 4e4+5;
	ll arr1[MAX],arr2[MAX];
	for(int i=0;i<MAX;i++)
		arr1[i]=arr2[i]=0;
	int a=0,b=0;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		a++;
		if(!tmp)	a=0;
		arr1[a]++;
	}
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		b++;
		if(!tmp)	b=0;
		arr2[b]++;
	}
	for(int i=MAX-2;i>=0;i--){
		arr1[i]+=arr1[i+1];
		arr2[i]+=arr2[i+1];
	}
	ll ans=0;
	for(ll i=1;i<=(long long)sqrt(K);i++){
		if(0==K%i&&(K/i<MAX)){
			ll add = arr1[i]*arr2[K/i];
			if(add>0)
				ans+=add;
			if(i*i==K)
				break;
			add = arr2[i]*arr1[K/i];
			if(add>0)
				ans+=add;
		}
	}
	cout<<ans<<endl;
	return 0;
}
