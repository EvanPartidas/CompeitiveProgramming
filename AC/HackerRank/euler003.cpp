#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

bool isPrime(ll num){
	for(ll i=2;i<=sqrt(num);i++){
		if(num%i==0)
			return false;
	}
	return true;
}

int main(){
	int T;
	cin>>T;
	while(T-->0){
		ll N;
		cin>>N;
		ll m =0;
		for(ll i=1;i<=sqrt(N);i++){
			if((N%i==0)){
				if(isPrime(i))
					m=max(m,i);
				if(isPrime(N/i))
					m=max(m,N/i);
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
